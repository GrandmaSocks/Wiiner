#include "../features.hpp"

extern hooks::draw_model_execute::fn draw_model_execute_original;

////////////////////////////////////////////////////////////////////////////////////////////////////////

void override_material(bool ignorez, bool wireframe, const color& rgba) {
	auto material = interfaces::material_system->find_material("debug/debugambientcube", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->alpha_modulate(rgba.a / 255.f);
	material->color_modulate(rgba.r / 255.f, rgba.g / 255.f, rgba.b / 255.f);
	interfaces::model_render->override_material(material);
}

void override_material_flat(bool ignorez, bool wireframe, bool flat, const color& rgba) {
	auto material = interfaces::material_system->find_material("debug/debugambientcube", TEXTURE_GROUP_MODEL);
	material->set_material_var_flag(material_var_ignorez, ignorez);
	material->set_material_var_flag(material_var_wireframe, wireframe);
	material->set_material_var_flag(material_var_flat, flat);
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
	auto material = interfaces::material_system->find_material("models/inventory_items/trophy_majors/crystal_blue", TEXTURE_GROUP_MODEL);
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

////////////////////////////////////////////////////////////////////////////////////////////////////////


void chams(i_mat_render_context* ctx, const draw_model_state_t& state, const model_render_info_t& info, matrix_t* matrix)
{
	const auto mdl = info.model;

	if (!csgo::local_player)
		return;

	if (!mdl)
		return;

	bool is_player = strstr(mdl->name, "models/player") != nullptr; /* Check if model is player */

	if (variables::Visuals::chams::chams == true) /* Chams run here */
	{
		if (variables::Visuals::chams::chamsalways == true)
		{
			variables::Visuals::chams::chamsvisible == false; /* Saves cheat from having a stroke */
			variables::Visuals::chams::chamsxqz == false;

			if (is_player)
			{
				player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

				if (!player || !player->is_alive() || player->dormant())
					return;


				if (player->team() != csgo::local_player->team())
				{
					if (variables::colors::cMats::m_normal == true)
					{
						override_material(true, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_flat)
					{
						override_material_flat(true, false, true, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_ghost)
					{
						override_material_crystal(true, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}
					
				}

			}
		}

		if (variables::Visuals::chams::chamsxqz == true)
		{
			variables::Visuals::chams::chamsvisible == false; /* Saves cheat from having a stroke */
			variables::Visuals::chams::chamsalways == false;

			if (is_player)
			{
				player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

				if (!player || !player->is_alive() || player->dormant())
					return;

				if (player->team() != csgo::local_player->team())
				{
					if (variables::colors::cMats::m_normal == true)
					{
						override_material(true, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material(false, false, color(variables::colors::cFloats::xqz_c_red, variables::colors::cFloats::xqz_c_green, variables::colors::cFloats::xqz_c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_flat)
					{
						override_material_flat(true, false, true,color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material_flat(false, false, true,color(variables::colors::cFloats::xqz_c_red, variables::colors::cFloats::xqz_c_green, variables::colors::cFloats::xqz_c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_ghost)
					{
						override_material_crystal(true, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material_crystal(false, false, color(variables::colors::cFloats::xqz_c_red, variables::colors::cFloats::xqz_c_green, variables::colors::cFloats::xqz_c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}				
				}

			}
		}

		if (variables::Visuals::chams::chamsvisible == true)
		{
			variables::Visuals::chams::chamsalways == false; /* Saves cheat from having a stroke */
			variables::Visuals::chams::chamsxqz == false;

			if (is_player)
			{
				player_t* player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(info.entity_index));

				if (!player || !player->is_alive() || player->dormant())
					return;

				if (player->team() != csgo::local_player->team())
				{
					if (variables::colors::cMats::m_normal == true)
					{
						override_material(true, false, color(0, 0, 0, 0));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material(false, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_flat == true)
					{
						override_material_flat(true, false, true,color(0, 0, 0, 0));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material_flat(false, false, true,color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}

					if (variables::colors::cMats::m_ghost == true)
					{
						override_material_crystal(true, false, color(0, 0, 0, 0));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
						override_material_crystal(false, false, color(variables::colors::cFloats::c_red, variables::colors::cFloats::c_green, variables::colors::cFloats::c_blue, 255));
						draw_model_execute_original(interfaces::model_render, 0, ctx, state, info, matrix);
					}
					
				}
			}
		}

	}

	if (variables::Visuals::chams::armschams == true) /* Chams for arms */
	{
		bool arms = strstr(mdl->name, "models/arms") != nullptr; /* Check model is arms */

		if (arms)
		{
			if (csgo::local_player && csgo::local_player->is_alive())  /* Only overide localplayers arms */
			{
				if (variables::colors::cMats::arms::m_normal == true)
				{
					override_material(true, false, color(variables::colors::cMats::arms::c_red, variables::colors::cMats::arms::c_green, variables::colors::cMats::arms::c_blue, 255));
				}

				if (variables::colors::cMats::arms::m_flat == true)
				{
					override_material_flat(true, false, true, color(variables::colors::cMats::arms::c_red, variables::colors::cMats::arms::c_green, variables::colors::cMats::arms::c_blue, 255));
				}

				if (variables::colors::cMats::arms::m_crystal == true)
				{
					override_material_crystal(true, false, color(variables::colors::cMats::arms::c_red, variables::colors::cMats::arms::c_green, variables::colors::cMats::arms::c_blue, 255));
				}
				
			}
		}

	}

	if (variables::Visuals::chams::nohands == true) /* No hands, pretty self explanitory */
	{
		bool arms = strstr(mdl->name, "models/arms") != nullptr; /* Same thing arms chams does */

		if (arms)
		{
			if (csgo::local_player && csgo::local_player->is_alive())
			{
				override_material(true, false, color(255, 255, 255, 0));
			}
		}

	}
}