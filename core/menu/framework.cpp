#include "framework.hpp"

POINT cursor;
POINT cursor_corrected;

void menu_framework::menu_movement(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h) {
	GetCursorPos(&cursor);

	if (GetAsyncKeyState(VK_LBUTTON) < 0 && (cursor.x > x && cursor.x < x + w && cursor.y > y && cursor.y < y + h)) {
		should_drag = true;

		if (!should_move) {
			cursor_corrected.x = cursor.x - x;
			cursor_corrected.y = cursor.y - y;
			should_move = true;
		}
	}

	if (should_drag) {
		x = cursor.x - cursor_corrected.x;
		y = cursor.y - cursor_corrected.y;
	}

	if (GetAsyncKeyState(VK_LBUTTON) == 0) {
		should_drag = false;
		should_move = false;
	}
}

void menu_framework::keybind(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, int& value)
{
	GetCursorPos(&cursor);

	int w = 15, h = 10;

	bool activate = true;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
	{
		activate = !activate;
	}

	if (activate == true) /* Where we run our code */
	{
		w = 60;
		render::draw_filled_rect(position, y, w, h, color(36, 36, 36, 255));
		render::draw_rect(position - 1, y - 1, w + 1, h + 1, variables::colors::menu::c_menu);

		for (int i = 0; i < 256; i++)
		{
			if (GetAsyncKeyState(i))
			{
				if(menu_framework::keys_list[i] != "Error")
				{
					value = i;
					std::string key = std::to_string(GetAsyncKeyState(i));
					render::text(x + 6, y - 1, font, key, false, value ? color(255, 255, 255, 255) : color::white());
					activate = false;
				}
			}
		}
	}
}

/*
 	else
	{
		render::draw_filled_rect(position, y, w, h, color(36, 36, 36, 255));
		render::draw_rect(position - 1, y - 1, w + 1, h + 1, color(52, 134, 235, 255));
		render::text(x + 6, y - 1, font, "-", false, value ? color(255, 255, 255, 255) : color::white());
	}
 */

void menu::create(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg, color header_text, color header_line, const std::string& name) {
	render::draw_filled_rect(x, y, w, h, bg);
	render::draw_rect(x + .5, y - 1, w - .5, h + .5, color(125, 125, 125));
}

void menu::tab(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, std::string icon, std::int32_t& tab, std::int32_t count, bool show_outline)
{
	GetCursorPos(&cursor);
	
	if ((cursor.x > x) && (cursor.x < x + w + 75) && (cursor.y > y) && (cursor.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 1))
	{
		tab = count;
	}
	//tab background
	if (show_outline)
		render::draw_rect(x, y, w, h, tab == count ? variables::colors::menu::c_menu : color(25, 25, 25, 255));

	//tab label
	if (count == 2)
	{
		render::text(x - render::get_text_size(font, string).x / 2 + 30 - 8, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
		render::text(x - render::get_text_size(font, string).x / 2 + 55, y + h / 2 - 8, font, string, false, color::white());
	}
	else
	{
		if (count == 4)
		{
			render::text(x - render::get_text_size(font, string).x / 2 + 26, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 56, y + h / 2 - 8, font, string, false, color::white());
		}
		else
		{
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());;
		}
	}
	
	
	if ((cursor.x > x) && (cursor.x < x + w + 130) && (cursor.y > y) && (cursor.y < y + h))
	{
		
		if (count == 1)
		{
			render::draw_filled_rect(x - 10, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}
		
		else
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}
		
		if (count == 2)
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30 - 8, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 55, y + h / 2 - 8, font, string, false, color::white());
		}

		if (count == 5)
		{
			render::draw_filled_rect(x - 30, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}

		if (count == 4)
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 26, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 56, y + h / 2 - 8, font, string, false, color::white());
		}
	}

	if (tab == count)
	{

		if (count == 1)
		{
			render::draw_filled_rect(x - 10, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}
		
		else
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}

		if (count == 2)
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30 - 8, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 55, y + h / 2 - 8, font, string, false, color::white());
		}

		if (count == 5)
		{
			render::draw_filled_rect(x - 30, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 30, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 60, y + h / 2 - 8, font, string, false, color::white());
		}

		if (count == 4)
		{
			render::draw_filled_rect(x, y + 2, w + 130, h, color(52, 134, 235, 255));
			render::text(x - render::get_text_size(font, string).x / 2 + 26, y + h / 2 - 8, render::fonts::tabicons, icon, false, color::white());
			render::text(x - render::get_text_size(font, string).x / 2 + 56, y + h / 2 - 8, font, string, false, color::white());
		}
	}
	
}

