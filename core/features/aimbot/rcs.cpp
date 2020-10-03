#include "../features.hpp"

void rcs(c_usercmd* cmd)
{
	if (variables::rcs == true)
	{
		vec3_t punchAngle = csgo::local_player->aim_punch_angle() * 2;

		if (csgo::local_player->shots_fired() > 15)
		{
			punchAngle = csgo::local_player->aim_punch_angle() * 1.5;
		}
		else {
			csgo::local_player->aim_punch_angle() * 2;
		}

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