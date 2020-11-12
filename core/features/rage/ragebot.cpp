#include "../features.hpp"

int random(int min, int max) /* Little function to make a random number very useful should make it in a header */
{
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

player_t* rage_closest_to_crosshair(c_usercmd* user_cmd) /* Player closest to localplayers crosshair */
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

		delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		if (delta < best_delta && delta < 180)
		{
			best_entity = entity;
			best_delta = delta;
		}
	}
	return best_entity;
}

player_t* rage_closest_distance(c_usercmd* user_cmd) /* Target closest to localplayer */
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

		auto delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		distance = entity->abs_origin().distance_to(csgo::local_player->abs_origin());
		if (distance < best_distance && delta < 180)
		{
			best_entity = entity;
		}
	}
	return best_entity;
}

player_t* rage_lowest_health(c_usercmd* user_cmd) /* Target with lowest health */
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

		if (entity->team() == csgo::local_player->team())
			continue;

		if (!entity->is_visible(entity)) /* Once autowall is done call it here (: */
			continue;

		auto delta = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_eye_pos(), view_angles).length();
		health = entity->health();
		if (health < best_health && delta < 180)
		{
			best_entity = entity;
			best_health = health;
		}
	}
	return best_entity;
}

void WRAGEBOT::fixpvs()
{
	for (int players = 1; players <= interfaces::globals->max_clients; players++)
	{
		auto CSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(players));
		
		if (CSPlayer != csgo::local_player)
			return;
		
		if (csgo::local_player == nullptr)
			return;

		if (!csgo::local_player->is_alive())
			return;
		
		*(int*)((uintptr_t)CSPlayer + 0xA30) = interfaces::globals->frame_count;
		*(int*)((uintptr_t)CSPlayer + 0xA28) = 0;
	}
}

void WRAGEBOT::hitchance(c_usercmd* cmd)
{
	if (!csgo::local_player)
		return;

	if (csgo::local_player == nullptr)
		return;

	if (!csgo::local_player->is_alive())
		return;
	
	const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;
	const auto weapon = csgo::local_player->active_weapon()->get_weapon_data()->weapon_name;
	
	if (weapon_type == NULL)
		return;

	float inaccuracy = csgo::local_player->active_weapon()->get_spread();

	if (inaccuracy == 0)
	{
		inaccuracy == 0.0000001;
	}
	
	if (weapon_type == WEAPONTYPE_PISTOL)
	{
		variables::aimbots::rage::pistols::hitchance = inaccuracy;

		if (variables::aimbots::rage::pistols::hitchance >= variables::aimbots::rage::pistols::hitchance)
			variables::canshoot = true;
	}

	if (weapon == "weapon_revolver")
	{
		variables::aimbots::rage::h_pistols::hitchance = inaccuracy;

		if (variables::aimbots::rage::h_pistols::hitchance >= variables::aimbots::rage::h_pistols::hitchance)
			variables::canshoot = true;
	}

	if (weapon == "weapon_ssg08")
	{
		variables::aimbots::rage::scout::hitchance = inaccuracy;

		if (variables::aimbots::rage::scout::hitchance >= variables::aimbots::rage::scout::hitchance)
			variables::canshoot = true;
	}

	if (weapon_type == WEAPONTYPE_SNIPER_RIFLE)
	{
		variables::aimbots::rage::autos::hitchance = inaccuracy;

		if (variables::aimbots::rage::autos::hitchance >= variables::aimbots::rage::autos::hitchance)
			variables::canshoot = true;
	}

	if (weapon == "weapon_awp")
	{
		variables::aimbots::rage::awp::hitchance = inaccuracy;

		if (variables::aimbots::rage::awp::hitchance >= variables::aimbots::rage::awp::hitchance)
			variables::canshoot = true;
	}
	
}

void WRAGEBOT::autowall(c_usercmd* cmd)
{
	/* Handles bullet penetration and shooting through walls */
}

void WRAGEBOT::safepoint(c_usercmd* cmd)
{
	/* Shoots at overlaps between desync and real angles */
}

void WRAGEBOT::mindmg(c_usercmd* cmd)
{
	/* Determine damage of next shot so the ragebot dosen't shoot until that damage is reachable */
}

