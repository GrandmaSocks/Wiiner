#include "framework.hpp"

POINT cursor;
POINT cursor_corrected;

void menu_framework::group_box(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, bool show_label) {
	//groupbox background
	render::draw_filled_rect(x, y, w, h, color(25, 25, 25, 255));

	//groupbox outline
	render::draw_rect(x, y, w, h, color(45, 45, 45, 255));

	//groupbox label
	if (show_label)
		render::text(x + 14, y - 6, font, string, false, color::white());
}

void menu_framework::tab(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, std::int32_t& tab, std::int32_t count, bool show_outline) {
	GetCursorPos(&cursor);

	if ((cursor.x > x) && (cursor.x < x + w) && (cursor.y > y) && (cursor.y < y + h) && (GetAsyncKeyState(VK_LBUTTON) & 1))
		tab = count;

	//tab background
	if (show_outline)
		render::draw_rect(x, y, w, h, tab == count ? variables::colors::menu::c_menu : color(25, 25, 25, 255));

	//tab label
	render::text(x - render::get_text_size(font, string).x / 2 + 50, y + h / 2 - 8, font, string, false, show_outline ? color::white() : tab == count ? variables::colors::menu::c_menu : color::white());
}

void menu_framework::check_box(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value) {
	GetCursorPos(&cursor);

	int w = 10, h = 10;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		value = !value;

	if (value == false)
	{
		render::draw_filled_rect(position, y, w, h, color(36, 36, 36, 255));
	}
	else
	{
		render::draw_filled_rect(position, y, w, h, variables::colors::menu::c_menu);
	}

	//checkbox label
	render::text(x + 2, y - 1, font, string, false, color::white());
}

void menu_framework::slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, float& value, float min_value, float max_value) {
	GetCursorPos(&cursor);

	int ix = x;
	int yi = y + 9;

	if ((cursor.x > ix) && (cursor.x < ix + position) && (cursor.y > yi) && (cursor.y < yi + 6) && (GetAsyncKeyState(VK_LBUTTON)))
		value = (cursor.x - ix) / (float(position) / float(max_value));

	//slider background
	render::draw_filled_rect(ix, yi, position, 6, color(36, 36, 36, 255));
	render::draw_filled_rect(ix, yi, value * (float(position) / float(max_value)), 6, variables::colors::menu::c_menu);

	render::text(ix + value * (float(position) / float(max_value)), yi, font, (std::stringstream{ } << std::setprecision(3) << value).str(), false, color::white());

	//slider label
	render::text(x + 2, y - 7, font, string, false, color::white());

}

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

void menu_framework::combo_box(std::int32_t x, std::int32_t y, std::int32_t position,  std::int32_t height, unsigned long font, std::string string, bool& isopened)
{
	GetCursorPos(&cursor);

	int w = 200, h = 20;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		isopened = !isopened;

	if (isopened == false)
	{
		render::draw_filled_rect(position, y, w, h, isopened ? variables::colors::menu::c_menu : color(36, 36, 36, 255));
		render::draw_rect(position - 1, y - 1, w + 1, h + 1, isopened ? color(52, 134, 235, 255) : variables::colors::menu::c_menu);
		render::text(x - 10, y + 4, font, string, false, color::white());
	}

	if (isopened == true)
	{
		int w = 200, h = height;

		render::draw_filled_rect(position, y, w, h, color(36, 36, 36, 255));
		render::draw_rect(position - 1, y - 1, w + 1, h + 1, isopened ? variables::colors::menu::c_menu : color(36, 36, 36, 255));
		render::text(x - 10, y + 4, font, string, false, color::white());
	}

}

void menu_framework::clr_slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, float& value, float min_value, float max_value, int rgb)
{

	GetCursorPos(&cursor);

	int ix = x;
	int yi = y + 9;

	if ((cursor.x > ix) && (cursor.x < ix + position) && (cursor.y > yi) && (cursor.y < yi + 6) && (GetAsyncKeyState(VK_LBUTTON)))
		value = (cursor.x - ix) / (float(position) / float(max_value));

	//slider background

	if (rgb == 1)
	{
		render::draw_filled_rect(ix, yi, position, 6, color(value, 0, 0, 255));
	}

	if (rgb == 2)
	{
		render::draw_filled_rect(ix, yi, position, 6, color(0, value, 0, 255));
	}

	if (rgb == 3)
	{
		render::draw_filled_rect(ix, yi, position, 6, color(0, 0, value, 255));
	}
	
	render::text(ix + value * (float(position) / float(max_value)), yi, font, (std::stringstream{ } << std::setprecision(3) << value).str(), false, color::white());

	//slider label
	render::text(x + 2, y - 7, font, string, false, color::white());
}

void menu_framework::textbutton(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value) {
	GetCursorPos(&cursor);

	int w = 50, h = 10;

	if ((cursor.x > position) && (cursor.x < position + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON) & 1)
		value = !value;

	// label
	render::text(x, y, font, string, false, value ? variables::colors::menu::c_menu : color::white());
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