#include "../features.hpp"

void mouseStrafer(c_usercmd* cmd)
{
	if (variables::misc::autostrafe == true)
	{
		const int move_type = csgo::local_player->move_type();

		if (move_type == movetype_ladder || move_type == movetype_noclip || move_type == movetype_observer)

			if (variables::misc::pbunny == true && csgo::local_player->flags() & in_jump)
			{
				if (cmd->viewangles.y == 0)
				{
					if (cmd->buttons |= in_forward)
					{
						cmd->viewangles.y + 0;
					}
					else
					{
						cmd->buttons |= in_forward;
						cmd->viewangles.y + 0;
					}
				}

				if (cmd->viewangles.y == -90)
				{
					if (cmd->buttons |= in_moveleft)
					{
						cmd->viewangles.y + -90;
					}
					else
					{
						cmd->buttons |= in_forward;
						cmd->viewangles.y + 0;
					}
				}

				if (cmd->viewangles.y == 90)
				{
					if (cmd->buttons |= in_moveright)
					{
						cmd->viewangles.y + 90;
					}
					else
					{
						cmd->buttons |= in_forward;
						cmd->viewangles.y + 0;
					}
				}

			}
	}
}

void misc::movement::bunny_hop(c_usercmd* cmd) {

	mouseStrafer(cmd);

	if (variables::misc::pbunny == true)
	{
		const int move_type = csgo::local_player->move_type();

		if (move_type == movetype_ladder || move_type == movetype_noclip || move_type == movetype_observer)
			return;

		if (!(csgo::local_player->flags() & fl_onground))
			cmd->buttons &= ~in_jump;
	}

	if (variables::misc::lbunny == true) // legit bhop
	{
		srand(time(0));
		int random = rand() % 4 + 1;
		int jumpamount = 0;

		const int move_type = csgo::local_player->move_type();

		if (move_type == movetype_ladder || move_type == movetype_noclip || move_type == movetype_observer)
			return;

		if (!(csgo::local_player->flags() & fl_onground))
		{
			if (jumpamount <= 1)
			{
				random == 1;
			}

			if (random == 1 || random == 2 && jumpamount < 3)
			{
				cmd->buttons &= ~in_jump;
				jumpamount++;

				if (jumpamount > 3)
				{
					jumpamount = 0;
				}

			}
			jumpamount = 0;
		}

	}

};

void antiflash()
{
	if (variables::misc::antiflash == true)
	{
		if (csgo::local_player->is_flashed() == true)
		{
			csgo::local_player->flash_duration() = 0;
		}
	}
}

void thirdperson()
{
	static bool in_thirdperson = false;

	if (GetAsyncKeyState(VK_MBUTTON) & 1)
		in_thirdperson = !in_thirdperson;

	if (interfaces::input->camera_in_third_person = in_thirdperson)
		interfaces::input->camera_offset.z = 100;
	interfaces::input->camera_offset.x = 0;
}

void set_clantag(std::string clantag)
{
	static auto clantag_original = (int(__fastcall*)(const char*, const char*))utilities::pattern_scan("engine.dll", "53 56 57 8B DA 8B F9 FF 15");
	clantag_original(clantag.c_str(), clantag.c_str());
}

void clantag()
{
	if (variables::misc::dtag == true)
	{
		static float last_change = 0.f;
		if (interfaces::globals->realtime - last_change >= 0.25f) {
			std::string clantag = "";
			switch (int(interfaces::globals->cur_time * 4.f) % 31) { //add latency for better sync
			case 0:  clantag = "               "; break;
			case 1:  clantag = "              W"; break;
			case 2:  clantag = "             Wi"; break;
			case 3:  clantag = "            Wii"; break;
			case 4:  clantag = "           Wiin"; break;
			case 5:  clantag = "          Wiine"; break;
			case 6:  clantag = "         Wiiner"; break;
			case 7:  clantag = "         Wiiner"; break;
			case 8:  clantag = "        Wiine r"; break;
			case 9:  clantag = "      Wiin e r "; break;
			case 10:  clantag = "     Wii n e r  "; break;
			case 11:  clantag = "    Wi i n e r   "; break;
			case 12:  clantag = "   W i i n e r    "; break;
			case 13:  clantag = "  Wi i n e r     "; break;
			case 14:  clantag = " Wii n e r       "; break;
			case 15:  clantag = " Wiin e r       "; break;
			case 16:  clantag = " Wiine r       "; break;
			case 17:  clantag = " Wiiner       "; break;
			}
			set_clantag(clantag);
			last_change = interfaces::globals->realtime;
		}
	}

	if (variables::misc::stag == true)
	{
		set_clantag("Wiiner");
	}

	if (variables::misc::dtag == false && variables::misc::stag == false)
	{
		set_clantag("");
	}

}

void crosshair()
{

	if (variables::aimbots::legit::crosshair == true && variables::aimbots::legit::rcs == false)
	{
		if (!csgo::local_player || !csgo::local_player->is_alive())
			return;

		interfaces::console->get_convar("crosshair")->set_value(0);

		std::pair<int, int> screen_size;

		interfaces::surface->get_screen_size(screen_size.first, screen_size.second);
		int x = screen_size.first / 2;
		int y = screen_size.second / 2;

		if (variables::aimbots::legit::crosshair == 1) {
			vec3_t punch = csgo::local_player->aim_punch_angle();
			if (csgo::local_player->is_scoped())
				punch /= .5f;

			// subtract the punch from the position
			x -= (screen_size.first / 90) * punch.y;
			y += (screen_size.second / 90) * punch.x;
		}

		render::draw_xhair(x, y, true, color::white());

	}

	if (variables::aimbots::legit::crosshair == true && variables::aimbots::legit::rcs == true && interfaces::engine->is_in_game())
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

	if (variables::aimbots::legit::crosshair == false)
	{
		interfaces::console->get_convar("crosshair")->set_value(1);
	}

}

void log(c_usercmd* cmd)
{
	if (interfaces::engine->is_in_game() == true)
	{
		std::string viewangles = std::to_string(cmd->viewangles.x);

		render::draw_text_string(20, 40, render::fonts::tabfont, "Viewangles" + viewangles, false, color(255, 255, 0));
	}
}

void Fov()
{
	if (variables::fov::fovOveride == true)
	{
		float fov = variables::fov::fovamount;
	}
}

void watermark()
{
	if (variables::misc::watermark == true)
	{
		if (interfaces::engine->is_in_game() == true)
		{

			for (int iPlayer = 0; iPlayer < interfaces::globals->max_clients; iPlayer++)
			{
				player_info_t playerinfo;
				interfaces::engine->get_player_info(iPlayer, &playerinfo);

				auto pCSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(iPlayer));

				if (pCSPlayer == csgo::local_player)
				{
					std::string name = playerinfo.name;

					render::draw_text_string(1420, 50, render::fonts::watermark_font, name, false, color(255, 255, 255));

					if (csgo::local_player->is_moving())
					{
						render::draw_text_string(1480, 50, render::fonts::watermark_font, " | Moving ", false, color(255, 255, 255));
					}

					if (csgo::local_player->is_moving() == false)
					{
						render::draw_text_string(1540, 50, render::fonts::watermark_font, " | Dormant ", false, color(255, 255, 255));
					}
				}
			}
		}
	}
}