#include "../../dependencies/utilities/csgo.hpp"
#include "../features/features.hpp"
#include "../features/misc/engine_prediction.hpp"
#include "../menu/menu.hpp"


hooks::create_move::fn create_move_original = nullptr;
hooks::paint_traverse::fn paint_traverse_original = nullptr;
hooks::frame_stage_notify::fn frame_stage_notify_original = nullptr;
hooks::draw_model_execute::fn draw_model_execute_original = nullptr;
hooks::sv_cheats::fn sv_cheats_original = nullptr;

bool hooks::initialize() {
	const auto create_move_target = reinterpret_cast<void*>(get_virtual(interfaces::clientmode, 24));
	const auto paint_traverse_target = reinterpret_cast<void*>(get_virtual(interfaces::panel, 41));
	const auto scene_end = reinterpret_cast<void*>(get_virtual(interfaces::render_view, 41));
	const auto frame_stage_notify = reinterpret_cast<void*>(get_virtual(interfaces::client, 37));
	const auto draw_model_execute = reinterpret_cast<void*>(get_virtual(interfaces::model_render, 21));
	const auto sv_cheats = reinterpret_cast<void*>(get_virtual(interfaces::console->get_convar("sv_cheats"), 13));

	if (MH_Initialize() != MH_OK)
		throw std::runtime_error("failed to initialize MH_Initialize.");

	if (MH_CreateHook(create_move_target, &create_move::hook, reinterpret_cast<void**>(&create_move_original)) != MH_OK)
		throw std::runtime_error("failed to initialize create_move. (outdated index?)");

	if (MH_CreateHook(paint_traverse_target, &paint_traverse::hook, reinterpret_cast<void**>(&paint_traverse_original)) != MH_OK)
		throw std::runtime_error("failed to initialize paint_traverse. (outdated index?)");

	if (MH_CreateHook(frame_stage_notify, &frame_stage_notify::hook, reinterpret_cast<void**>(&frame_stage_notify_original)) != MH_OK)
		throw std::runtime_error("failed to initialize frame_stage_notify. (outdated index?)");

	if (MH_CreateHook(draw_model_execute, &draw_model_execute::hook, reinterpret_cast<void**>(&draw_model_execute_original)) != MH_OK)
		throw std::runtime_error("failed to initialize draw_model_execute. (outdated index?)");

	if (MH_CreateHook(sv_cheats, &sv_cheats::hook, reinterpret_cast<void**>(&sv_cheats_original)) != MH_OK)
		throw std::runtime_error("failed to initialize sv_cheats. (outdated index?)");

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
		throw std::runtime_error("failed to enable hooks.");

	console::log("[setup] hooks initialized!\n");

	return true;
}

void hooks::release() {
	MH_Uninitialize();

	MH_DisableHook(MH_ALL_HOOKS);
}

bool __stdcall hooks::create_move::hook(float input_sample_frametime, c_usercmd* cmd) {
	create_move_original(input_sample_frametime, cmd);

	if (!cmd || !cmd->command_number)
		return false;

	csgo::local_player = static_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));

	uintptr_t* frame_pointer;
	__asm mov frame_pointer, ebp;
	bool& send_packet = *reinterpret_cast<bool*>(*frame_pointer - 0x1C);

	auto old_viewangles = cmd->viewangles;
	auto old_forwardmove = cmd->forwardmove;
	auto old_sidemove = cmd->sidemove;

	misc::movement::bunny_hop(cmd);
	rcs(cmd);
	aimbot(cmd);
	clantag();
	ragebot(cmd);
	triggerbot(cmd);
	
	player_t* entity;

	antiaim(cmd);
	
	prediction::start(cmd); {

		

	} prediction::end();

	math::correct_movement(old_viewangles, cmd, old_forwardmove, old_sidemove);

	cmd->forwardmove = std::clamp(cmd->forwardmove, -450.0f, 450.0f);
	cmd->sidemove = std::clamp(cmd->sidemove, -450.0f, 450.0f);
	cmd->upmove = std::clamp(cmd->upmove, -320.0f, 320.0f);

	cmd->viewangles.normalize();
	cmd->viewangles.x = std::clamp(cmd->viewangles.x, -89.0f, 89.0f);
	cmd->viewangles.y = std::clamp(cmd->viewangles.y, -180.0f, 180.0f);
	cmd->viewangles.z = 0.0f;
	
	return false;
}

