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

	do_frame(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(36, 36, 36, 255), color(25, 25, 25, 255), color(36, 36, 36, 255), "WiinerV2 | Welcome User | Enjoy Hitting P |");
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	menu_framework::group_box(variables::menu::x, variables::menu::y + 30, 175, 595, render::fonts::watermark_font, "tabs", false); {
		menu_framework::tab(variables::menu::x + 45, variables::menu::y + (260 / 2) - 90, 100, 120, render::fonts::iconfont, "A", menu::current_tab, 0, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 50, 100, 120, render::fonts::extraicons, "a", menu::current_tab, 1, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 180, 100, 120, render::fonts::iconfont, "D", menu::current_tab, 2, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 310, 100, 120, render::fonts::iconfont, "G", menu::current_tab, 3, false);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	switch (current_tab) {
	case 0:
		menu_framework::group_box(variables::menu::x + 190, variables::menu::y + 125, 285, 400, render::fonts::menufont, "Aimbot", true); {

			render::draw_filled_rect(variables::menu::x + 190, variables::menu::y + 36, 600, 75, color(25, 25, 25));

			render::draw_rect(variables::menu::x + 190 - 1, variables::menu::y + 36 - 1, 600 + 1, 75 + 1, color(45, 45, 45));

			menu_framework::tab(variables::menu::x + 180, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "C", menu::weapon_current_tab, 0, false);
			menu_framework::tab(variables::menu::x + 300, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "M", menu::weapon_current_tab, 1, false);
			menu_framework::tab(variables::menu::x + 480, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "T", menu::weapon_current_tab, 2, false);
			menu_framework::tab(variables::menu::x + 665, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "a", menu::weapon_current_tab, 3, false);

			switch (weapon_current_tab)
			{
			case 0:

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 145, variables::menu::x + 205, render::fonts::menucontent, "Enabled", variables::aimbots::legit::pistols::aimbotToggle);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 165, variables::menu::x + 205, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::pistols::silentaim);

				menu_framework::slider(variables::menu::x + 205, variables::menu::y + 195, 125, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::pistols::smoothing, 1.0f, 6.0f);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 220, variables::menu::x + 205, render::fonts::menucontent, "Random Bones", variables::aimbots::legit::pistols::randombones);

				menu_framework::combo_box(variables::menu::x + 220, variables::menu::y + 240, variables::menu::x + 205, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::lbsIsOpened);

				if (variables::menu::combos::lbsIsOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 260, variables::menu::x + 210, render::fonts::menucontent, "Head", variables::aimbots::legit::pistols::ahead);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 275, variables::menu::x + 210, render::fonts::menucontent, "Chest", variables::aimbots::legit::pistols::achest);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::pistols::afeet);
				}

				menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 320, 285, 205, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 355, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::pistols::enabled);

				menu_framework::slider(variables::menu::x + 515, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::pistols::delay, 0, 400);

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 405, variables::menu::x + 515, 100, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 425, variables::menu::x + 520, render::fonts::menucontent, "Head", variables::aimbots::trigger::pistols::head);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 440, variables::menu::x + 520, render::fonts::menucontent, "Neck", variables::aimbots::trigger::pistols::neck);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 455, variables::menu::x + 520, render::fonts::menucontent, "Chest", variables::aimbots::trigger::pistols::chest);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 470, variables::menu::x + 520, render::fonts::menucontent, "Legs", variables::aimbots::trigger::pistols::legs);
				}

				break;
			case 1:

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 145, variables::menu::x + 205, render::fonts::menucontent, "Enabled", variables::aimbots::legit::smgs::aimbotToggle);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 165, variables::menu::x + 205, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::smgs::silentaim);

				menu_framework::slider(variables::menu::x + 205, variables::menu::y + 195, 125, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::smgs::smoothing, 1.0f, 6.0f);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 220, variables::menu::x + 205, render::fonts::menucontent, "Random Bones", variables::aimbots::legit::smgs::randombones);

				menu_framework::combo_box(variables::menu::x + 220, variables::menu::y + 240, variables::menu::x + 205, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::lbsIsOpened);

				if (variables::menu::combos::lbsIsOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 260, variables::menu::x + 210, render::fonts::menucontent, "Head", variables::aimbots::legit::smgs::ahead);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 275, variables::menu::x + 210, render::fonts::menucontent, "Chest", variables::aimbots::legit::smgs::achest);
					
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::smgs::afeet);
				}
				menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 320, 285, 205, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 355, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::smgs::enabled);

				menu_framework::slider(variables::menu::x + 515, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::smgs::delay, 0, 400);

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 405, variables::menu::x + 515, 70,render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 425, variables::menu::x + 520, render::fonts::menucontent, "Head", variables::aimbots::trigger::smgs::head);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 440, variables::menu::x + 520, render::fonts::menucontent, "Neck", variables::aimbots::trigger::smgs::neck);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 455, variables::menu::x + 520, render::fonts::menucontent, "Chest", variables::aimbots::trigger::smgs::chest);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 470, variables::menu::x + 520, render::fonts::menucontent, "Legs", variables::aimbots::trigger::smgs::legs);
				}

				break;
			case 2:

				menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 320, 285, 205, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 355, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::rifles::enabled);

				menu_framework::slider(variables::menu::x + 515, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::rifles::delay, 0, 400);

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 405, variables::menu::x + 515, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 425, variables::menu::x + 520, render::fonts::menucontent, "Head", variables::aimbots::trigger::bones::head);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 440, variables::menu::x + 520, render::fonts::menucontent, "Neck", variables::aimbots::trigger::rifles::neck);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 455, variables::menu::x + 520, render::fonts::menucontent, "Chest", variables::aimbots::trigger::rifles::chest);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 470, variables::menu::x + 520, render::fonts::menucontent, "Legs", variables::aimbots::trigger::rifles::legs);
				}

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 145, variables::menu::x + 205, render::fonts::menucontent, "Enabled", variables::aimbots::legit::rifles::aimbotToggle);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 165, variables::menu::x + 205, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::rifles::silentaim);

				menu_framework::slider(variables::menu::x + 205, variables::menu::y + 195, 125, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::rifles::smoothing, 1.0f, 6.0f);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 220, variables::menu::x + 205, render::fonts::menucontent, "Random Bones", variables::aimbots::legit::rifles::randombones);

				menu_framework::combo_box(variables::menu::x + 220, variables::menu::y + 240, variables::menu::x + 205, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::lbsIsOpened);

				if (variables::menu::combos::lbsIsOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 260, variables::menu::x + 210, render::fonts::menucontent, "Head", variables::aimbots::legit::rifles::ahead);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 275, variables::menu::x + 210, render::fonts::menucontent, "Chest", variables::aimbots::legit::rifles::achest);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::rifles::afeet);

			
				break;
				
			case 3:

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 145, variables::menu::x + 205, render::fonts::menucontent, "Enabled", variables::aimbots::legit::snipers::aimbotToggle);

			//	menu_framework::keybind(variables::menu::x + 400, variables::menu::y + 145, variables::menu::x + 400, render::fonts::menucontent, "Bind", variables::aimbots::legit::snipers::keybindings::aimbotbind);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 165, variables::menu::x + 205, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::snipers::silentaim);

				menu_framework::slider(variables::menu::x + 205, variables::menu::y + 195, 125, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::snipers::smoothing, 1.0f, 6.0f);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 220, variables::menu::x + 205, render::fonts::menucontent, "Random Bones", variables::aimbots::legit::snipers::randombones);

				menu_framework::combo_box(variables::menu::x + 220, variables::menu::y + 240, variables::menu::x + 205, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::lbsIsOpened);

				if (variables::menu::combos::lbsIsOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 260, variables::menu::x + 210, render::fonts::menucontent, "Head", variables::aimbots::legit::snipers::ahead);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 275, variables::menu::x + 210, render::fonts::menucontent, "Chest", variables::aimbots::legit::snipers::achest);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::snipers::afeet);
					}
					
					menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 320, 285, 205, render::fonts::menufont, "Triggerbot", true);

					menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 355, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::snipers::enabled);

					menu_framework::slider(variables::menu::x + 515, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::snipers::delay, 0, 400);

					menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 405, variables::menu::x + 515, 100, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

					if (variables::menu::combos::tHOpened == true)
					{
						menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 425, variables::menu::x + 520, render::fonts::menucontent, "Head", variables::aimbots::trigger::snipers::head);

						menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 440, variables::menu::x + 520, render::fonts::menucontent, "Neck", variables::aimbots::trigger::snipers::neck);

						menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 455, variables::menu::x + 520, render::fonts::menucontent, "Chest", variables::aimbots::trigger::snipers::chest);

						menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 470, variables::menu::x + 520, render::fonts::menucontent, "Legs", variables::aimbots::trigger::snipers::legs);
					}
					
					break;
				}
			}
		}
	
			
			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 125, 285, 160, render::fonts::menufont, "Other", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 145, variables::menu::x + 515, render::fonts::menucontent, "Recoil Control", variables::aimbots::legit::rcs);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 165, variables::menu::x + 515, render::fonts::menucontent, "Recoil Crosshair", variables::aimbots::legit::crosshair);

			break;

		
	case 1:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 560, render::fonts::menufont, "Ragebot", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Enabled", variables::aimbots::rage::ragebot);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Target by crosshair", variables::aimbots::rage::ctarget);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Target by distance", variables::aimbots::rage::cdistance);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Target by health", variables::aimbots::rage::chealth);


			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 400, render::fonts::menufont, "Antiaim", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 80, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::antiaim::enabled);

			menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 110, variables::menu::x + 515, 50,render::fonts::menucontent, "Pitch...", variables::menu::combos::pisopened);

			if (variables::menu::combos::pisopened == true)
			{

				if (variables::antiaim::pUp == true)
				{
					variables::antiaim::pDown = false;
				}

				if (variables::antiaim::pDown == true)
				{
					variables::antiaim::pUp = false;
				}
				
				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 130, variables::menu::x + 520, render::fonts::menucontent, "Up", variables::antiaim::pUp);

				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 145, variables::menu::x + 520, render::fonts::menucontent, "Down", variables::antiaim::pDown);

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 180, variables::menu::x + 515, 50,render::fonts::menucontent, "Yaw...", variables::yisopened);

				if (variables::yisopened == true)
				{

					if (variables::antiaim::yStatic == true)
					{
						variables::antiaim::yJitter = false;
					}

					if (variables::antiaim::yJitter == true)
					{
						variables::antiaim::yStatic = false;
					}
					
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 200, variables::menu::x + 520, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 215, variables::menu::x + 520, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}

			}
			else {
				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 145, variables::menu::x + 515, 50, render::fonts::menucontent, "Yaw...", variables::yisopened);

				if (variables::yisopened == true)
				{

					if (variables::antiaim::yStatic == true)
					{
						variables::antiaim::yJitter = false;
					}

					if (variables::antiaim::yJitter == true)
					{
						variables::antiaim::yStatic = false;
					}
					
					if (variables::antiaim::yStatic == true)
					{
						variables::antiaim::yJitter = false;
					}

					if (variables::antiaim::yJitter == true)
					{
						variables::antiaim::yStatic = false;
					}
					
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 165, variables::menu::x + 520, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 180, variables::menu::x + 520, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}
			}

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 460, 285, 150, render::fonts::menufont, "Other", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 490, variables::menu::x + 515, render::fonts::menucontent, "Airstuck", variables::misc::airstuck);

		}
		break;
	case 2:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 260, render::fonts::menufont, "ESP", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Enabled", variables::Visuals::esp::espToggle);


			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Box", variables::Visuals::esp::box);


			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Name", variables::Visuals::esp::name);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Health Bar", variables::Visuals::esp::healthbar);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 160, variables::menu::x + 215, render::fonts::menucontent, "Shield Bar", variables::Visuals::esp::shieldbar);

			menu_framework::combo_box(variables::menu::x + 230, variables::menu::y + 180, variables::menu::x + 215, 50, render::fonts::menucontent, "BoneESP", variables::menu::combos::boneComboToggle);

			if (variables::menu::combos::boneComboToggle)
			{

				if (variables::Visuals::esp::bonealways == true)
				{
					variables::Visuals::esp::bonevisible = false;
				}

				if (variables::Visuals::esp::bonevisible == true)
				{
					variables::Visuals::esp::bonealways = false;
				}
				
				menu_framework::textbutton(variables::menu::x + 220, variables::menu::y + 200, variables::menu::x + 220, render::fonts::menucontent, "Visible", variables::Visuals::esp::bonevisible);

				menu_framework::textbutton(variables::menu::x + 220, variables::menu::y + 215, variables::menu::x + 220, render::fonts::menucontent, "Always", variables::Visuals::esp::bonealways);

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 240, variables::menu::x + 215, render::fonts::menucontent, "Weapon Icons", variables::Visuals::esp::weaponesp);
				
			}
			else
			{
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 210, variables::menu::x + 215, render::fonts::menucontent, "Weapon Icons", variables::Visuals::esp::weaponesp);

			}
		

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Chams", true);

			menu_framework::check_box(variables::menu::x + 530, variables::menu::y + 80, variables::menu::x + 515, render::fonts::menucontent, "Enabled", variables::Visuals::chams::chams);

			menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 100, variables::menu::x + 515, 70, render::fonts::menucontent, "Chams Mode", variables::menu::combos::cCOpened);
		
			if (variables::menu::combos::cCOpened)
			{

				if (variables::Visuals::chams::chamsvisible == true)
				{
					variables::Visuals::chams::chamsalways = false;
					variables::Visuals::chams::chamsxqz = false;
				}

				if (variables::Visuals::chams::chamsalways == true)
				{
					variables::Visuals::chams::chamsvisible = false;
					variables::Visuals::chams::chamsxqz = false;
				}

				if (variables::Visuals::chams::chamsxqz == true)
				{
					variables::Visuals::chams::chamsalways = false;
					variables::Visuals::chams::chamsvisible = false;
				}
				
				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 120, variables::menu::x + 520, render::fonts::menucontent, "Chams Visible", variables::Visuals::chams::chamsvisible);

				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 135, variables::menu::x + 520, render::fonts::menucontent, "Chams Always", variables::Visuals::chams::chamsalways);

				menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 150, variables::menu::x + 520, render::fonts::menucontent, "Chams XQZ", variables::Visuals::chams::chamsxqz);

				menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 190, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::chamfloat, 1.0f, 10.0f, variables::colors::chamcolor);


				menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 230, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::chamfloat, 1.0f, 10.0f, variables::colors::chamcolor);
				
			}
			else
			{
				menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 140, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::chamfloat, 1.0f, 10.0f, variables::colors::chamcolor);


				menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 180, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::chamfloat, 1.0f, 10.0f, variables::colors::chamcolor);

			}

			menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 330, 285, 260, render::fonts::menufont, "Localplayer", true); {

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 360, variables::menu::x + 215, render::fonts::menucontent, "No Hands", variables::Visuals::chams::nohands);

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 380, variables::menu::x + 215, render::fonts::menucontent, "Hand Chams", variables::Visuals::chams::armschams);

			}

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 330, 285, 260, render::fonts::menufont, "World", true);

			break;

	case 3:
		menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 50, 285, 545, render::fonts::menufont, "Misc", true); {

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, variables::menu::x + 215, render::fonts::menucontent, "Perfect Bunny Hop", variables::misc::pbunny);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, variables::menu::x + 215, render::fonts::menucontent, "Legit Bunny Hop", variables::misc::lbunny);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 120, variables::menu::x + 215, render::fonts::menucontent, "Antiflash", variables::misc::antiflash);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 140, variables::menu::x + 215, render::fonts::menucontent, "Dynamic Clantag", variables::misc::dtag);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 160, variables::menu::x + 215, render::fonts::menucontent, "Static Clantag", variables::misc::stag);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 180, variables::menu::x + 215, render::fonts::menucontent, "Field of View Override", variables::fov::fovOveride);

			menu_framework::slider(variables::menu::x + 215, variables::menu::y + 205, 140, render::fonts::menucontent, "Fov Override Amount", variables::fov::fovamount, 1.f, 120.0f);

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Config", true);

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 335, 285, 260, render::fonts::menufont, "Settings", true);

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