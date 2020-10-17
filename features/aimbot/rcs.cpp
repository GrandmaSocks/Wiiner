#include "../features.hpp"

void rcs(c_usercmd* cmd)
{
	if (variables::aimbots::legit::rcs == true)
	{
		vec3_t punchAngle = csgo::local_player->aim_punch_angle() * 2;

		csgo::local_player->aim_punch_angle() * 2;		

		vec3_t oPunch{ 0,0,0 };
		if (cmd->buttons & in_attack)
		{
			cmd->viewangles += (oPunch - punchAngle);
			oPunch = punchAngle;
			cmd->viewangles.normalize();
		}
	}

	else {}
}