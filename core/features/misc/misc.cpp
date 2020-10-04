#include "../features.hpp"

void misc::movement::bunny_hop(c_usercmd* cmd) {

	if (variables::bhopToggle == true)
	{
		const int move_type = csgo::local_player->move_type();

		if (move_type == movetype_ladder || move_type == movetype_noclip || move_type == movetype_observer)
			return;

		if (!(csgo::local_player->flags() & fl_onground))
			cmd->buttons &= ~in_jump;
	}
	else {}
};

void antiflash()
{
	if (variables::antiflash == 1)
	{
		if (csgo::local_player->is_flashed() == true)
		{
			csgo::local_player->flash_duration() = 0;
		}
	}
	if (variables::antiflash == 2)
	{
		if (csgo::local_player->is_flashed() == true)
		{
			csgo::local_player->flash_alpha() = 0.3f;
		}
	}
}

void thirdperson()
{
	/*vec3_t oldAngles = interfaces::input->camera_offset;
	if (variables::thirdperson == true)
	{
		if (interfaces::input->camera_in_third_person = variables::thirdperson)
		{
			interfaces::input->camera_offset.z = 100;
			interfaces::input->camera_offset.x = 40;
			vec3_t newAngles = interfaces::input->camera_offset;
			interfaces::input->camera_offset.clamp();
			interfaces::input->camera_offset.normalize();
		}
		else
		{
			interfaces::input->camera_offset = oldAngles;
		}
	}
	*/

}

void set_clantag(std::string clantag)
{
	static auto clantag_original = (int(__fastcall*)(const char*, const char*))utilities::pattern_scan("engine.dll", "53 56 57 8B DA 8B F9 FF 15");
	clantag_original(clantag.c_str(), clantag.c_str());
}

void clantag()
{
	if (variables::clantag == 1)
	{
		static float last_change = 0.f;
		if (interfaces::globals->realtime - last_change >= 0.25f) {
			std::string clantag = "";
			switch (int(interfaces::globals->cur_time * 4.f) % 41) { //add latency for better sync
			case 0:  clantag = "               "; break;
			case 1:  clantag = "              W"; break;
			case 2:  clantag = "             Wi"; break;
			case 3:  clantag = "            Wii"; break;
			case 4:  clantag = "           Wiin"; break;
			case 5:  clantag = "          Wiine"; break;
			case 6:  clantag = "         Wiiner"; break;
			case 7:  clantag = "        Wiiner"; break;
			case 8:  clantag = "       Wiiner"; break;
			case 9:  clantag = "      Wiiner "; break;
			case 10:  clantag = "     Wiiner  "; break;
			case 11:  clantag = "    Wiiner   "; break;
			case 12:  clantag = "   Wiiner    "; break;
			case 13:  clantag = "  Wiiner     "; break;
			case 14:  clantag = " Wiiner      "; break;
			case 15:  clantag = "Wiiner       "; break;
			case 16:  clantag = "iiner        "; break;
			case 17:  clantag = "iner         "; break;
			case 18:  clantag = "ner          "; break;
			case 19:  clantag = "er           "; break;
			case 20:  clantag = "r            "; break;
			}
			set_clantag(clantag);
			last_change = interfaces::globals->realtime;
		}
	}

	if (variables::clantag == 2)
	{
		set_clantag("Wiiner");
	}

	if (variables::clantag == 0)
	{
		set_clantag("");
	}

}


void crosshair()
{

	if (variables::crosshair == 1 && variables::rcs == false)
	{
		if (!csgo::local_player || !csgo::local_player->is_alive())
			return;

		interfaces::console->get_convar("crosshair")->set_value(0);

		std::pair<int, int> screen_size;

		interfaces::surface->get_screen_size(screen_size.first, screen_size.second);
		int x = screen_size.first / 2;
		int y = screen_size.second / 2;

		if (variables::crosshair == 1) {
			vec3_t punch = csgo::local_player->aim_punch_angle();
			if (csgo::local_player->is_scoped())
				punch /= .5f;

			// subtract the punch from the position
			x -= (screen_size.first / 90) * punch.y;
			y += (screen_size.second / 90) * punch.x;
		}

		render::draw_xhair(x, y, true, color::white());

	}

	if (variables::crosshair == 1 && variables::rcs == true)
	{
		interfaces::console->get_convar("crosshair")->set_value(0);

		if (!csgo::local_player || !csgo::local_player->is_alive())
			return;

		std::pair<int, int> screen_size;

		interfaces::surface->get_screen_size(screen_size.first, screen_size.second);
		int x = screen_size.first / 2;
		int y = screen_size.second / 2;
		render::draw_xhair(x, y, true, color::white());
	}

	if (variables::crosshair == 0)
	{
		interfaces::console->get_convar("crosshair")->set_value(1);
	}

}

