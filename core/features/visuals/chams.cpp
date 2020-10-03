#include "../features.hpp"

extern hooks::draw_model_execute::fn draw_model_execute_original;

void override_material(bool ignorez, bool wireframe, const color& rgba) {
	auto material = interfaces::material_system->find_material("debug/debugambientcube", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->alpha_modulate(rgba.a / 255.f);
	material->color_modulate(rgba.r / 255.f, rgba.g / 255.f, rgba.b / 255.f);
	interfaces::model_render->override_material(material);
}

void override_material_gloss(bool ignorez, bool wireframe, const color& rgba) {
	auto material = interfaces::material_system->find_material("models/inventory_items/trophy_majors/gloss", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->alpha_modulate(rgba.a / 255.f);
	material->color_modulate(rgba.r / 255.f, rgba.g / 255.f, rgba.b / 255.f);
	interfaces::model_render->override_material(material);
}

void override_material_crystal(bool ignorez, bool wireframe, const color& rgba) {
	auto material = interfaces::material_system->find_material("models/inventory_items/trophy_majors/crystal_clear.vmt", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->alpha_modulate(rgba.a / 255.f);
	material->color_modulate(rgba.r / 255.f, rgba.g / 255.f, rgba.b / 255.f);
	interfaces::model_render->override_material(material);
}

void noarms(bool ignorez, bool wireframe, const color& rgba) {
	auto material = interfaces::material_system->find_material("models/inventory_items/trophy_majors/crystal_clear.vmt", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->alpha_modulate(rgba.a / 255.f);
	material->color_modulate(rgba.r / 255.f, rgba.g / 255.f, rgba.b / 255.f);
	interfaces::model_render->override_material(material);
}

void chams(i_mat_render_context* ctx, const draw_model_state_t& state, const model_render_info_t& info, matrix_t* matrix)
{
	const auto mdl = info.model;

	if (!csgo::local_player)
		return;

	if (!mdl)
		return;

	bool is_player = strstr(mdl->name, "models/player") != nullptr;

	if (variables::chams == 1)
	{
		if (is_player)
		{
			player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

			if (!player || !player->is_alive() || player->dormant())
				return;


			if (player->team() != csgo::local_player->team())
			{
				override_material(true, false, color(255, 0, 0, 255));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
			}

		}
	}

	if (variables::chams == 2)
	{
		if (is_player)
		{
			player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

			if (!player || !player->is_alive() || player->dormant())
				return;

			if (player->team() != csgo::local_player->team())
			{
				override_material_gloss(true, false, color(255, 0, 0, 255));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
			}

		}
	}

	if (variables::chams == 3)
	{
		if (is_player)
		{
			player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

			if (!player || !player->is_alive() || player->dormant())
				return;

			if (player->team() != csgo::local_player->team())
			{
				override_material(true, false, color(255, 0, 0));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
				override_material(false, false, color(0, 0, 255));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
			}

		}
	}

	if (variables::chams == 4)
	{
		if (is_player)
		{
			player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

			if (!player || !player->is_alive() || player->dormant())
				return;

			if (player->team() != csgo::local_player->team())
			{
				override_material(true, false, color(0, 0, 0, 0));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
				override_material(false, false, color(255, 0, 0));
				draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
			}

		}
	}

	if (variables::chams == 0)
	{

	}


	if (variables::arms == 1)
	{
		bool arms = strstr(mdl->name, "models/arms") != nullptr;

		if (arms)
		{
			if (csgo::local_player && csgo::local_player->is_alive())
			{
				override_material(true, false, color(255, 255, 255, 255));
			}
		}

	}

	if (variables::arms == 2)
	{
		bool arms = strstr(mdl->name, "models/arms") != nullptr;

		if (arms)
		{
			if (csgo::local_player && csgo::local_player->is_alive())
			{
				override_material(true, false, color(255, 255, 255, 0));
			}
		}

	}

	if (variables::arms == 0)
	{

	}

}