void menu::group_box(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, bool show_label, bool outline)
{
	render::draw_filled_rect(x, y, w, h, color(25, 25, 25, 255));

	//groupbox outline

	if (outline)
	{
		render::draw_rect(x, y, w, h, color(125, 125, 125));
	}

	//groupbox label
	if (show_label)
	{
		render::draw_filled_rect(x, y, w, 35, color(25, 25, 25, 255));
		render::draw_rect(x, y, w, 35, color(125, 125, 125));
		render::text(x + 14, y + 8, font, string, false, color::white());
	}
}

void menu::textbutton(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t position, unsigned long font, const std::string string, std::int32_t& section, std::int32_t count)
{
	GetCursorPos(&cursor);

	int h = 10;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		section = count;

	// label
	render::text(x, y, font, string, false, color::white());

	if (section == count)
	{
		render::draw_filled_rect(x, y + 20, w, 5, color(52, 134, 235));
	}

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h))
	{
		render::draw_filled_rect(x, y + 20, w, 5, color(52, 134, 235));
	}
	
}

void menu::check_box(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value)
{
	GetCursorPos(&cursor);

	int w = 15, h = 15;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		value = !value;

	if (value == false)
	{
		render::draw_filled_rect(position, y, w, h, color(36, 36, 36, 255));
		render::draw_rect(position, y, w, h, color(125, 125, 125));
	}
	else
	{
		render::draw_filled_rect(position, y, w, h, color(52, 134, 235));
		render::draw_rect(position, y, w, h, color(125, 125, 125));
	}

	//checkbox label
	render::text(x + 19, y - 2, font, string, false, color::white());
}

void menu::slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, float& value, float min_value, float max_value)
{
	GetCursorPos(&cursor);

	int ix = x;
	int yi = y + 9;

	if ((cursor.x > ix) && (cursor.x < ix + position) && (cursor.y > yi) && (cursor.y < yi + 6) && (GetAsyncKeyState(VK_LBUTTON)))
		value = (cursor.x - ix) / (float(position) / float(max_value));

	//slider background
	render::draw_filled_rect(ix, yi, position, 12, color(36, 36, 36, 255));
	render::draw_filled_rect(ix, yi, value * (float(position) / float(max_value)), 12, variables::colors::menu::c_menu);

	render::text(x + 170, yi - 3, font, (std::stringstream{ } << std::setprecision(3) << value).str(), false, color::white());

	render::draw_filled_rect(ix + value * (float(position) / float(max_value)), yi, 15, 12, color(255, 255, 255));
	
	//slider label
	render::text(x - 1, y - 8, font, string, false, color::white());
}

void menu::clr_slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& opened, float& r, float& g, float& b)
{
	GetCursorPos(&cursor);

	int w = 15, h = 10;

	render::draw_filled_rect(x, y + 2, w, h, color(r, g, b));
	render::draw_rect(x, y + 2, w, h, color(125, 125, 125));
	
	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		opened = !opened;

	if (opened == true)
	{
		render::draw_filled_rect(x + 520, y, 400, 350, color(25, 25, 25, 255));
		render::draw_rect(x + 520, y, 400, 350, color(125, 125, 125, 255));

		render::draw_filled_rect(x +  640, y + 90, 150, 150, color(r, g, b, 255));
		render::draw_rect(x + 640, y + 90, 150, 150, color(r, g, b, 255));

		menu::slider(x + 640, y + 240, 140, render::fonts::menucontent, "", r, 0, 255);
		menu::slider(x + 640, y + 260, 140, render::fonts::menucontent, "", g, 0, 255);
		menu::slider(x + 640, y + 280, 140, render::fonts::menucontent, "", b, 0, 255);

		if ((cursor.x < position) && (cursor.x > position + w) && (cursor.y < y) && (cursor.y > y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		{
			opened = false;
		}

	}

	else
	{
		
	}
	
}