void __stdcall hooks::paint_traverse::hook(unsigned int panel, bool force_repaint, bool allow_force) {
	auto panel_to_draw = fnv::hash(interfaces::panel->get_panel_name(panel));

	switch (panel_to_draw) {
	case fnv::hash("MatSystemTopPanel"):

		render::draw_text_string(20, 20, render::fonts::tabfont, "Debug", false, color(255, 255, 0));

		antiflash();
		esp();
		boneesp();
		crosshair();
		watermark();
		menu::toggle();
 		menu::render();;

		
		break;

	case fnv::hash("FocusOverlayPanel"):
		
		interfaces::panel->set_keyboard_input_enabled(panel, variables::menu::opened);
		interfaces::panel->set_mouse_input_enabled(panel, variables::menu::opened);

		break;
	}

	paint_traverse_original(interfaces::panel, panel, force_repaint, allow_force);
}

void __stdcall hooks::frame_stage_notify::hook(client_frame_stage_t frame_stage) {
	const auto local = static_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	static auto set_interpolation_flags = [](player_t* e, int flag) {
		const auto var_map = (uintptr_t)e + 36;
		const auto sz_var_map = *(int*)(var_map + 20);
		for (auto index = 0; index < sz_var_map; index++)
			*(uintptr_t*)((*(uintptr_t*)var_map) + index * 12) = flag;
	};
	switch (frame_stage) {
	case FRAME_UNDEFINED:
		break;
	case FRAME_START:
		break;
	case FRAME_NET_UPDATE_START:
		break;
	case FRAME_NET_UPDATE_POSTDATAUPDATE_START:
		break;
	case FRAME_NET_UPDATE_POSTDATAUPDATE_END:
		break;
	case FRAME_NET_UPDATE_END:
		break;
	case FRAME_RENDER_START:
		if (local)
		{
			thirdperson();
		}
		break;
	case FRAME_RENDER_END:
		break;
	default: break;
	}
	frame_stage_notify_original(interfaces::client, frame_stage);
}

void __fastcall hooks::draw_model_execute::hook(void* _this, int edx, i_mat_render_context* ctx, const draw_model_state_t& state, const model_render_info_t& info, matrix_t* matrix) {
	if (interfaces::engine->is_in_game() && interfaces::engine->is_connected() && csgo::local_player) {
		const auto mdl = info.model;
		if (!mdl)
			return;

		bool is_player = strstr(mdl->name, "models/player") != nullptr;

		if (!interfaces::studio_render->is_forced() && is_player) {
			chams(ctx, state, info, matrix);
			draw_model_execute_original(_this, edx, ctx, state, info, matrix);
			interfaces::model_render->override_material(nullptr);
		}
		else if (!interfaces::model_render->is_forced() && !is_player) {
			chams(ctx, state, info, matrix);
			draw_model_execute_original(_this, edx, ctx, state, info, matrix);
			interfaces::model_render->override_material(nullptr);
		}
		else {
			draw_model_execute_original(_this, edx, ctx, state, info, matrix);
		}
	}
}

bool __fastcall hooks::sv_cheats::hook(PVOID convar, int edx) {
	static auto cam_think = utilities::pattern_scan("client.dll", sig_cam_think);

	if (!convar)
		return false;

	if ((_ReturnAddress()) == cam_think)
		return true;
	else
		return sv_cheats_original(convar);
}