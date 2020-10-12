#include "menu.hpp"

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg, color header_text, color header_line, const std::string& name) {
	render::draw_filled_rect(x, y, w, h, bg);
	render::draw_filled_rect(x, y, w, 30, header_text);
	render::draw_filled_rect(x, y + 30, w, 2, header_line);
	render::text(x + 10, y + 8, render::fonts::watermark_font, name, false, color::white());
};

void menu::render()
{
	if (!variables::menu::opened)
		return;


	do_frame(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(36, 36, 36, 255), color(25, 25, 25, 255), color(36, 36, 36, 255), "WiinerV2 | Welcome User | Enjoy Hitting P");
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	menu_framework::group_box(variables::menu::x + 5, variables::menu::y + 35, 175, 585, render::fonts::watermark_font, "tabs", false); {
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 50, 100, 30, render::fonts::tabfont, "AIMBOT", menu::current_tab, 0, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 120, 100, 30, render::fonts::tabfont, "RAGE", menu::current_tab, 1, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 205, 100, 30, render::fonts::tabfont, "VISUALS", menu::current_tab, 2, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 290, 100, 30, render::fonts::tabfont, "MISC", menu::current_tab, 3, false);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	switch (current_tab) {
	case 0:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Aimbot", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Enabled", variables::aimbotToggle);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Silent Aim", variables::silentaim);

			menu_framework::slider(variables::menu::x + 215, variables::menu::y + 125, 125, render::fonts::menucontent, "Smoothing", variables::smoothing, 0.0f, 6.0f);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 150, variables::menu::x + 215, render::fonts::menucontent, "Random Bones", variables::randombones);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 170, variables::menu::x + 215, render::fonts::menucontent, "Head", variables::ahead);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 190, variables::menu::x + 215, render::fonts::menucontent, "Neck", variables::aneck);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 210, variables::menu::x + 215, render::fonts::menucontent, "Chest", variables::achest);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 230, variables::menu::x + 215, render::fonts::menucontent, "Pelvis", variables::apelvis);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 250, variables::menu::x + 215, render::fonts::menucontent, "Feet", variables::afeet);


			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Other", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 80, variables::menu::x + 515, render::fonts::menucontent, "Recoil Control", variables::rcs);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 100, variables::menu::x + 515, render::fonts::menucontent, "Recoil Crosshair", variables::crosshair);

		}
		break;
	case 1:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 545, render::fonts::menufont, "Ragebot", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Enabled", variables::ragebot);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Target by crosshair", variables::ctarget);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Target by distance", variables::cdistance);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Target by health", variables::chealth);


		menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 400, render::fonts::menufont, "Antiaim", true);
			
		menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 80, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::antiaim::enabled);

			menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 110, variables::menu::x + 515, render::fonts::menucontent, "Pitch...", variables::pisopened);

			if (variables::pisopened == true)
			{
				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 130, variables::menu::x + 520, render::fonts::menucontent, "Up", variables::antiaim::pUp);

				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 145, variables::menu::x + 520, render::fonts::menucontent, "Down", variables::antiaim::pDown);

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 200, variables::menu::x + 515, render::fonts::menucontent, "Yaw...", variables::yisopened);

				if (variables::yisopened == true)
				{
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 220, variables::menu::x + 520, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 235, variables::menu::x + 520, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}

			}
			else {
				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 130, variables::menu::x + 515, render::fonts::menucontent, "Yaw...", variables::yisopened);

				if (variables::yisopened == true)
				{
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 150, variables::menu::x + 520, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 165, variables::menu::x + 520, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}
			}		

		menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 460, 285, 150, render::fonts::menufont, "Other", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 490, variables::menu::x + 515, render::fonts::menucontent, "Airstuck", variables::airstuck);

		}
		break;
	case 2:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 260, render::fonts::menufont, "ESP", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Enabled", variables::espToggle);


			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Box", variables::box);


			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Name", variables::name);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Health Bar", variables::healthbar);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 160, variables::menu::x + 215, render::fonts::menucontent, "Shield Bar", variables::shieldbar);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 180, variables::menu::x + 215, render::fonts::menucontent, "BoneESP Visible", variables::bonevisible);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 200, variables::menu::x + 215, render::fonts::menucontent, "BoneESP Always", variables::bonealways);

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Chams", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 80, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::chams);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 100, variables::menu::x + 515, render::fonts::menucontent, "Chams Visible", variables::chamsvisible);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 120, variables::menu::x + 515, render::fonts::menucontent, "Chams Always", variables::chamsalways);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 140, variables::menu::x + 515, render::fonts::menucontent, "Chams XQZ", variables::chamsxqz);

			menu_framework::clr_slider(variables::menu::x + 530, variables::menu::y + 160, 125, render::fonts::menucontent, "Color", variables::chamfloat, 1.0f, 10.0f, variables::chamcolor);


			menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 330, 285, 260, render::fonts::menufont, "Localplayer", true); {

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 360, variables::menu::x + 215, render::fonts::menucontent, "No Hands", variables::nohands);

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 380, variables::menu::x + 215, render::fonts::menucontent, "Hand Chams", variables::armschams);

			}
			break;

	case 3:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Misc", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Perfect Bunny Hop", variables::pbunny);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Legit Bunny Hop", variables::lbunny);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Antiflash", variables::antiflash);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Dynamic Clantag", variables::dtag);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 160, variables::menu::x + 215, render::fonts::menucontent, "Static Clantag", variables::stag);

		}
		break;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 30);
}

void menu::toggle()
{
	if (GetAsyncKeyState(VK_F6) & 1)
		variables::menu::opened = !variables::menu::opened;
}