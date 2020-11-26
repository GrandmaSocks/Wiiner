#include "menu.hpp"

namespace variables
{
	namespace menu
	{
		inline int x = 200, y = 200;
		inline int w = 825, h = 500;
	}
}

void menu::render()
{
	if (!variables::menu::opened)
		return;

	render::draw_filled_rect(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(30, 30, 30));
	render::draw_rect(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(10, 10, 10));
	render::draw_rect(variables::menu::x + 1, variables::menu::y + 1, variables::menu::w - 2, variables::menu::h - 2, color(10, 10, 10));
	render::draw_rect(variables::menu::x + 2, variables::menu::y + 2, variables::menu::w - 4, variables::menu::h - 4, color(10, 10, 10));
	render::draw_filled_rect(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h - 495, color(51, 153, 255));
	render::draw_rect(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h - 495, color(10, 10, 10));
	render::draw_filled_rect(variables::menu::x + 3, variables::menu::y + 7, variables::menu::w - 650, variables::menu::h - 10, color(25, 25, 25));
	
	render::draw_filled_rect(variables::menu::x, variables::menu::y + 525, variables::menu::w, variables::menu::h - 475, color(30, 30, 30));
	render::draw_rect(variables::menu::x, variables::menu::y + 525, variables::menu::w, variables::menu::h - 475, color(10, 10, 10));
	
	menu::quotes(variables::menu::x + 5, variables::menu::y + 525, render::fonts::menucontent);
	
	menu::tab(variables::menu::x, variables::menu::y + 3, 45, 35, render::fonts::bodyfont, "Legit", "a", menu::current_tab, 0, false);
	menu::tab(variables::menu::x, variables::menu::y + 38, 45, 35, render::fonts::bodyfont, "Rage", "a", menu::current_tab, 4, false);
	menu::tab(variables::menu::x + 10, variables::menu::y + 73, 45, 35, render::fonts::bodyfont, "Visuals", "b", menu::current_tab, 1, false);
	menu::tab(variables::menu::x, variables::menu::y + 108, 45, 35, render::fonts::bodyfont, "Misc", "c", menu::current_tab, 2, false);
	menu::tab(variables::menu::x, variables::menu::y + 143, 45, 35, render::fonts::bodyfont, "Skins", "d", menu::current_tab, 3, false);

	switch(current_tab)
	{
	case 0:

		render::draw_filled_rect(variables::menu::x + 225, variables::menu::y + 35, 550, 5, color(50, 50, 50));

		menu::textbutton(variables::menu::x + 225, variables::menu::y + 15, 65, variables::menu::x + 225, render::fonts::headerfont, "Pistols", menu::weapon_current_tab, 0);
		menu::textbutton(variables::menu::x + 305, variables::menu::y + 15, 35, variables::menu::x + 305, render::fonts::headerfont, "SMGS", menu::weapon_current_tab, 1);
		menu::textbutton(variables::menu::x + 355, variables::menu::y + 15, 55, variables::menu::x + 355, render::fonts::headerfont, "Rifles", menu::weapon_current_tab, 2);
		menu::textbutton(variables::menu::x + 425, variables::menu::y + 15, 65, variables::menu::x + 425, render::fonts::headerfont, "Snipers", menu::weapon_current_tab, 3);
		menu::textbutton(variables::menu::x + 505, variables::menu::y + 15, 45, variables::menu::x + 505, render::fonts::headerfont, "Other", menu::weapon_current_tab, 4);

		switch (weapon_current_tab)
		{
		case 0:

			render::draw_text_string(variables::menu::x + 230, variables::menu::y + 60, render::fonts::headerfont, "Aimbot", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 230, variables::menu::y + 90, variables::menu::x + 225, render::fonts::menucontent, "Enabled", variables::aimbots::legit::pistols::aimbotToggle);

			menu::keybind(variables::menu::x + 375, variables::menu::y + 90, variables::menu::x + 355, render::fonts::menucontent, variables::aimbots::legit::pistols::keybindings::aimbotbind, variables::menu::binds::pistolbind, variables::menu::binds::otherpistolbind);
			
			menu::check_box(variables::menu::x + 230, variables::menu::y + 110, variables::menu::x + 225, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::pistols::randombones);

			menu::slider(variables::menu::x + 225, variables::menu::y + 200, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::pistols::smoothing, 0, 5);
			
			menu::combo(variables::menu::x + 225, variables::menu::y + 140, variables::menu::x + 225, 40, render::fonts::menucontent, "Bone Priority", variables::menu::combos::pistol_priority, std::vector< multi_select_item >{ { "Head", & variables::aimbots::legit::pistols::headprioirtybone }, { "Body", &variables::aimbots::legit::pistols::bodyprioritybone }, { "Stomach", &variables::aimbots::legit::pistols::stomachprioritybone }});

			render::draw_text_string(variables::menu::x + 525, variables::menu::y + 60, render::fonts::headerfont, "Trigger", false, color(255, 255, 255));
			
			menu::check_box(variables::menu::x + 525, variables::menu::y + 90, variables::menu::x + 520, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::pistols::enabled);

			menu::keybind(variables::menu::x + 670, variables::menu::y + 90, variables::menu::x + 650, render::fonts::menucontent, variables::aimbots::legit::pistols::keybindings::triggerbind, variables::menu::binds::pistoltriggerbind, variables::menu::binds::othertriggerpistolbind);

			menu::slider(variables::menu::x + 520, variables::menu::y + 180, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::pistols::delay, 0, 1000);

			menu::slider(variables::menu::x + 520, variables::menu::y + 210, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::pistols::hitchance, 0, 1000);

			menu::combo(variables::menu::x + 520, variables::menu::y + 120, variables::menu::x + 525, 45, render::fonts::menucontent, "Hitbox Selection", variables::menu::combos::pistol_trigger_slection, std::vector< multi_select_item >{ { "Head", & variables::aimbots::trigger::pistols::head }, { "Body", &variables::aimbots::trigger::pistols::chest }, { "Stomach", &variables::aimbots::trigger::pistols::stomach }});
			
			break;

		case 1:

			render::draw_text_string(variables::menu::x + 230, variables::menu::y + 60, render::fonts::headerfont, "Aimbot", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 230, variables::menu::y + 90, variables::menu::x + 225, render::fonts::menucontent, "Enabled", variables::aimbots::legit::smgs::aimbotToggle);

			menu::keybind(variables::menu::x + 375, variables::menu::y + 90, variables::menu::x + 355, render::fonts::menucontent, variables::aimbots::legit::smgs::keybindings::aimbotbind, variables::menu::binds::smgbind, variables::menu::binds::othersmgbind);

			menu::check_box(variables::menu::x + 230, variables::menu::y + 110, variables::menu::x + 225, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::smgs::randombones);

			menu::slider(variables::menu::x + 225, variables::menu::y + 200, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::smgs::smoothing, 0, 5);

			menu::combo(variables::menu::x + 225, variables::menu::y + 140, variables::menu::x + 225, 40, render::fonts::menucontent, "Bone Priority", variables::menu::combos::smg_priority, std::vector< multi_select_item >{ { "Head", & variables::aimbots::legit::smgs::headprioirtybone }, { "Body", &variables::aimbots::legit::smgs::bodyprioritybone }, { "Stomach", &variables::aimbots::legit::smgs::stomachprioritybone }});

			render::draw_text_string(variables::menu::x + 525, variables::menu::y + 60, render::fonts::headerfont, "Trigger", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 525, variables::menu::y + 90, variables::menu::x + 520, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::smgs::enabled);

			menu::keybind(variables::menu::x + 670, variables::menu::y + 90, variables::menu::x + 650, render::fonts::menucontent, variables::aimbots::legit::smgs::keybindings::triggerbind, variables::menu::binds::smgtriggerbind, variables::menu::binds::othertriggersmgbind);

			menu::slider(variables::menu::x + 520, variables::menu::y + 180, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::smgs::delay, 0, 1000);

			menu::slider(variables::menu::x + 520, variables::menu::y + 210, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::smgs::hitchance, 0, 1000);

			menu::combo(variables::menu::x + 520, variables::menu::y + 120, variables::menu::x + 525, 45, render::fonts::menucontent, "Hitbox Selection", variables::menu::combos::smg_trigger_slection, std::vector< multi_select_item >{ { "Head", & variables::aimbots::trigger::smgs::head }, { "Body", &variables::aimbots::trigger::smgs::chest }, { "Stomach", &variables::aimbots::trigger::smgs::stomach }});

			break;

		case 2:

			render::draw_text_string(variables::menu::x + 230, variables::menu::y + 60, render::fonts::headerfont, "Aimbot", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 230, variables::menu::y + 90, variables::menu::x + 225, render::fonts::menucontent, "Enabled", variables::aimbots::legit::rifles::aimbotToggle);

			menu::keybind(variables::menu::x + 375, variables::menu::y + 90, variables::menu::x + 355, render::fonts::menucontent, variables::aimbots::legit::rifles::keybindings::aimbotbind, variables::menu::binds::riflebind, variables::menu::binds::otherriflebind);

			menu::check_box(variables::menu::x + 230, variables::menu::y + 110, variables::menu::x + 225, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::rifles::randombones);

			menu::slider(variables::menu::x + 225, variables::menu::y + 200, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::rifles::smoothing, 0, 5);

			menu::combo(variables::menu::x + 225, variables::menu::y + 140, variables::menu::x + 225, 40, render::fonts::menucontent, "Bone Priority", variables::menu::combos::rifle_priority, std::vector< multi_select_item >{ { "Head", & variables::aimbots::legit::rifles::headprioirtybone }, { "Body", &variables::aimbots::legit::rifles::bodyprioritybone }, { "Stomach", &variables::aimbots::legit::rifles::stomachprioritybone }});

			render::draw_text_string(variables::menu::x + 525, variables::menu::y + 60, render::fonts::headerfont, "Trigger", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 525, variables::menu::y + 90, variables::menu::x + 520, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::rifles::enabled);

			menu::keybind(variables::menu::x + 670, variables::menu::y + 90, variables::menu::x + 650, render::fonts::menucontent, variables::aimbots::legit::rifles::keybindings::triggerbind, variables::menu::binds::rifletriggerbind, variables::menu::binds::othertriggerriflebind);

			menu::slider(variables::menu::x + 520, variables::menu::y + 180, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::rifles::delay, 0, 1000);

			menu::slider(variables::menu::x + 520, variables::menu::y + 210, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::rifles::hitchance, 0, 1000);

			menu::combo(variables::menu::x + 520, variables::menu::y + 120, variables::menu::x + 525, 45, render::fonts::menucontent, "Hitbox Selection", variables::menu::combos::rifle_trigger_slection, std::vector< multi_select_item >{ { "Head", & variables::aimbots::trigger::rifles::head }, { "Body", &variables::aimbots::trigger::rifles::chest }, { "Stomach", &variables::aimbots::trigger::rifles::stomach }});

			break;

		case 3:

			render::draw_text_string(variables::menu::x + 230, variables::menu::y + 60, render::fonts::headerfont, "Aimbot", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 230, variables::menu::y + 90, variables::menu::x + 225, render::fonts::menucontent, "Enabled", variables::aimbots::legit::snipers::aimbotToggle);

			menu::keybind(variables::menu::x + 375, variables::menu::y + 90, variables::menu::x + 355, render::fonts::menucontent, variables::aimbots::legit::snipers::keybindings::aimbotbind, variables::menu::binds::sniperbind, variables::menu::binds::othersniperbind);

			menu::check_box(variables::menu::x + 230, variables::menu::y + 110, variables::menu::x + 225, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::snipers::randombones);

			menu::slider(variables::menu::x + 225, variables::menu::y + 200, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::snipers::smoothing, 0, 5);

			menu::check_box(variables::menu::x + 230, variables::menu::y + 230, variables::menu::x + 225, render::fonts::menucontent, "Scope Check", variables::aimbots::legit::snipers::aimcheck);
			
			menu::combo(variables::menu::x + 225, variables::menu::y + 140, variables::menu::x + 225, 40, render::fonts::menucontent, "Bone Priority", variables::menu::combos::sniper_priority, std::vector< multi_select_item >{ { "Head", & variables::aimbots::legit::snipers::headprioirtybone }, { "Body", &variables::aimbots::legit::snipers::bodyprioritybone }, { "Stomach", &variables::aimbots::legit::snipers::stomachprioritybone }});

			render::draw_text_string(variables::menu::x + 525, variables::menu::y + 60, render::fonts::headerfont, "Trigger", false, color(255, 255, 255));

			menu::check_box(variables::menu::x + 525, variables::menu::y + 90, variables::menu::x + 520, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::snipers::enabled);

			menu::keybind(variables::menu::x + 670, variables::menu::y + 90, variables::menu::x + 650, render::fonts::menucontent, variables::aimbots::legit::snipers::keybindings::triggerbind, variables::menu::binds::smgtriggerbind, variables::menu::binds::othertriggersmgbind);

			menu::slider(variables::menu::x + 520, variables::menu::y + 180, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::snipers::delay, 0, 1000);

			menu::slider(variables::menu::x + 520, variables::menu::y + 210, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::snipers::hitchance, 0, 1000);

			menu::check_box(variables::menu::x + 525, variables::menu::y + 240, variables::menu::x + 520, render::fonts::menucontent, "Scope Check", variables::aimbots::trigger::snipers::scopeCheck);
			
			menu::combo(variables::menu::x + 520, variables::menu::y + 120, variables::menu::x + 525, 45, render::fonts::menucontent, "Hitbox Selection", variables::menu::combos::sniper_trigger_slection, std::vector< multi_select_item >{ { "Head", & variables::aimbots::trigger::snipers::head }, { "Body", &variables::aimbots::trigger::snipers::chest }, { "Stomach", &variables::aimbots::trigger::snipers::stomach }});

			break;

		case 4:

			menu::check_box(variables::menu::x + 230, variables::menu::y + 70, variables::menu::x + 225, render::fonts::menucontent, "Backtrack", variables::aimbots::backtrack);
			menu::check_box(variables::menu::x + 230, variables::menu::y + 90, variables::menu::x + 225, render::fonts::menucontent, "Recoil Crosshair", variables::aimbots::legit::crosshair);
			menu::check_box(variables::menu::x + 230, variables::menu::y + 110, variables::menu::x + 225, render::fonts::menucontent, "Recoil Control", variables::aimbots::legit::rcs);
			menu::slider(variables::menu::x + 225, variables::menu::y + 140, 150, render::fonts::menucontent, "Recoil Control X", variables::aimbots::legit::rcs_x, 0, 1);
			menu::slider(variables::menu::x + 225, variables::menu::y + 170, 150, render::fonts::menucontent, "Recoil Control Y", variables::aimbots::legit::rcs_y, 0, 1);

			break;
		}
		
		break;

	case 1:

		render::draw_filled_rect(variables::menu::x + 225, variables::menu::y + 35, 550, 5, color(50, 50, 50));

		break;

	case 2:

		render::draw_filled_rect(variables::menu::x + 225, variables::menu::y + 35, 550, 5, color(50, 50, 50));

		menu::textbutton(variables::menu::x + 220, variables::menu::y + 15, 60, variables::menu::x + 225, render::fonts::headerfont, "General", menu::misc_current_tab, 0);

		menu::textbutton(variables::menu::x + 300, variables::menu::y + 15, 55, variables::menu::x + 305, render::fonts::headerfont, "Config", menu::misc_current_tab, 1);

		switch (misc_current_tab)
		{
		case 0:

			menu::check_box(variables::menu::x + 225, variables::menu::y + 70, variables::menu::x + 220, render::fonts::menucontent, "Antiflash", variables::misc::antiflash);
			menu::check_box(variables::menu::x + 225, variables::menu::y + 90, variables::menu::x + 220, render::fonts::menucontent, "Auto Strafe", variables::misc::autostrafe);
			menu::check_box(variables::menu::x + 225, variables::menu::y + 110, variables::menu::x + 220, render::fonts::menucontent, "Spread Circle", variables::misc::spreadCircle);
			menu::check_box(variables::menu::x + 225, variables::menu::y + 130, variables::menu::x + 220, render::fonts::menucontent, "Thirdperson", variables::misc::thirdperson);

			menu::keybind(variables::menu::x + 400, variables::menu::y + 130, variables::menu::x + 400, render::fonts::menucontent, variables::misc::thirdpersonbind, variables::menu::binds::thirdpersonbind, variables::menu::binds::otherthirdpersonbind);
			
			menu::check_box(variables::menu::x + 225, variables::menu::y + 150, variables::menu::x + 220, render::fonts::menucontent, "Watermark", variables::misc::watermark);

			// clantag checkbox here

			// bunnyhop checkbox here
			
			break;

		case 1:



			break;
		}
		
		break;

	case 3:

		render::draw_filled_rect(variables::menu::x + 225, variables::menu::y + 35, 550, 5, color(50, 50, 50));
		
		break;

	case 4:

		render::draw_filled_rect(variables::menu::x + 225, variables::menu::y + 35, 550, 5, color(50, 50, 50));

		break;
	}
	
	menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 30);
}

