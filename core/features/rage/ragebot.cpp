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

player_t* get_rage_target(c_usercmd* cmd)
{



	return 0;
}

void ragebot(c_usercmd* cmd)
{



}

/*
void movementFix(c_usercmd* cmd, vec3_t oldAngles, float oldForward, float oldSide)
{
	float deltaView;
	float f1;
	float f2;

	if (oldAngles.y < 0.f)
		f1 = 360.0f + oldAngles.y;
	else
		f1 = oldAngles.y;

	if (cmd->viewangles.y < 0.0f)
		f2 = 360.0f + cmd->viewangles.y;
	else
		f2 = cmd->viewangles.y;

	if (f2 < f1)
		deltaView = abs(f2 - f1);
	else
		deltaView = 360.0f - abs(f1 - f2);

	deltaView = 360.0f - deltaView;

	cmd->forwardmove = cos(DEG2RAD(deltaView)) * oldForward + cos(DEG2RAD(deltaView + 90.f)) * oldSide;
	cmd->sidemove = sin(DEG2RAD(deltaView)) * oldForward + sin(DEG2RAD(deltaView + 90.f)) * oldSide;
}*/

void hvhmode(c_usercmd* cmd)
{
	weapon_t weapon;

	if (cmd->buttons & in_attack ||
		cmd->buttons & in_use ||
		csgo::local_player->move_type() == movetype_ladder ||
		csgo::local_player->move_type() == movetype_noclip || csgo::local_player->is_moving() == true)
		return;

	float yaw;
	vec3_t engine_angles;
	interfaces::engine->get_view_angles(engine_angles);
	yaw = engine_angles.y;

	if (variables::hvhmode == true)
	{

		csgo::local_player->lower_body_yaw() = 179.0f;
		vec3_t angles = cmd->viewangles = vec3_t(89.f, yaw + 180.f, 0.f);
		interfaces::engine->set_view_angles(angles);
		angles.clamp();
		angles.normalize();

		ragebot(cmd);
		//movementFix(cmd, oAngle, oldForward, oldSide);

	}
	else {}
}