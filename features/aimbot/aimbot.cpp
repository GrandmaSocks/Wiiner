#include "../features.hpp"

// int aim_bone[] = { 8, 7 , 6 }; /* Useless */

#define HITBOX_HEAD 8 /* I think I wanna do this for bone selection now */
#define HITBOX_NECK 7
#define HITBOX_CHEST 6
#define HITBOX_PELVIS 5
#define HITBOX_FOOT 4

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

	if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
		return;
	
	const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;

	if (weapon_type == WEAPONTYPE_PISTOL)
	{
		if (variables::aimbots::legit::pistols::aimbotToggle == true)
		{
			variables::aimbots::rage::ragebot == false;

			if (variables::aimbots::legit::pistols::randombones == true)
			{
				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

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

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::pistols::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::pistols::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}

			if (variables::aimbots::legit::pistols::randombones == false)
			{

				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

				if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
					return; /* Don't aimbot with grenade, c4, or knife */

				player_t* entity = nullptr;
				int bone = 6;
				entity = closest_to_crosshair(user_cmd);

				if (variables::aimbots::legit::pistols::afeet == true)
				{
					if (bone == HITBOX_FOOT);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::pistols::apelvis == true)
				{
					if (bone == HITBOX_PELVIS);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::pistols::achest == true)
				{
					if (bone == HITBOX_CHEST);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::pistols::aneck == true)
				{
					if (bone == HITBOX_NECK);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::pistols::ahead == true)
				{
					if (bone == HITBOX_HEAD);

					else
					{
						bone = 7;
					}
				}

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::pistols::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::pistols::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////


	if (weapon_type == WEAPONTYPE_SUBMACHINEGUN)
	{
		if (variables::aimbots::legit::smgs::aimbotToggle == true)
		{
			variables::aimbots::rage::ragebot == false;

			if (variables::aimbots::legit::smgs::randombones == true)
			{
				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

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

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::smgs::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::smgs::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}

			if (variables::aimbots::legit::smgs::randombones == false)
			{

				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */
				
				if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
					return; /* Don't aimbot with grenade, c4, or knife */

				player_t* entity = nullptr;
				int bone = 6;
				entity = closest_to_crosshair(user_cmd);

				if (variables::aimbots::legit::smgs::afeet == true)
				{
					if (bone == HITBOX_FOOT);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::smgs::apelvis == true)
				{
					if (bone == HITBOX_PELVIS);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::smgs::achest == true)
				{
					if (bone == HITBOX_CHEST);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::smgs::aneck == true)
				{
					if (bone == HITBOX_NECK);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::smgs::ahead == true)
				{
					if (bone == HITBOX_HEAD);

					else
					{
						bone = 7;
					}
				}

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::smgs::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::smgs::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////

	if (weapon_type == WEAPONTYPE_RIFLE)
	{
		if (variables::aimbots::legit::rifles::aimbotToggle == true)
		{
			variables::aimbots::rage::ragebot == false;

			if (variables::aimbots::legit::rifles::randombones == true)
			{
				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

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

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::rifles::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::rifles::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}

			if (variables::aimbots::legit::rifles::randombones == false)
			{

				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

				if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
					return; /* Don't aimbot with grenade, c4, or knife */

				player_t* entity = nullptr;
				int bone = 6;
				entity = closest_to_crosshair(user_cmd);

				if (variables::aimbots::legit::rifles::afeet == true)
				{
					if (bone == HITBOX_FOOT);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::rifles::apelvis == true)
				{
					if (bone == HITBOX_PELVIS);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::rifles::achest == true)
				{
					if (bone == HITBOX_CHEST);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::rifles::aneck == true)
				{
					if (bone == HITBOX_NECK);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::rifles::ahead == true)
				{
					if (bone == HITBOX_HEAD);

					else
					{
						bone = 7;
					}
				}

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::rifles::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::rifles::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////

	if (weapon_type == WEAPONTYPE_SNIPER_RIFLE)
	{
		if (variables::aimbots::legit::snipers::aimbotToggle == true)
		{
			variables::aimbots::rage::ragebot == false;

			if (variables::aimbots::legit::snipers::randombones == true)
			{
				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */
				
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

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::snipers::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::snipers::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}

			if (variables::aimbots::legit::snipers::randombones == false)
			{

				if (!csgo::local_player->is_alive()) /* No reason to run aimbot if you are dead */
					return;

				srand(time(0)); /* psudeo random number generator */
				int random = rand() % 5 + 1;  /* Only randomize from 1-5 */

				if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
					return; /* Don't aimbot with grenade, c4, or knife */

				player_t* entity = nullptr;
				int bone = 6;
				entity = closest_to_crosshair(user_cmd);

				if (variables::aimbots::legit::snipers::afeet == true)
				{
					if (bone == HITBOX_FOOT);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::snipers::apelvis == true)
				{
					if (bone == HITBOX_PELVIS);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::snipers::achest == true)
				{
					if (bone == HITBOX_CHEST);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::snipers::aneck == true)
				{
					if (bone == HITBOX_NECK);

					else
					{
						bone = 7;
					}
				}

				if (variables::aimbots::legit::snipers::ahead == true)
				{
					if (bone == HITBOX_HEAD);

					else
					{
						bone = 7;
					}
				}

				auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

				angle.clamp();

				angle /= (variables::aimbots::legit::snipers::smoothing * 4);

				angle = math::normalize(angle);

				user_cmd->viewangles += angle;

				if (variables::aimbots::legit::snipers::silentaim == false) /* If silent aim isn't enabled set viewangles */
				{
					interfaces::engine->set_view_angles(user_cmd->viewangles);
				}
				else {
					/* Not happy about this but this seems to prevent a bug */
				}
			}
		}
	}
}