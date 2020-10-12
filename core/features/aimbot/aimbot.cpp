#include "../features.hpp"

// int aim_bone[] = { 8, 7 , 6 }; /* Useless */

#define HITBOX_HEAD 7 /* I think I wanna do this for bone selection now */
#define HITBOX_NECK 6
#define HITBOX_CHEST 5
#define HITBOX_PELVIS 4
#define HITBOX_FEET 3

void smooth(vec3_t& ViewAngle, vec3_t& Angle, float SmoothValue) /* Useless? */
{
	// Angle = (ViewAngle + Angle - ViewAngle.clamp() / SmoothValue).clamp();
}

player_t* closest_to_crosshair(c_usercmd* user_cmd) /* Target closest to crosshair */
{
	player_t* best_entity = nullptr;
	float delta;
	float best_delta = FLT_MAX;

	for (int i = 1; i <= interfaces::globals->max_clients; i++)
	{
		auto view_angles = user_cmd->viewangles;
		auto entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(i));

		if (!entity || entity == csgo::local_player)
			continue;

		if (entity->has_gun_game_immunity() || entity->dormant() || !entity->is_alive() || !entity->is_player() || entity->health() <= 0)
			continue;

		if (entity->team() == csgo::local_player->team())
			continue;

		if (!entity->is_visible(entity))
			continue;

		if (csgo::local_player->is_flashed() == true)
			continue;
		
		delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		if (delta < best_delta && delta < 6)
		{
			best_entity = entity;
			best_delta = delta;
		}
	}
	return best_entity;
}

player_t* closest_distance(c_usercmd* user_cmd) /* Target closest to localplayer */
{
	player_t* best_entity = nullptr;
	float distance;
	float best_distance = FLT_MAX;

	for (int i = 1; i <= interfaces::globals->max_clients; i++)
	{
		auto view_angles = user_cmd->viewangles;
		auto entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(i));

		if (!entity || entity == csgo::local_player)
			continue;

		if (entity->has_gun_game_immunity() || entity->dormant() || !entity->is_alive() || !entity->is_player() || entity->health() <= 0)
			continue;

		if (entity->team() == csgo::local_player->team())
			continue;

		if (!entity->is_visible(entity))
			continue;

		if (csgo::local_player->is_flashed() == true)
			continue;

		auto delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		distance = entity->abs_origin().distance_to(csgo::local_player->abs_origin());
		if (distance < best_distance && delta < 4.5)
		{
			best_entity = entity;
		}
	}
	return best_entity;
}

player_t* lowest_health(c_usercmd* user_cmd) /* Target with lowest health */
{
	player_t* best_entity = nullptr;
	int health;
	int best_health = 1000.f;

	for (int i = 1; i <= interfaces::globals->max_clients; i++)
	{
		auto view_angles = user_cmd->viewangles;
		auto entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(i));

		if (!entity || entity == csgo::local_player)
			continue;

		if (entity->has_gun_game_immunity() || entity->dormant() || !entity->is_alive() || !entity->is_player() || entity->health() <= 0)
			continue;

		if (!entity->is_visible(entity))
			continue;

		if (csgo::local_player->is_flashed() == true)
			continue;

		if (entity->team() == csgo::local_player->team())
			continue;

		auto delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		health = entity->health();
		if (health < best_health && delta < 6)
		{
			best_entity = entity;
			best_health = health;
		}
	}
	return best_entity;
}

void aimbot(c_usercmd* user_cmd) /* Where legit aimbot runs */
{
	if (variables::aimbotToggle == true) /* If enabled actually do stuff */
	{
		if (variables::randombones == true) /* Mode where bone selection randomizes, looks more legit and easy to code */
		{

			if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
				return;

			srand(time(0)); /* psudeo random number generator */
			int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

			const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;
			if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
				return; /* Don't aimbot with grenade, c4, or knife */

			player_t* entity = nullptr;
			int bone = 0;
			entity = closest_to_crosshair(user_cmd); /* I should make it so you can pick diffrent modes  */

			if (!entity)
				return;

			if (random == 1)
			{
				bone = 7;
			}
			if (random == 2 || random == 3) /* Bone selection */
			{
				bone = 8;
			}
			if (random == 4 || random == 5)
			{
				bone = 6;
			}

			if (weapon_type == WEAPONTYPE_RIFLE || weapon_type == WEAPONTYPE_SUBMACHINEGUN) /* High spread weapons aim lower to compensate for high spread/recoil */
			{

				/* If you wanted you can make a new random variable and have it be like 1-10 and if its 1-9 baim and if its 10 shoot head */

				if (random == 1 || random == 2 || random == 3)
				{
					bone = 4;
				}
				else {
					bone = 3;
				}
			}

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

			angle.clamp();

			angle /= (variables::smoothing * 4);

			angle = math::normalize(angle);

			user_cmd->viewangles += angle;


			if (variables::silentaim == false) /* If silent aim isn't enabled set viewangles */
			{
				interfaces::engine->set_view_angles(user_cmd->viewangles);
			}
			else {
				/* Not happy about this but this seems to prevent a bug */
			}

		}
		else /* Here is where I need to add the custom hitbox selection */
		{
			if (!csgo::local_player->is_alive())
				return;

			srand(time(0));
			int random = rand() % 5 + 1;

			const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;
			if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
				return;

			player_t* entity = nullptr;
			int bone = 0;
			entity = closest_to_crosshair(user_cmd);

			if (!entity)
				return;

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

			angle.clamp();

			angle /= (variables::smoothing * 4);

			angle = math::normalize(angle);

			user_cmd->viewangles += angle;


			if (variables::silentaim == false)
			{
				interfaces::engine->set_view_angles(user_cmd->viewangles);
			}
		}
	}
}