void menu::toggle()
{
	if (GetAsyncKeyState(VK_F6) & 1)
		variables::menu::opened = !variables::menu::opened;
}

/*
 if (!variables::menu::opened)
		return;

	if (GetAsyncKeyState(VK_F8) & 1 && variables::menu::opened)
		variables::misc::classicmenu = !variables::misc::classicmenu;

	if (variables::misc::classicmenu)
	{
		menu::create(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(30, 30, 30), color(45, 45, 45), color(45, 45, 45), "WiinerV2");

		render::draw_filled_rect(variables::menu::x, variables::menu::y, 250, 700, color(25, 25,25));
		render::draw_rect(variables::menu::x + .5, variables::menu::y - .5, 250 - .5, 75 + .5, color(125, 125, 125));
		
		render::draw_rect(variables::menu::x + .5, variables::menu::y - 1, 250 - .5, 700 + .5, color(125, 125, 125));

		render::draw_text_string(variables::menu::x + 70, variables::menu::y + 30, render::fonts::headerfont, "WiinerV2", false, color(255, 255, 255));


		render::draw_text_string(variables::menu::x + 20, variables::menu::y + 110, render::fonts::headerfont, "FEATURES", false, color(255, 255, 255));

		render::draw_text_string(variables::menu::x + 20, variables::menu::y + 340, render::fonts::headerfont, "INFO", false, color(255, 255, 255));

		menu::tab(variables::menu::x + 60, variables::menu::y + 370, 10, 35, render::fonts::bodyfont, "Change Logs", "e", menu::current_tab, 5, false);

		
		menu::tab(variables::menu::x + 30, variables::menu::y + 140, 40, 35, render::fonts::bodyfont, "Legit", "a", menu::current_tab, 0, false);
		menu::tab(variables::menu::x + 30, variables::menu::y + 180, 40, 35, render::fonts::bodyfont, "Rage", "a", menu::current_tab, 4, false);
		menu::tab(variables::menu::x + 40, variables::menu::y + 220, 40, 35, render::fonts::bodyfont, "Visuals", "b", menu::current_tab, 1, false);
		menu::tab(variables::menu::x + 30, variables::menu::y + 260, 40, 35, render::fonts::bodyfont, "Misc", "c", menu::current_tab, 2, false);
		menu::tab(variables::menu::x + 30, variables::menu::y + 300, 40, 35, render::fonts::bodyfont, "Skins", "d", menu::current_tab, 3, false);
		
		switch (current_tab)
		{
		case 0:

			render::draw_filled_rect(variables::menu::x + 300, variables::menu::y + 70, 550, 5, color(50, 50, 50));
			
			menu::textbutton(variables::menu::x + 300, variables::menu::y + 50, 70 , variables::menu::x + 300,  render::fonts::headerfont, "Pistols", menu::weapon_current_tab, 0);
			menu::textbutton(variables::menu::x + 385, variables::menu::y + 50, 40, variables::menu::x + 385, render::fonts::headerfont, "SMGS", menu::weapon_current_tab, 1);
			menu::textbutton(variables::menu::x + 445, variables::menu::y + 50, 60, variables::menu::x + 450, render::fonts::headerfont, "Rifles", menu::weapon_current_tab, 2);
			menu::textbutton(variables::menu::x + 525, variables::menu::y + 50, 70 , variables::menu::x + 530,  render::fonts::headerfont, "Snipers", menu::weapon_current_tab, 3);
			menu::textbutton(variables::menu::x + 620, variables::menu::y + 50, 50, variables::menu::x + 600, render::fonts::headerfont, "Other", menu::weapon_current_tab, 4);

			switch(weapon_current_tab)
			{
			case 0:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "AIMBOT", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::legit::pistols::aimbotToggle);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::pistols::silentaim);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::pistols::randombones);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Head Priority", variables::aimbots::legit::pistols::headprioirtybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Body Priority", variables::aimbots::legit::pistols::bodyprioritybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Stomach Priority", variables::aimbots::legit::pistols::stomachprioritybone);
				menu::slider(variables::menu::x + 310, variables::menu::y + 280, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::pistols::smoothing, 1, 5);
				
				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TRIGGER", true, true);

				menu::check_box(variables::menu::x + 610, variables::menu::y + 150, variables::menu::x + 610, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::pistols::enabled);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 170, variables::menu::x + 610, render::fonts::menucontent, "Head", variables::aimbots::trigger::pistols::head);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 190, variables::menu::x + 610, render::fonts::menucontent, "Chest", variables::aimbots::trigger::pistols::chest);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 210, variables::menu::x + 610, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::pistols::stomach);
				menu::slider(variables::menu::x + 610, variables::menu::y + 240, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::pistols::delay, 1, 500);
				menu::slider(variables::menu::x + 610, variables::menu::y + 270, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::pistols::hitchance, 1, 100);
				
				break;
				
			case 1:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "AIMBOT", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::legit::smgs::aimbotToggle);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::smgs::silentaim);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::smgs::randombones);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Head Priority", variables::aimbots::legit::smgs::headprioirtybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Body Priority", variables::aimbots::legit::smgs::bodyprioritybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Stomach Priority", variables::aimbots::legit::smgs::stomachprioritybone);
				menu::slider(variables::menu::x + 310, variables::menu::y + 280, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::smgs::smoothing, 1, 5);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TRIGGER", true, true);

				menu::check_box(variables::menu::x + 610, variables::menu::y + 150, variables::menu::x + 610, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::smgs::enabled);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 170, variables::menu::x + 610, render::fonts::menucontent, "Head", variables::aimbots::trigger::smgs::head);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 190, variables::menu::x + 610, render::fonts::menucontent, "Chest", variables::aimbots::trigger::smgs::chest);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 210, variables::menu::x + 610, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::smgs::stomach);
				menu::slider(variables::menu::x + 610, variables::menu::y + 240, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::smgs::delay, 1, 500);
				menu::slider(variables::menu::x + 610, variables::menu::y + 270, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::smgs::hitchance, 1, 100);
				
				break;
				
			case 2:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "AIMBOT", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::legit::rifles::aimbotToggle);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::rifles::silentaim);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::rifles::randombones);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Head Priority", variables::aimbots::legit::rifles::headprioirtybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Body Priority", variables::aimbots::legit::rifles::bodyprioritybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Stomach Priority", variables::aimbots::legit::rifles::stomachprioritybone);
				menu::slider(variables::menu::x + 310, variables::menu::y + 280, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::rifles::smoothing, 1, 5);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TRIGGER", true, true);

				menu::check_box(variables::menu::x + 610, variables::menu::y + 150, variables::menu::x + 610, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::rifles::enabled);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 170, variables::menu::x + 610, render::fonts::menucontent, "Head", variables::aimbots::trigger::rifles::head);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 190, variables::menu::x + 610, render::fonts::menucontent, "Chest", variables::aimbots::trigger::rifles::chest);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 210, variables::menu::x + 610, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::rifles::stomach);
				menu::slider(variables::menu::x + 610, variables::menu::y + 240, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::rifles::delay, 1, 500);
				menu::slider(variables::menu::x + 610, variables::menu::y + 270, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::rifles::hitchance, 1, 100);
				
				break;
				
			case 3:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "AIMBOT", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::legit::snipers::aimbotToggle);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Silent Aim", variables::aimbots::legit::snipers::silentaim);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Dynamic Bone Selection", variables::aimbots::legit::snipers::randombones);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Head Priority", variables::aimbots::legit::snipers::headprioirtybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Body Priority", variables::aimbots::legit::snipers::bodyprioritybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Stomach Priority", variables::aimbots::legit::snipers::stomachprioritybone);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 270, variables::menu::x + 310, render::fonts::menucontent, "Scope Check", variables::aimbots::legit::snipers::aimcheck);
				menu::slider(variables::menu::x + 310, variables::menu::y + 300, 150, render::fonts::menucontent, "Smoothing", variables::aimbots::legit::snipers::smoothing, 1, 5);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TRIGGER", true, true);

				menu::check_box(variables::menu::x + 610, variables::menu::y + 150, variables::menu::x + 610, render::fonts::menucontent, "Enabled", variables::aimbots::trigger::snipers::enabled);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 170, variables::menu::x + 610, render::fonts::menucontent, "Head", variables::aimbots::trigger::snipers::head);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 190, variables::menu::x + 610, render::fonts::menucontent, "Chest", variables::aimbots::trigger::snipers::chest);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 210, variables::menu::x + 610, render::fonts::menucontent, "Stomach", variables::aimbots::trigger::snipers::stomach);
				menu::check_box(variables::menu::x + 610, variables::menu::y + 230, variables::menu::x + 610, render::fonts::menucontent, "Scope Check", variables::aimbots::trigger::snipers::scopeCheck);
				menu::slider(variables::menu::x + 610, variables::menu::y + 260, 150, render::fonts::menucontent, "Delay", variables::aimbots::trigger::snipers::delay, 1, 500);
				menu::slider(variables::menu::x + 610, variables::menu::y + 290, 150, render::fonts::menucontent, "Hitchance", variables::aimbots::trigger::snipers::hitchance, 1, 100);
				
				break;
				
			case 4:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "OTHER", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Backtrack", variables::aimbots::backtrack);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Recoil Crosshair", variables::aimbots::legit::crosshair);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Recoil Control", variables::aimbots::legit::rcs);
				menu::slider(variables::menu::x + 310, variables::menu::y + 220, 150, render::fonts::menucontent, "Recoil Control X", variables::aimbots::legit::rcs_x, 0, 1);
				menu::slider(variables::menu::x + 310, variables::menu::y + 250, 150, render::fonts::menucontent, "Recoil Control Y", variables::aimbots::legit::rcs_y, 0, 1);

				break;
			}
			
			break;
			
		case 1:

			render::draw_filled_rect(variables::menu::x + 300, variables::menu::y + 70, 550, 5, color(50, 50, 50));

			menu::textbutton(variables::menu::x + 300, variables::menu::y + 50, 30, variables::menu::x + 300, render::fonts::headerfont, "ESP", menu::visuals_current_tab, 0);
			menu::textbutton(variables::menu::x + 345, variables::menu::y + 50, 130, variables::menu::x + 345, render::fonts::headerfont, "Chams Visible", menu::visuals_current_tab, 1);
			menu::textbutton(variables::menu::x + 490, variables::menu::y + 50, 170, variables::menu::x + 490, render::fonts::headerfont, "Chams Non Visible", menu::visuals_current_tab, 2);
			menu::textbutton(variables::menu::x + 675, variables::menu::y + 50, 40, variables::menu::x + 675, render::fonts::headerfont, "Glow", menu::visuals_current_tab, 3);
			menu::textbutton(variables::menu::x + 730, variables::menu::y + 50, 30, variables::menu::x + 730, render::fonts::headerfont, "You", menu::visuals_current_tab, 4);
			menu::textbutton(variables::menu::x + 775, variables::menu::y + 50, 50, variables::menu::x + 775, render::fonts::headerfont, "World ", menu::visuals_current_tab, 5);

			switch (visuals_current_tab)
			{
			case 0:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "ESP", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::Visuals::esp::espToggle);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Box", variables::Visuals::esp::box);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Name", variables::Visuals::esp::name);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Health Bar", variables::Visuals::esp::healthbar);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Shield Bar", variables::Visuals::esp::shieldbar);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Weapon Name", variables::Visuals::esp::weaponesp);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 270, variables::menu::x + 310, render::fonts::menucontent, "Bone Visible", variables::Visuals::esp::bonevisible);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 290, variables::menu::x + 310, render::fonts::menucontent, "Bone Always", variables::Visuals::esp::bonealways);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 310, variables::menu::x + 310, render::fonts::menucontent, "Health Color Override", variables::Visuals::esp::hpoverridecheck);
				menu::clr_slider(variables::menu::x + 510, variables::menu::y + 311, variables::menu::x + 510, render::fonts::menucontent, "", variables::chamopened, variables::colors::esp::o_red, variables::colors::esp::o_green, variables::colors::esp::o_blue);
				
				menu::slider(variables::menu::x + 310, variables::menu::y + 340, 150, render::fonts::menucontent, "Override Health", variables::colors::esp::hpoverride, 1, 100);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 370, variables::menu::x + 310, render::fonts::menucontent, "Backtrack Skeleton", variables::Visuals::esp::backtrackskeleton);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 390, variables::menu::x + 310, render::fonts::menucontent, "Hit Markers", variables::Visuals::esp::hitmarkers);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 410, variables::menu::x + 310, render::fonts::menucontent, "Flashed Flag", variables::Visuals::esp::flag_flashed);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 430, variables::menu::x + 310, render::fonts::menucontent, "Money Flag", variables::Visuals::esp::flag_money);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 450, variables::menu::x + 310, render::fonts::menucontent, "Armor Flag", variables::Visuals::esp::flag_armor);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 470, variables::menu::x + 310, render::fonts::menucontent, "Scoped Flag", variables::Visuals::esp::flag_scoped);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 490, variables::menu::x + 310, render::fonts::menucontent, "Defusing Flag", variables::Visuals::esp::flag_defusing);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 510, variables::menu::x + 310, render::fonts::menucontent, "Defuse Kit Flag", variables::Visuals::esp::flag_defusekit);

				break;

			case 1:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ENEMY", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::Visuals::chams::chamsvisible);

				menu::clr_slider(variables::menu::x + 400, variables::menu::y + 150, variables::menu::x + 400, render::fonts::menucontent, "", variables::chamopened, variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue);
				
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Normal Material", variables::colors::cMats::m_normal);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Flat Material", variables::colors::cMats::m_flat);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Blue Uber Material", variables::colors::cMats::m_ghost);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Wireframe", variables::Visuals::chams::wireframe);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Backtrack Chams", variables::Visuals::chams::backtrackchams);

				menu::clr_slider(variables::menu::x + 460, variables::menu::y + 251, variables::menu::x + 460, render::fonts::menucontent, "", variables::bchamsopened, variables::colors::cFloats::b_red, variables::colors::cFloats::b_green, variables::colors::cFloats::b_blue);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TEAMATE", true, true);
				
				break;

			case 2:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ENEMY", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::Visuals::chams::chamsxqz);
				
				menu::clr_slider(variables::menu::x + 400, variables::menu::y + 150, variables::menu::x + 400, render::fonts::menucontent, "", variables::chamopened, variables::colors::cFloats::xqz_c_red, variables::colors::cFloats::xqz_c_green, variables::colors::cFloats::xqz_c_blue);
				
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Normal Material", variables::colors::cMats::xqz_m_normal);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Flat Material", variables::colors::cMats::xqz_m_flat);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Blue Uber Material", variables::colors::cMats::xqz_m_ghost);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Wireframe", variables::Visuals::chams::xqz_wireframe);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Backtrack Chams", variables::Visuals::chams::backtrackchams);

				menu::clr_slider(variables::menu::x + 460, variables::menu::y + 251, variables::menu::x + 460, render::fonts::menucontent, "", variables::bchamsopened, variables::colors::cFloats::b_red, variables::colors::cFloats::b_green, variables::colors::cFloats::b_blue);
				
				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TEAMATE", true, true);
				
				break;
				
			case 3:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "GLOW", true, true);

				break;
				
			case 4:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "LOCALPLAYER", true, true);
				
				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Hand Chams Enabled", variables::Visuals::chams::armschams);

				menu::clr_slider(variables::menu::x + 485, variables::menu::y + 150, variables::menu::x + 485, render::fonts::menucontent, "", variables::chamopened, variables::colors::cMats::arms::c_red, variables::colors::cMats::arms::c_green, variables::colors::cMats::arms::c_blue);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Hand Chams Normal Material", variables::colors::cMats::arms::m_normal);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Hand Chams Flat Material", variables::colors::cMats::arms::m_flat);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Hand Chams Blue Uber Material", variables::colors::cMats::arms::m_crystal);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Hand Chams Wireframe", variables::Visuals::chams::hands_wireframe);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Flip Knife Hand", variables::misc::knifehandflip);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 270, variables::menu::x + 310, render::fonts::menucontent, "No Hands", variables::Visuals::chams::nohands);

				
				break;
				
			case 5:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "WORLD", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Dropped Weapon Names", variables::Visuals::esp::dropped_wep_names);

				
				break;
			}
			
			break;
			
		case 2:

			render::draw_filled_rect(variables::menu::x + 300, variables::menu::y + 70, 550, 5, color(50, 50, 50));

			menu::textbutton(variables::menu::x + 300, variables::menu::y + 50, 70, variables::menu::x + 300, render::fonts::headerfont, "General", menu::misc_current_tab, 0);			
			menu::textbutton(variables::menu::x + 385, variables::menu::y + 50, 60, variables::menu::x + 385, render::fonts::headerfont, "Config", menu::misc_current_tab, 1);

			switch (misc_current_tab)
			{
			case 0:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "GENERAL", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Dynamic Clan Tag", variables::misc::dtag);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Static Clan Tag", variables::misc::stag);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Perfect Bunnyhop", variables::misc::pbunny);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Legit Bunnyhop", variables::misc::lbunny);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Antiflash", variables::misc::antiflash);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 250, variables::menu::x + 310, render::fonts::menucontent, "Watermark", variables::misc::watermark);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 270, variables::menu::x + 310, render::fonts::menucontent, "Mouse Strafer", variables::misc::autostrafe);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 290, variables::menu::x + 310, render::fonts::menucontent, "Thirdperson", variables::misc::thirdperson);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 310, variables::menu::x + 310, render::fonts::menucontent, "Viewmodel FOV Override", variables::fov::fovOveride);
				menu::slider(variables::menu::x + 310, variables::menu::y + 340, 150, render::fonts::menucontent, "Viewmodel FOV Override Amount", variables::fov::fovamount, 0, 90);
				break;

			case 1:

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "CONFIG", true, true);

				break;
			}
			
			break;
			
		case 3:

			break;

		case 4:

			render::draw_filled_rect(variables::menu::x + 300, variables::menu::y + 70, 550, 5, color(50, 50, 50));

			menu::textbutton(variables::menu::x + 300, variables::menu::y + 50, 70, variables::menu::x + 300, render::fonts::headerfont, "Pistols", menu::rage_weapon_current_tab, 0);
			menu::textbutton(variables::menu::x + 385, variables::menu::y + 50, 130, variables::menu::x + 385, render::fonts::headerfont, "Heavy Pistols", menu::rage_weapon_current_tab, 1);
			menu::textbutton(variables::menu::x + 530, variables::menu::y + 50, 50, variables::menu::x + 530, render::fonts::headerfont, "Scout", menu::rage_weapon_current_tab, 2);
			menu::textbutton(variables::menu::x + 595, variables::menu::y + 50, 40, variables::menu::x + 595, render::fonts::headerfont, "Auto", menu::rage_weapon_current_tab, 3);
			menu::textbutton(variables::menu::x + 650, variables::menu::y + 50, 30, variables::menu::x + 650, render::fonts::headerfont, "AWP", menu::rage_weapon_current_tab, 4);
			menu::textbutton(variables::menu::x + 695, variables::menu::y + 50, 20, variables::menu::x + 695, render::fonts::headerfont, "AA", menu::rage_weapon_current_tab, 5);
			menu::textbutton(variables::menu::x + 730, variables::menu::y + 50, 50, variables::menu::x + 730, render::fonts::headerfont, "Other", menu::rage_weapon_current_tab, 6);

			switch(rage_weapon_current_tab)
			{
			case 0:

				///////////////////////////////////////////////

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TARGETING", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::rage::pistols::ragebot);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ACCURACY", true, true);

				
				break;

			case 1:

				///////////////////////////////////////////////
				///
				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TARGETING", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::rage::h_pistols::ragebot);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ACCURACY", true, true);
				break;

			case 2:

				///////////////////////////////////////////////
				///
				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TARGETING", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::rage::scout::ragebot);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ACCURACY", true, true);
				break;

			case 3:

				///////////////////////////////////////////////

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TARGETING", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::rage::autos::ragebot);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ACCURACY", true, true);
				break;

			case 4:

				///////////////////////////////////////////////

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "TARGETING", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::aimbots::rage::awp::ragebot);

				menu::group_box(variables::menu::x + 600, variables::menu::y + 100, 265, 550, render::fonts::headerfont, "ACCURACY", true, true);
				break;

			case 5:

				///////////////////////////////////////////////

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "ANTI-AIM", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Enabled", variables::antiaim::enabled);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 170, variables::menu::x + 310, render::fonts::menucontent, "Up", variables::antiaim::pUp);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 190, variables::menu::x + 310, render::fonts::menucontent, "Down", variables::antiaim::pDown);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 210, variables::menu::x + 310, render::fonts::menucontent, "Static", variables::antiaim::yStatic);
				menu::check_box(variables::menu::x + 310, variables::menu::y + 230, variables::menu::x + 310, render::fonts::menucontent, "Jitter", variables::antiaim::yJitter);

				break;

			case 6:

				///////////////////////////////////////////////

				menu::group_box(variables::menu::x + 300, variables::menu::y + 100, 550, 550, render::fonts::headerfont, "OTHER", true, true);

				menu::check_box(variables::menu::x + 310, variables::menu::y + 150, variables::menu::x + 310, render::fonts::menucontent, "Backtrack", variables::aimbots::backtrack);
				
				break;
			}
			
			break;

		case 5:

			break;
		}

		menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 30);
	}
 */