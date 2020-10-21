#include "menu.hpp"

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg, color header_text, color header_line, const std::string& name) {
	render::draw_filled_rect(x, y, w, h, bg);
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

	menu_framework::group_box(variables::menu::x, variables::menu::y + 30, 175, 770, render::fonts::watermark_font, "tabs", false); {
		menu_framework::tab(variables::menu::x + 45, variables::menu::y + (260 / 2) - 90, 100, 120, render::fonts::iconfont, "A", menu::current_tab, 0, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 50, 100, 120, render::fonts::extraicons, "a", menu::current_tab, 1, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 180, 100, 120, render::fonts::iconfont, "D", menu::current_tab, 2, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 330, 100, 120, render::fonts::iconfont, "G", menu::current_tab, 3, false);
		menu_framework::tab(variables::menu::x + 35, variables::menu::y + (260 / 2) + 470, 100, 120, render::fonts::iconfont, "B", menu::current_tab, 4, false);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	switch (current_tab) {
	case 0:
		menu_framework::group_box(variables::menu::x + 190, variables::menu::y + 125, 280, 605, render::fonts::menufont, "Aimbot", true); {

			render::draw_filled_rect(variables::menu::x + 190, variables::menu::y + 36, 620, 75, color(25, 25, 25));

			render::draw_rect(variables::menu::x + 190 - 1, variables::menu::y + 36 - 1, 620 + 1, 75 + 1, color(45, 45, 45));

			menu_framework::tab(variables::menu::x + 200, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "D", menu::weapon_current_tab, 0, false);
			menu_framework::tab(variables::menu::x + 335, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "L", menu::weapon_current_tab, 1, false);
			menu_framework::tab(variables::menu::x + 500, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "W", menu::weapon_current_tab, 2, false);
			menu_framework::tab(variables::menu::x + 680, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::weaponicons, "Z", menu::weapon_current_tab, 3, false);

			switch (weapon_current_tab)
			{
			case 0:

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 145, variables::menu::x + 205, render::fonts::menucontent, "Enabled", variables::aimbots::legit::pistols::aimbotToggle);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 165, variables::menu::x + 205, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::pistols::silentaim);

				menu_framework::slider(variables::menu::x + 205, variables::menu::y + 195, 125, render::fonts::menucontent, "Smoothing",
					variables::aimbots::legit::pistols::smoothing, 1, 6.0f);

				menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 220, variables::menu::x + 205, render::fonts::menucontent, "Random Bones", variables::aimbots::legit::pistols::randombones);

				menu_framework::combo_box(variables::menu::x + 220, variables::menu::y + 240, variables::menu::x + 205, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::lbsIsOpened);

				if (variables::menu::combos::lbsIsOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 260, variables::menu::x + 210, render::fonts::menucontent, "Head", variables::aimbots::legit::pistols::ahead);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 275, variables::menu::x + 210, render::fonts::menucontent, "Chest", variables::aimbots::legit::pistols::achest);

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::pistols::astomach);
				}

				menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 320, 285, 410, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 355, variables::menu::x + 540, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::pistols::enabled);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::pistols::delay, 0, 400);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 415, 140, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::pistols::hitchance, 0, 100);
				
				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 445, variables::menu::x + 540, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 465, variables::menu::x + 650, render::fonts::menucontent, "Head", variables::aimbots::trigger::pistols::head);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 480, variables::menu::x + 650, render::fonts::menucontent, "Chest", variables::aimbots::trigger::pistols::chest);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 495, variables::menu::x + 650, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::pistols::stomach);
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

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::smgs::astomach);
				}

				menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 320, 285, 410, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 355, variables::menu::x + 540, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::smgs::enabled);
				
				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::smgs::delay, 0, 400);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 415, 140, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::smgs::hitchance, 0, 100);

				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 445, variables::menu::x + 540, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 465, variables::menu::x + 650, render::fonts::menucontent, "Head", variables::aimbots::trigger::smgs::head);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 480, variables::menu::x + 650, render::fonts::menucontent, "Chest", variables::aimbots::trigger::smgs::chest);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 495, variables::menu::x + 650, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::smgs::stomach);
				}

				break;
			case 2:

				menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 320, 285, 410, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 355, variables::menu::x + 540, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::rifles::enabled);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::rifles::delay, 0, 400);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 415, 140, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::rifles::hitchance, 0, 100);

				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 445, variables::menu::x + 540, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 465, variables::menu::x + 650, render::fonts::menucontent, "Head", variables::aimbots::trigger::rifles::head);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 480, variables::menu::x + 650, render::fonts::menucontent, "Chest", variables::aimbots::trigger::rifles::chest);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 495, variables::menu::x + 650, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::rifles::stomach);
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

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::rifles::astomach);
					
				}

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

					menu_framework::textbutton(variables::menu::x + 210, variables::menu::y + 290, variables::menu::x + 210, render::fonts::menucontent, "Stomach", variables::aimbots::legit::snipers::astomach);

					menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 330, variables::menu::x + 205, render::fonts::menucontent, "Check for scoped", variables::aimbots::legit::snipers::randombones);
					
				}

				else
				{
					menu_framework::check_box(variables::menu::x + 220, variables::menu::y + 270, variables::menu::x + 205, render::fonts::menucontent, "Check for scoped", variables::aimbots::legit::snipers::randombones);
				}

			

				menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 320, 285, 410, render::fonts::menufont, "Triggerbot", true);

				menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 355, variables::menu::x + 540, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::snipers::enabled);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 380, 140, render::fonts::menucontent, "Delay", variables::aimbots::trigger::snipers::delay, 0, 400);

				menu_framework::slider(variables::menu::x + 540, variables::menu::y + 415, 140, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::snipers::hitchance, 0, 100);

				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 445, variables::menu::x + 540, 70, render::fonts::menucontent, "Hitboxes...", variables::menu::combos::tHOpened);

				if (variables::menu::combos::tHOpened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 465, variables::menu::x + 650, render::fonts::menucontent, "Head", variables::aimbots::trigger::snipers::head);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 480, variables::menu::x + 650, render::fonts::menucontent, "Chest", variables::aimbots::trigger::snipers::chest);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 495, variables::menu::x + 650, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::snipers::stomach);
				}
				break;
			}
		}



		menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 125, 285, 160, render::fonts::menufont, "Other", true);

		menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 145, variables::menu::x + 540, render::fonts::menucontent, "Recoil Control", variables::aimbots::legit::rcs);

		menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 165, variables::menu::x + 540, render::fonts::menucontent, "Recoil Crosshair", variables::aimbots::legit::crosshair);

		break;



	case 1:


		render::draw_filled_rect(variables::menu::x + 190, variables::menu::y + 36, 620, 75, color(25, 25, 25));

		render::draw_rect(variables::menu::x + 190 - 1, variables::menu::y + 36 - 1, 620 + 1, 75 + 1, color(45, 45, 45));

		menu_framework::tab(variables::menu::x + 200, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::Sweaponicons, "D", menu::rage_weapon_current_tab, 0, false);
		menu_framework::tab(variables::menu::x + 285, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::Sweaponicons, "J", menu::rage_weapon_current_tab, 1, false);
		menu_framework::tab(variables::menu::x + 410, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::Sweaponicons, "a", menu::rage_weapon_current_tab, 2, false);
		menu_framework::tab(variables::menu::x + 540, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::Sweaponicons, "Y", menu::rage_weapon_current_tab, 3, false);
		menu_framework::tab(variables::menu::x + 680, variables::menu::y + (260 / 2) - 130, 100, 120, render::fonts::Sweaponicons, "Z", menu::rage_weapon_current_tab, 4, false);


		menu_framework::group_box(variables::menu::x + 190, variables::menu::y + 125, 285, 590, render::fonts::menufont, "Ragebot", true); {

		menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 125, 285, 410, render::fonts::menufont, "AntiAim", true);
		{
			menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 145, variables::menu::x + 540, render::fonts::menucontent, "Enabled", variables::antiaim::enabled);

			menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 175, variables::menu::x + 540, 50,render::fonts::menucontent, "Pitch", variables::menu::combos::pisopened);
			
			if (variables::menu::combos::pisopened == true)
			{
				menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 195, variables::menu::x + 545, render::fonts::menucontent, "Up", variables::antiaim::pUp);

				menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 210, variables::menu::x + 545, render::fonts::menucontent, "Down", variables::antiaim::pDown);

				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 240, variables::menu::x + 540, 50, render::fonts::menucontent, "Yaw", variables::menu::combos::yisopened);

				if (variables::menu::combos::yisopened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 260, variables::menu::x + 545, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 275, variables::menu::x + 545, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}
				
			}
			else
			{
				menu_framework::combo_box(variables::menu::x + 555, variables::menu::y + 205, variables::menu::x + 540, 50, render::fonts::menucontent, "Yaw", variables::menu::combos::yisopened);

				if (variables::menu::combos::yisopened == true)
				{
					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 225, variables::menu::x + 545, render::fonts::menucontent, "Static", variables::antiaim::yStatic);

					menu_framework::textbutton(variables::menu::x + 545, variables::menu::y + 240, variables::menu::x + 545, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);
				}
				
			}
		}
		
		menu_framework::group_box(variables::menu::x + 525, variables::menu::y + 550, 285, 163, render::fonts::menufont, "Other", true);
		{
			menu_framework::check_box(variables::menu::x + 555, variables::menu::y + 570, variables::menu::x + 540, render::fonts::menucontent, "Airstuck", variables::misc::airstuck);
		}

		
			switch (rage_weapon_current_tab)
			{
			case 0:

				break;

			case 1:

				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

				break;
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


			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 400, render::fonts::menufont, "Chams", true);

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

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 185, variables::menu::x + 515, 100, render::fonts::menucontent, "Chams Material", variables::menu::combos::c_mOpened);

				if (variables::menu::combos::c_mOpened == true)
				{
					if (variables::colors::cMats::m_normal == true)
					{
						variables::colors::cMats::m_flat = false;
						variables::colors::cMats::m_ghost = false;
					}

					if (variables::colors::cMats::m_flat == true)
					{
						variables::colors::cMats::m_ghost = false;
						variables::colors::cMats::m_normal = false;
					}

					if (variables::colors::cMats::m_ghost == true)
					{
						variables::colors::cMats::m_flat = false;
						variables::colors::cMats::m_normal = false;
					}
					
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 205, variables::menu::x + 520, render::fonts::menucontent, "Normal", variables::colors::cMats::m_normal);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 220, variables::menu::x + 520, render::fonts::menucontent, "Flat", variables::colors::cMats::m_flat);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 235, variables::menu::x + 520, render::fonts::menucontent, "Crystal", variables::colors::cMats::m_ghost);			
				}
				
				if (variables::menu::combos::c_mOpened)
				{
					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 300, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 310, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 320, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_blue, 0.0f, 255.0f, 3);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 350, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::xqz_c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 360, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 370, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_blue, 0.0f, 255.0f, 3);
				}

				else
				{
					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 220, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 230, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 240, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_blue, 0.0f, 255.0f, 3);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 270, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::xqz_c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 280, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 290, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_blue, 0.0f, 255.0f, 3);
				}
				
			}
			else
			{

				menu_framework::combo_box(variables::menu::x + 530, variables::menu::y + 140, variables::menu::x + 515, 100, render::fonts::menucontent, "Chams Material", variables::menu::combos::c_mOpened);
				
				if (variables::menu::combos::c_mOpened)
				{

					if (variables::colors::cMats::m_normal == true)
					{
						variables::colors::cMats::m_flat = false;
						variables::colors::cMats::m_ghost = false;
					}

					if (variables::colors::cMats::m_flat == true)
					{
						variables::colors::cMats::m_ghost = false;
						variables::colors::cMats::m_normal = false;
					}

					if (variables::colors::cMats::m_ghost == true)
					{
						variables::colors::cMats::m_flat = false;
						variables::colors::cMats::m_normal = false;
					}
					
					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 160, variables::menu::x + 520, render::fonts::menucontent, "Normal", variables::colors::cMats::m_normal);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 175, variables::menu::x + 520, render::fonts::menucontent, "Flat", variables::colors::cMats::m_flat);

					menu_framework::textbutton(variables::menu::x + 520, variables::menu::y + 190, variables::menu::x + 520, render::fonts::menucontent, "Crystal", variables::colors::cMats::m_ghost);
					
					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 260, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 270, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 280, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_blue, 0.0f, 255.0f, 3);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 310, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::xqz_c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 320, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 330, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_blue, 0.0f, 255.0f, 3);
				}

				else
				{
					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 180, 125, render::fonts::menucontent, "Chams Visible Color", variables::colors::cFloats::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 190, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 200, 125, render::fonts::menucontent, "", variables::colors::cFloats::c_blue, 0.0f, 255.0f, 3);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 230, 125, render::fonts::menucontent, "Chams Non Visible Color", variables::colors::cFloats::xqz_c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 240, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 250, 125, render::fonts::menucontent, "", variables::colors::cFloats::xqz_c_blue, 0.0f, 255.0f, 3);
				}
				
			}

			menu_framework::group_box(variables::menu::x + 200, variables::menu::y + 330, 285, 395, render::fonts::menufont, "Localplayer", true); {

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 360, variables::menu::x + 215, render::fonts::menucontent, "No Hands", variables::Visuals::chams::nohands);

				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 380, variables::menu::x + 215, render::fonts::menucontent, "Hand Chams", variables::Visuals::chams::armschams);

				menu_framework::combo_box(variables::menu::x + 230, variables::menu::y + 410, variables::menu::x + 215, 100, render::fonts::menucontent, "Hand Chams Material", variables::menu::combos::a_Combo);		

				if (variables::menu::combos::a_Combo == true)
				{

					if (variables::colors::cMats::arms::m_normal == true)
					{
						variables::colors::cMats::arms::m_crystal = false;
						variables::colors::cMats::arms::m_flat = false;
					}

					if (variables::colors::cMats::arms::m_crystal == true)
					{
						variables::colors::cMats::arms::m_normal = false;
						variables::colors::cMats::arms::m_flat = false;
					}

					if (variables::colors::cMats::arms::m_flat == true)
					{
						variables::colors::cMats::arms::m_crystal = false;
						variables::colors::cMats::arms::m_normal = false;
					}
					
					menu_framework::textbutton(variables::menu::x + 220, variables::menu::y + 430, variables::menu::x + 220, render::fonts::menucontent, "Normal", variables::colors::cMats::arms::m_normal);

					menu_framework::textbutton(variables::menu::x + 220, variables::menu::y + 445, variables::menu::x + 220, render::fonts::menucontent, "Flat", variables::colors::cMats::arms::m_flat);

					menu_framework::textbutton(variables::menu::x + 220, variables::menu::y + 460, variables::menu::x + 220, render::fonts::menucontent, "Crystal", variables::colors::cMats::arms::m_crystal);

					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 530, 125, render::fonts::menucontent, "Arm Chams Color", variables::colors::cMats::arms::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 540, 125, render::fonts::menucontent, "", variables::colors::cMats::arms::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 550, 125, render::fonts::menucontent, "", variables::colors::cMats::arms::c_blue, 0.0f, 255.0f, 3);		
				}
				else
				{
					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 450, 125, render::fonts::menucontent, "Arm Chams Color", variables::colors::cMats::arms::c_red, 0.0f, 255.0f, 1);

					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 460, 125, render::fonts::menucontent, "", variables::colors::cMats::arms::c_green, 0.0f, 255.0f, 2);

					menu_framework::clr_slider(variables::menu::x + 215, variables::menu::y + 470, 125, render::fonts::menucontent, "", variables::colors::cMats::arms::c_blue, 0.0f, 255.0f, 3);
				}
				
			}

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 465, 285, 260, render::fonts::menufont, "World", true);

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

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 230, variables::menu::x + 215, render::fonts::menucontent, "Watermark", variables::misc::watermark);

			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 250, variables::menu::x + 215, render::fonts::menucontent, "Mouse Strafer", variables::misc::autostrafe);

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 50, 285, 260, render::fonts::menufont, "Config", true);

			menu_framework::group_box(variables::menu::x + 500, variables::menu::y + 335, 285, 260, render::fonts::menufont, "Settings", true);

			menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 365, 125, render::fonts::menucontent, "Menu Color", variables::colors::menu::floats::r, 0.0f, 255.0f, 1);

			menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 375, 125, render::fonts::menucontent, "", variables::colors::menu::floats::g, 0.0f, 255.0f, 2);

			menu_framework::clr_slider(variables::menu::x + 515, variables::menu::y + 385, 125, render::fonts::menucontent, "", variables::colors::menu::floats::b, 0.0f, 255.0f, 3);
				
		}
		break;
		}
		}
	}
	menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 30);
}

void menu::toggle()
{
	if (GetAsyncKeyState(VK_F6) & 1)
		variables::menu::opened = !variables::menu::opened;
}