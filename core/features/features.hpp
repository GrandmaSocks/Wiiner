#pragma once
#include "../../dependencies/utilities/csgo.hpp"
#include "../variables.hpp"

namespace misc {
	namespace movement {
		void bunny_hop(c_usercmd* cmd);
	};
}

void antiflash();

void rcs(c_usercmd* cmd);

void esp();

void boneesp();

void aimbot(c_usercmd* cmd);

void hvhmode(c_usercmd* cmd);

void bombesp();

void chams(i_mat_render_context* ctx, const draw_model_state_t& state, const model_render_info_t& info, matrix_t* matrix);

void thirdperson();

void bombesp();

void clantag();

void crosshair();

void antiaim(c_usercmd* cmd);