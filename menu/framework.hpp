#pragma once
#include "../../dependencies/utilities/csgo.hpp"


#pragma once
#include "../../dependencies/utilities/csgo.hpp"


namespace menu_framework {
    void group_box(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string string, bool show_label);

    void tab(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, unsigned long font, const std::string, std::int32_t& tab, std::int32_t count, bool show_outline);

    void check_box(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value);

    void slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, float& value, float min_value, float max_value);
    void menu_movement(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h);

    void combo_box(std::int32_t x, std::int32_t y, std::int32_t position, std::int32_t height, unsigned long font, std::string string, bool& isopened);

    void clr_slider(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, float& value, float min_value, float max_value, color clr);

    void textbutton(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, bool& value);

    void keybind(std::int32_t x, std::int32_t y, std::int32_t position, unsigned long font, const std::string string, int& value);

    inline bool should_drag = false;
    inline bool should_move = false;

	constexpr std::string_view keys_list[]{

			   "Error", "Left Mouse", "Right Mouse", "Break", "Middle Mouse", "Mouse 4", "Mouse 5",
			   "Error", "Backspace", "TAB", "Error", "Error", "Error", "ENTER", "Error", "Error", "SHIFT",
			   "CTRL", "ALT", "PAUSE", "CAPS LOCK", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "SPACEBAR", "PG UP", "PG DOWN", "END", "HOME", "Left",
			   "Up", "Right", "Down", "Error", "Print", "Error", "Print Screen", "Insert", "Delete", "Error", "0", "1",
			   "2", "3", "4", "5", "6", "7", "8", "9", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
			   "V", "W", "X", "Y", "Z", "Left Windows", "Right Windows", "Error", "Error", "Error", "NUM 0", "NUM 1",
			   "NUM 2", "NUM 3", "NUM 4", "NUM 5", "NUM 6", "NUM 7", "NUM 8", "NUM 9", "*", "+", "_", "-", ".", "/", "F1", "F2", "F3",
			   "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "F16", "F17", "F18", "F19", "F20", "F21",
			   "F22", "F23", "F24", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "NUM LOCK", "SCROLL LOCK", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "LSHIFT", "RSHIFT", "LCONTROL",
			   "RCONTROL", "LMENU", "RMENU", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Next Track", "Previous Track", "Stop", "Play/Pause", "Error", "Error",
			   "Error", "Error", "Error", "Error", ";", "+", ",", "-", ".", "/?", "~", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "[{", "\\|", "}]", "'\"", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
			   "Error", "Error"
	};
	
};