void WRAGEBOT::ragebot(c_usercmd* cmd)
{
	/* Handles shooting and target selection */

	hitchance(cmd);
	mindmg(cmd);
	safepoint(cmd);
	autowall(cmd);
	
	if (!csgo::local_player)
		return;

	if (csgo::local_player == nullptr)
		return;

	if (!csgo::local_player->is_alive())
		return;

	const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;
	const auto weapon = csgo::local_player->active_weapon()->get_weapon_data()->weapon_name;

	if (weapon_type == NULL)
		return;

	if (weapon_type == WEAPONTYPE_PISTOL)
	{
		if (variables::aimbots::rage::pistols::ragebot)
		{
			player_t* entity = nullptr;
			int bone = 0;
			entity = rage_lowest_health(cmd);

			if (!entity)
				return;
			
			///////////////////////
						
			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), cmd->viewangles);

			angle.clamp();

			angle /= (variables::aimbots::legit::pistols::smoothing * 4);

			angle = math::normalize(angle);

			cmd->viewangles += angle;
		}
	}

	if (weapon == "weapon_revolver")
	{
		if (variables::aimbots::rage::h_pistols::ragebot)
		{
			player_t* entity = nullptr;
			int bone = 0;
			entity = rage_lowest_health(cmd);

			if (!entity)
				return;

			///////////////////////

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), cmd->viewangles);

			angle.clamp();

			angle /= (variables::aimbots::legit::pistols::smoothing * 4);

			angle = math::normalize(angle);

			cmd->viewangles += angle;
		}
	}

	if (weapon == "weapon_ssg08")
	{
		if (variables::aimbots::rage::scout::ragebot)
		{
			player_t* entity = nullptr;
			int bone = 0;
			entity = rage_lowest_health(cmd);

			if (!entity)
				return;

			///////////////////////

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), cmd->viewangles);

			angle.clamp();

			angle /= (variables::aimbots::legit::pistols::smoothing * 4);

			angle = math::normalize(angle);

			cmd->viewangles += angle;
		}
	}

	if (weapon_type == WEAPONTYPE_SNIPER_RIFLE)
	{
		if (variables::aimbots::rage::autos::ragebot)
		{
			player_t* entity = nullptr;
			int bone = 0;
			entity = rage_lowest_health(cmd);

			if (!entity)
				return;

			///////////////////////

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), cmd->viewangles);

			angle.clamp();

			angle /= (variables::aimbots::legit::pistols::smoothing * 4);

			angle = math::normalize(angle);

			cmd->viewangles += angle;
		}
	}

	if (weapon == "weapon_awp")
	{
		if (variables::aimbots::rage::awp::ragebot)
		{
			player_t* entity = nullptr;
			int bone = 0;
			entity = rage_lowest_health(cmd);

			if (!entity)
				return;

			///////////////////////

			auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), cmd->viewangles);

			angle.clamp();

			angle /= (variables::aimbots::legit::pistols::smoothing * 4);

			angle = math::normalize(angle);

			cmd->viewangles += angle;
		}
	}
	
	/*
	 1. Create standard checks to prevent crashes *
	 2. Setup checks for weapon held *
	 3. Setup target selection and bone selection
	 4. Call our previous functions 
	 5. Setup shoot logic 
	 6. Profit
	 */
	
}

void WRAGEBOT::antiaim(c_usercmd* cmd) 
{

	if (variables::misc::airstuck == true) /* When I make keybind thing make this on key */
	{
		cmd->tick_count = INT_MAX; /* Stupid exploit */
		cmd->command_number = INT_MAX;
	}

	if (variables::antiaim::enabled == true)
	{
		if (!csgo::local_player) /* We can't change viewangles of others so how about we just change ourself ¯\_(ツ)_/¯ */
			return;

		if (cmd->buttons & in_attack ||  /* Run checks for when to not run antiaim aka times antiaim would be inconvienent */
			cmd->buttons & in_use ||
			csgo::local_player->move_type() == movetype_ladder ||
			csgo::local_player->move_type() == movetype_noclip)
			return;

		float yaw_base;
		vec3_t engine_angles;                                  /* Some useful variables */
		interfaces::engine->get_view_angles(engine_angles);
		yaw_base = engine_angles.y;

		if (variables::antiaim::pDown == true) /* Down pitch */
		{
			variables::antiaim::pUp == false;

			cmd->viewangles.x = 89.f;
			cmd->viewangles.clamp();

			if (variables::misc::thirdperson == true)
			{
				interfaces::engine->set_view_angles(cmd->viewangles);
			}
		}

		if (variables::antiaim::pUp == true) /* Up pitch */
		{
			variables::antiaim::pDown = false;

			cmd->viewangles.x = -89.f;
			cmd->viewangles.clamp();

			if (variables::misc::thirdperson == true)
			{
				interfaces::engine->set_view_angles(cmd->viewangles);
			}
		}

		if (variables::antiaim::yStatic == true) /* Static Yaw */
		{
			uintptr_t* frame_pointer;
			__asm mov frame_pointer, ebp;
			bool& send_packet = *reinterpret_cast<bool*>(*frame_pointer - 0x1C);
			if (!send_packet) {
				cmd->viewangles.y += 180.f;
			}
			else {
				cmd->viewangles.y += 180.f;
			}

			if (csgo::local_player->flags() & fl_onground && cmd->sidemove < 3 && cmd->sidemove > -3) {
				static bool switch_ = false;
				if (switch_)
					cmd->sidemove = 2;
				else
					cmd->sidemove = -2;
				switch_ = !switch_;
			}
		}
	}

}