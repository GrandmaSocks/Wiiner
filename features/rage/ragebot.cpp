#include "../features.hpp"

/*

TO-DO
--------------------------------
* Make it so if your viewangles are down you aren't acutally looking down

* Create Ragebot and Resolver
	- Autowall
	- Hitchance and Min Damage
	- Auto shoot

* Add fakelag

* Idea for antiaim (switch)
	- have LBY shift around from two values


*/

void log() /* Log debug info */
{
	/*	if (interfaces::engine->is_in_game() == true)
		{
			float loghitchance = 1 / csgo::local_player->active_weapon()->get_weapon_data()->weapon_inaccuracy_stand;
			std::string hitchancelogp = std::to_string(loghitchance);
			render::text(370, 25, render::fonts::menufont, hitchancelogp, false, color(255, 255, 255));
		}*/
}

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

void ragebot(c_usercmd* user_cmd) /* Rage aimbot needs much improvment, list of things to do is down below */
{
	if (variables::aimbots::rage::ragebot == true)
	{
		variables::aimbots::legit::aimbotToggle == false; /* If ragebot is on disable legitbot or else it messed everything up */

		srand(time(0));
		int random = rand() % 5 + 1; /* Should just call the already made random function  */

		if (!csgo::local_player->is_alive())
			return;

		const auto weapon_type = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type;
		const auto weapon = csgo::local_player->active_weapon()->get_weapon_data()->weapon_type_name; /* Dosen't Work */
		if (weapon_type == WEAPONTYPE_GRENADE || weapon_type == WEAPONTYPE_C4 || weapon_type == WEAPONTYPE_KNIFE)
			return;

		player_t* entity = nullptr;
		int bone = 0;

		if (variables::aimbots::rage::ctarget == true) /* Get Target | Configible */
		{
			entity = rage_closest_to_crosshair(user_cmd);
		}

		if (variables::aimbots::rage::chealth == true) /* Get Target | Configible */
		{
			entity = rage_lowest_health(user_cmd);
		}

		if (variables::aimbots::rage::cdistance == true) /* Get Target | Configible */
		{
			entity = rage_closest_distance(user_cmd);
		}


		if (!entity)  
			return;

		bone = 7; /* Inital bone is head but gets changed by some statments later */

		if (entity->health() < 50) /* If targets health is below 50 baim them*/
		{
			bone = 5;
		}

		if (weapon_type == WEAPON_AWP) /* Dosen't work but useful, if you have awp baim target */
		{
			bone = 6;
		}

		if (weapon_type == WEAPONTYPE_RIFLE || weapon_type == WEAPONTYPE_SUBMACHINEGUN) /* If you got a high spread weapon just baim */
		{
			if (csgo::local_player->active_weapon()->clip1_count() < 15)
			{
				bone = 4;
			}
			bone = 6;
		}

		auto angle = math::calculate_angle(csgo::local_player->get_eye_pos(), entity->get_bone_position(bone), user_cmd->viewangles);

		angle.clamp();

		angle = math::normalize(angle);

		user_cmd->viewangles += angle;

		float hitchance = 1 / csgo::local_player->active_weapon()->get_weapon_data()->weapon_inaccuracy_stand;

		float flServerTime = csgo::local_player->get_tick_base() * interfaces::globals->interval_per_tick;

		bool canShoot = (csgo::local_player->active_weapon()->next_primary_attack() <= flServerTime && csgo::local_player->active_weapon()->clip1_count() > 0);

		std::string hitchancelog = std::to_string(hitchance);

		/* Add hitchance, add multipoint, add safepoint, add min dmg, add hitgroups { Copy the ones from the legit bot when thats done} */

	}
}

void antiaim(c_usercmd* cmd) /* Antiaim(s) still working on it. Need a fix so you don't look at the floor (: */
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
			interfaces::engine->set_view_angles(cmd->viewangles);
		}

		if (variables::antiaim::pUp == true) /* Up pitch */
		{
			variables::antiaim::pDown = false;

			cmd->viewangles.x = -89.f;
			cmd->viewangles.clamp();
			interfaces::engine->set_view_angles(cmd->viewangles);
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

bool autowall(player_t* entity) /* Shoot valid targets through walls */
{
	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	trace_filter filter;
	ray_t ray;
	trace_t trace;
	vec3_t start, end;
	filter.skip = local_player;
	start = local_player->origin() + local_player->view_offset();
	end = entity->get_eye_pos();
	ray.initialize(start, end);

	// cast ray
	interfaces::trace_ray->trace_ray(ray, MASK_SOLID, &filter, &trace);

	if (trace.entity == entity || trace.flFraction > .97f)
	{

	}
	else {

		// auto wall starts here

		extern int bone;

		float dmg = csgo::local_player->active_weapon()->get_weapon_data()->weapon_damage;
		float pen = csgo::local_player->active_weapon()->get_weapon_data()->weapon_penetration;

		std::string dmglog = std::to_string(dmg);
		// 	std::string bonelog = std::to_string(bone);
		std::string penlog = std::to_string(pen);

		render::draw_text_string(1000, 450, render::fonts::menufont, dmglog, false, color(255, 255, 0));
		render::draw_text_string(1000, 500, render::fonts::menufont, penlog, false, color(255, 255, 0));

		if (entity->health() > 0 && entity->armor() < 0)
		{
			if (trace.did_hit() && !trace.startSolid)
			{

			}
		}

		if (entity->health() > 0 && entity->armor() > 0)
		{
			if (!trace.did_hit() && !trace.startSolid)
			{

			}
		}
	}

	/*
		1. initial damage of bullet (+ other properties)

		2. what walls the bullet goes thru (how much damage do those take off)

		3. the distance the bullet will be traveling (damage fall off at distance)

		4. the hitbox you'll be shooting at  (hitbox damage multiplier)

		FINISHED  5. is the guy wearing armor
	*/
	return true;
}

void hvhmode(c_usercmd* cmd, player_t* entity) /* I think this is useless with the menu update but haven't deleted it */
{
	if (variables::misc::hvhmode == true)
	{
		variables::aimbots::legit::aimbotToggle = false;
		ragebot(cmd);
		//movementFix(cmd, oAngle, oldForward, oldSide);
		//autowall(entity);
	}
}