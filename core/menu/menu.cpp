#include "menu.hpp"

void featureToggle() // this had to go somewhere
{
	if (GetAsyncKeyState(VK_F7) & 1)
	{
		variables::bhopToggle = !variables::bhopToggle;
	}
	if (GetAsyncKeyState(VK_F8) & 1)
	{
		variables::rcs = !variables::rcs;
	}
	if (GetAsyncKeyState(VK_F9) & 1)
	{
		variables::espToggle = !variables::espToggle;
	}
	if (GetAsyncKeyState(VK_UP) & 1)
	{
		variables::boneToggle++;

		if (variables::boneToggle > 2)
		{
			variables::boneToggle = 0;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 1)
	{
		variables::hvhmode = !variables::hvhmode;
	}
	if (GetAsyncKeyState(VK_LEFT) & 1)
	{
		variables::thirdperson = !variables::thirdperson;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 1)
	{
		variables::aimbotToggle = !variables::aimbotToggle;
	}
	if (GetAsyncKeyState(VK_OEM_MINUS) & 1)
	{
		variables::chams++;

		if (variables::chams > 5)
		{
			variables::chams = 0;
		}
	}
	if (GetAsyncKeyState(VK_MBUTTON) & 1)
	{
		variables::thirdperson = !variables::thirdperson;
	}
	if (GetAsyncKeyState(VK_OEM_COMMA) & 1)
	{
		variables::clantag++;

		if (variables::clantag > 2)
		{
			variables::clantag = 0;
		}
	}
	if (GetAsyncKeyState(VK_OEM_PERIOD) & 1)
	{
		variables::crosshair++;

		if (variables::crosshair > 1)
		{
			variables::crosshair = 0;
		}
	}
	if (GetAsyncKeyState(VK_OEM_PLUS) & 1)
	{
		variables::arms++;

		if (variables::arms > 4)
		{
			variables::arms = 0;
		}
	}
	if (GetAsyncKeyState(VK_F11) & 1)
	{
		variables::antiflash++;

		if (variables::antiflash > 2)
		{
			variables::antiflash = 0;
		}
	}
	if (GetAsyncKeyState(VK_RSHIFT) & 1)
	{
		variables::antiaim++;

		if (variables::antiaim > 4)
		{
			variables::antiaim = 0;
		}

	}
}

void menu::render()
{
	featureToggle();

	#ifdef NDEBUG
		render::text(200, 10, render::fonts::watermark_font, "WiinerV2 | Welcome GrandmaSocks | Release 2.0", false, color(255, 255, 0));
	#endif

	#ifdef _DEBUG
		render::text(200, 10, render::fonts::watermark_font, "WiinerV2 | Welcome GrandmaSocks | Debug Build" , false, color(255, 255, 0));
	#endif

	if (variables::menu::opened == true)
	{
		if (variables::bhopToggle == true)
		{
			render::text(200, 25, render::fonts::watermark_font, "Bhop", false, color(120, 255, 255, 255));
		}
		if (variables::bhopToggle == false)
		{
			render::text(200, 25, render::fonts::watermark_font, "Bhop", false, color::white());
		}
		if (variables::rcs == true)
		{
			render::text(200, 40, render::fonts::watermark_font, "RCS", false, color(120, 255, 255, 255));
		}
		if (variables::rcs == false)
		{
			render::text(200, 40, render::fonts::watermark_font, "RCS", false, color::white());
		}
		if (variables::espToggle == true)
		{
			render::text(200, 55, render::fonts::watermark_font, "ESP", false, color(120, 255, 255, 255));
		}
		if (variables::espToggle == false)
		{
			render::text(200, 55, render::fonts::watermark_font, "ESP", false, color::white());
		}
		if (variables::boneToggle == 1)
		{
			render::text(233, 25, render::fonts::watermark_font, "BoneESP", false, color(120, 255, 255, 255));
		}
		if (variables::boneToggle == 2)
		{
			render::text(233, 25, render::fonts::watermark_font, "BoneESP", false, color(255, 50, 255, 255));
		}
		if (variables::boneToggle == 0)
		{
			render::text(233, 25, render::fonts::watermark_font, "BoneESP", false, color::white());
		}
		if (variables::hvhmode == false)
		{
			render::text(233, 40, render::fonts::watermark_font, "HVH", false, color::white());
		}
		if (variables::hvhmode == true)
		{
			render::text(233, 40, render::fonts::watermark_font, "HVH", false, color(120, 255, 255, 255));
		}
		if (variables::aimbotToggle == false)
		{
			render::text(233, 55, render::fonts::watermark_font, "Aimbot", false, color::white());
		}
		if (variables::aimbotToggle == true)
		{
			render::text(233, 55, render::fonts::watermark_font, "Aimbot", false, color(120, 255, 255, 255));
		}
		if (variables::antiflash == 0)
		{
			render::text(283, 25, render::fonts::watermark_font, "Antiflash", false, color::white());
		}
		if (variables::antiflash == 1)
		{
			render::text(283, 25, render::fonts::watermark_font, "Antiflash", false, color(120, 255, 255, 255));
		}
		if (variables::antiflash == 2)
		{
			render::text(283, 25, render::fonts::watermark_font, "Antiflash", false, color(255, 50, 255, 255));
		}
		if (variables::chams == 1)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color(120, 255, 255, 255));
		}
		if (variables::chams == 2)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color(255, 50, 255, 255));
		}
		if (variables::chams == 3)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color(255, 0, 0, 255));
		}
		if (variables::chams == 4)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color(255, 255, 0, 255));
		}
		if (variables::chams == 5)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color(50, 255, 50, 255));
		}
		if (variables::chams == 0)
		{
			render::text(283, 40, render::fonts::watermark_font, "Chams", false, color::white());
		}
		if (variables::thirdperson == false)
		{
			render::text(283, 55, render::fonts::watermark_font, "3rdPerson", false, color::white());
		}
		if (variables::thirdperson == true)
		{
			render::text(283, 55, render::fonts::watermark_font, "3rdPerson", false, color(120, 255, 255, 255));
		}
		if (variables::clantag == 1)
		{
			render::text(333, 25, render::fonts::watermark_font, "Clantag", false, color(120, 255, 255, 255));
		}
		if (variables::clantag == 2)
		{
			render::text(333, 25, render::fonts::watermark_font, "Clantag", false, color(255, 50, 255, 255));
		}
		if (variables::clantag == 0)
		{
			render::text(333, 25, render::fonts::watermark_font, "Clantag", false, color::white());
		}
		if (variables::crosshair == 1)
		{
			render::text(333, 40, render::fonts::watermark_font, "Crosshair", false, color(120, 255, 255, 255));
		}
		if (variables::crosshair == 0)
		{
			render::text(333, 40, render::fonts::watermark_font, "Crosshair", false, color::white());
		}
		if (variables::arms == 0)
		{
			render::text(333, 55, render::fonts::watermark_font, "Arms", false, color::white());
		}
		if (variables::arms == 1)
		{
			render::text(333, 55, render::fonts::watermark_font, "Arms", false, color(120, 255, 255, 255));
		}
		if (variables::arms == 2)
		{
			render::text(333, 55, render::fonts::watermark_font, "Arms", false, color(255, 50, 255, 255));
		}
		if (variables::arms == 3)
		{
			render::text(333, 55, render::fonts::watermark_font, "Arms", false, color(255, 0, 0, 255));
		}
		if (variables::arms == 4)
		{
			render::text(333, 55, render::fonts::watermark_font, "Arms", false, color(255, 255, 0, 255));
		}
		if (variables::antiaim == 1)
		{
			render::text(383, 25, render::fonts::watermark_font, "AA", false, color(120, 255, 255, 255));
		}
		if (variables::antiaim == 2)
		{
			render::text(383, 25, render::fonts::watermark_font, "AA", false, color(255, 50, 255, 255));
		}
		if (variables::antiaim == 3)
		{
			render::text(383, 25, render::fonts::watermark_font, "AA", false, color(255, 0, 0, 255));
		}
		if (variables::antiaim == 4)
		{
			render::text(383, 25, render::fonts::watermark_font, "AA", false, color(255, 255, 0, 255));
		}
		if (variables::antiaim == 0)
		{
			render::text(383, 25, render::fonts::watermark_font, "AA", false, color(255, 255, 255, 255));
		}
	}

}


void menu::toggle()
{
	if (GetAsyncKeyState(VK_F6) & 1)
		variables::menu::opened = !variables::menu::opened;
}
