#pragma once
#include "../../dependencies/utilities/csgo.hpp"
#include "../variables.hpp"

char* HitgroupToName(int hitgroup)
{
	switch (hitgroup)
	{
	case hitgroup_head:
		return "head";
	case hitgroup_leftleg:
		return "left leg";
	case hitgroup_rightleg:
		return "right leg";
	case hitgroup_stomach:
		return "stomach";
	default:
		return "body";
	}
}

namespace misc {
	namespace movement {
		void bunny_hop(c_usercmd* cmd);
	};
}

class WRAGEBOT
{
public:
	static void ragebot(c_usercmd* cmd);
	static void antiaim(c_usercmd* cmd);
	static void autowall(c_usercmd* cmd);
	static void safepoint(c_usercmd* cmd);
	static void hitchance(c_usercmd* cmd);
	static void mindmg(c_usercmd* cmd);
	static void fixpvs();
};

void hitlogs(i_game_event* event);

void antiflash();

void rcs(c_usercmd* cmd);

void esp();

void boneesp();

void aimbot(c_usercmd* cmd);

void bombesp();

void chams(i_mat_render_context* ctx, const draw_model_state_t& state, const model_render_info_t& info, matrix_t* matrix);

void thirdperson();

void bombesp();

void clantag();

void crosshair();

void antiaim(c_usercmd* cmd);

void Fov();

void log(c_usercmd* cmd);

void ragebot(c_usercmd* user_cmd);

void watermark();

void triggerbot(c_usercmd* cmd);

void knifehandFlip();

void spreadxhair();

namespace cfg
{
	void run(const char* name);

	void load(size_t id);

	void save(size_t id);

	bool add(const char* name);

	void remove(size_t id);

	void rename(size_t item, const char* newName);

	void reset();
	
}