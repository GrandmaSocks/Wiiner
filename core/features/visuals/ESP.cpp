#include "../features.hpp"
#include "../rage/backtrack.h"

void esp() /* I just draw all player esp in this function because why not */
{
	if (variables::Visuals::esp::espToggle == true && interfaces::engine->is_in_game()) /* Where esp is getting drawn */
	{
		if (interfaces::engine->is_in_game() == false)
			return;

		if (csgo::local_player == nullptr)
			return;
		
		for (int iPlayer = 0; iPlayer < interfaces::globals->max_clients; iPlayer++) /* Player loop */
		{

			if (interfaces::engine->is_in_game() == false)
				return;

			if (csgo::local_player == nullptr)
				return;
			
			auto pCSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(iPlayer));
			if (!pCSPlayer)
				continue;
			if (pCSPlayer == csgo::local_player)
				continue;
			if (pCSPlayer->dormant())
				continue;
			if (!(pCSPlayer->is_alive() && pCSPlayer->health() > 0))
				continue;

			vec3_t vecFoot;
			vec2_t vecScreen;
			vec2_t vecHeadScreen;
			vecFoot = pCSPlayer->origin();
			if (!(math::world_to_screen(vecFoot, vecScreen)))
				continue;

			vecFoot.z += 72.f;
			if (!(math::world_to_screen(vecFoot, vecHeadScreen)))
				continue;

			player_info_t playerinfo;
			interfaces::engine->get_player_info(iPlayer, &playerinfo);

			float alpha = pCSPlayer->flash_alpha();
			float time = pCSPlayer->flash_duration(); // need to make these update
			std::string flashtime = std::to_string(time);
			std::string flashAlpha = std::to_string(alpha);

			int h = vecScreen.y - vecHeadScreen.y;
			int w = (h / 2);
			int y = vecHeadScreen.y;
			int x = vecHeadScreen.x - w / 2;

			int healthh = vecScreen.y - vecHeadScreen.y;
			int healthw = 4;
			int healthy = vecHeadScreen.y;
			int healthx = vecHeadScreen.x - (h / 4 + 5);

			int armorh = vecScreen.y - vecHeadScreen.y;
			int armorw = 4;
			int armory = vecHeadScreen.y;
			int armorx = vecHeadScreen.x - (h / 4 + 11);

			int healthheight = (h * pCSPlayer->health()) / 100;
			int armorheight = (h * pCSPlayer->armor()) / 100;

			color espclr;

			if (variables::Visuals::esp::hpoverridecheck && pCSPlayer->health() <= variables::colors::esp::hpoverride)
			{
				espclr = color(variables::colors::esp::o_red, variables::colors::esp::o_green, variables::colors::esp::o_blue);
			}
			else
			{
				espclr = color::white();
			}
			
			if (pCSPlayer->team() != csgo::local_player->team()) 
			{
				if (variables::Visuals::esp::name == true) /* Name esp */
				{
					render::draw_text_string(vecHeadScreen.x, vecHeadScreen.y - 15, render::fonts::espfont, playerinfo.name, true, espclr);
				}
				 
				if (variables::Visuals::esp::box == true) /* Box esp */
				{
					render::draw_rect(x, y, w, h, color::black());
					render::draw_rect(x + 1, y + 1, w - 2, h - 2, espclr);
				}

				if (variables::Visuals::esp::healthbar) /* Health Bar esp */
				{
					if (pCSPlayer->health() > 70)
					{
						render::draw_rect(healthx, healthy, healthw, healthh, color::black());
						render::draw_filled_rect(healthx + 1, healthy + 1, healthw - 2, healthheight - 2, color::green());
					}

					if (pCSPlayer->health() < 70)
					{
						render::draw_rect(healthx, healthy, healthw, healthh, color::black());
						render::draw_filled_rect(healthx + 1, healthy + 1, healthw - 2, healthheight - 2, color(255, 165, 0));
					}

					if (pCSPlayer->health() < 35)
					{
						render::draw_rect(healthx, healthy, healthw, healthh, color::black());
						render::draw_filled_rect(healthx + 1, healthy + 1, healthw - 2, healthheight - 2, color::red());
					}

				}

				if (variables::Visuals::esp::shieldbar == true) /* Armor Bar esp */
				{
					if (pCSPlayer->armor() > 0)
					{
						render::draw_rect(armorx, armory, armorw, armorh, color::black());
						render::draw_filled_rect(armorx + 1, armory + 1, armorw - 1, armorheight - 2, color::blue());
					}
				}

				if (variables::Visuals::esp::weaponesp == true) /* Weapon name esp */
				{
					if (pCSPlayer->is_alive() == true)
					{
						std::string wep = pCSPlayer->active_weapon()->get_weapon_data()->weapon_name_alt;
						render::draw_text_string(vecHeadScreen.x, vecHeadScreen.y - 25, render::fonts::espfont, wep, true, color(255,255,0));
					}
				}

				if (pCSPlayer->is_flashed() == true) /* If target is flashed show flag */
				{
					render::draw_text_string(vecHeadScreen.x / -6, vecHeadScreen.y, render::fonts::watermark_font, "flashed", true, color(255, 255, 0));
				}

				/* Make more flags then esp is complete  */

			}
		}
	}
	else {}
}

void boneesp() /* Skeletons */
{
	if (variables::Visuals::esp::bonevisible == true) /* Only draw if player is visible */
	{
		variables::Visuals::esp::bonealways == false;
		for (int iPlayer = 0; iPlayer < interfaces::globals->max_clients; iPlayer++)
		{
			auto pCSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(iPlayer));
			if (!pCSPlayer)
				continue;
			if (pCSPlayer == csgo::local_player)
				continue;
			if (pCSPlayer->dormant())
				continue;
			if (!(pCSPlayer->is_alive() && pCSPlayer->health() > 0))
				continue;

			if (pCSPlayer->is_visible(pCSPlayer) == true)
			{
				vec3_t vecFoot;
				vec2_t vecScreen;
				vec2_t vecHeadScreen;
				vecFoot = pCSPlayer->origin();
				if (!(math::world_to_screen(vecFoot, vecScreen)))
					continue;

				vecFoot.z += 72.f;
				if (!(math::world_to_screen(vecFoot, vecHeadScreen)))
					continue;

				player_info_t playerinfo;
				interfaces::engine->get_player_info(iPlayer, &playerinfo);

				auto pStudioModel = interfaces::model_info->get_studio_model(pCSPlayer->model());
				if (!pStudioModel)
					return;

				static matrix_t pBoneToWorldOut[128];
				if (pCSPlayer->setup_bones(pBoneToWorldOut, 128, 256, 0))
				{
					for (int i = 0; i < pStudioModel->bones_count; i++)
					{
						if (interfaces::engine->is_in_game() == false)
							return;
						
						if (csgo::local_player == nullptr)
							return;
						
						studio_bone_t* pBone = pStudioModel->bone(i);
						if (!pBone || !(pBone->flags & 256) || pBone->parent == -1)
							continue;

						vec2_t vBonePos1;
						if (!math::world_to_screen(vec3_t(pBoneToWorldOut[i][0][3], pBoneToWorldOut[i][1][3], pBoneToWorldOut[i][2][3]), vBonePos1))
							continue;

						vec2_t vBonePos2;
						if (!math::world_to_screen(vec3_t(pBoneToWorldOut[pBone->parent][0][3], pBoneToWorldOut[pBone->parent][1][3], pBoneToWorldOut[pBone->parent][2][3]), vBonePos2))
							continue;
						
						else if (pCSPlayer->team() != csgo::local_player->team())
						{
							render::draw_line(vBonePos1.x, vBonePos1.y, vBonePos2.x, vBonePos2.y, color::white());
						}
					}

				}
			}
		}
	}
	if (variables::Visuals::esp::bonealways == true) /* Draw bones always */
	{
		variables::Visuals::esp::bonevisible == false;
		for (int iPlayer = 0; iPlayer < interfaces::globals->max_clients; iPlayer++)
		{
			auto pCSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(iPlayer));
			if (!pCSPlayer)
				continue;
			if (pCSPlayer == csgo::local_player)
				continue;
			if (pCSPlayer->dormant())
				continue;
			if (!(pCSPlayer->is_alive() && pCSPlayer->health() > 0))
				continue;


			vec3_t vecFoot;
			vec2_t vecScreen;
			vec2_t vecHeadScreen;
			vecFoot = pCSPlayer->origin();
			if (!(math::world_to_screen(vecFoot, vecScreen)))
				continue;

			vecFoot.z += 72.f;
			if (!(math::world_to_screen(vecFoot, vecHeadScreen)))
				continue;

			player_info_t playerinfo;
			interfaces::engine->get_player_info(iPlayer, &playerinfo);

			auto pStudioModel = interfaces::model_info->get_studio_model(pCSPlayer->model());
			if (!pStudioModel)
				return;

			static matrix_t pBoneToWorldOut[128];
			if (pCSPlayer->setup_bones(pBoneToWorldOut, 128, 256, 0))
			{
				for (int i = 0; i < pStudioModel->bones_count; i++)
				{
					if (interfaces::engine->is_in_game() == false)
						return;

					if (csgo::local_player == nullptr)
						return;
					
					studio_bone_t* pBone = pStudioModel->bone(i);
					if (!pBone || !(pBone->flags & 256) || pBone->parent == -1)
						continue;

					vec2_t vBonePos1;
					if (!math::world_to_screen(vec3_t(pBoneToWorldOut[i][0][3], pBoneToWorldOut[i][1][3], pBoneToWorldOut[i][2][3]), vBonePos1))
						continue;

					vec2_t vBonePos2;
					if (!math::world_to_screen(vec3_t(pBoneToWorldOut[pBone->parent][0][3], pBoneToWorldOut[pBone->parent][1][3], pBoneToWorldOut[pBone->parent][2][3]), vBonePos2))
						continue;
					else if (pCSPlayer->team() != csgo::local_player->team())
					{
						render::draw_line(vBonePos1.x, vBonePos1.y, vBonePos2.x, vBonePos2.y, color::white());
					}
				}

			}
		}
	}
	if (variables::Visuals::esp::backtrackskeleton == true) /* Draw bones always */
	{
		for (int iPlayer = 0; iPlayer < interfaces::globals->max_clients; iPlayer++)
		{
			auto pCSPlayer = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(iPlayer));
			
			if (!pCSPlayer)
				continue;
			if (pCSPlayer == csgo::local_player)
				continue;
			if (pCSPlayer->dormant())
				continue;
			if (!(pCSPlayer->is_alive() && pCSPlayer->health() > 0))
				continue;
			
			vec3_t vecFoot;
			vec2_t vecScreen;
			vec2_t vecHeadScreen;
			vecFoot = pCSPlayer->origin();
			if (!(math::world_to_screen(vecFoot, vecScreen)))
				continue;

			vecFoot.z += 72.f;
			if (!(math::world_to_screen(vecFoot, vecHeadScreen)))
				continue;

			player_info_t playerinfo;
			interfaces::engine->get_player_info(iPlayer, &playerinfo);

			auto pStudioModel = interfaces::model_info->get_studio_model(pCSPlayer->model());
			if (!pStudioModel)
				return;

			static matrix_t pBoneToWorldOut[128];
			if (pCSPlayer->setup_bones(pBoneToWorldOut, 128, 256, 0))
			{
				for (int i = 0; i < pStudioModel->bones_count; i++)
				{
					if (interfaces::engine->is_in_game() == false)
						return;

					if (csgo::local_player == nullptr)
						return;

					studio_bone_t* pBone = pStudioModel->bone(i);
					if (!pBone || !(pBone->flags & 256) || pBone->parent == -1)
						continue;

					vec2_t vBonePos1;
					if (!math::world_to_screen(vec3_t(pBoneToWorldOut[i][0][3], pBoneToWorldOut[i][1][3], pBoneToWorldOut[i][2][3]), vBonePos1))
						continue;

					vec2_t vBonePos2;
					
					if (!math::world_to_screen(vec3_t(pBoneToWorldOut[pBone->parent][0][3], pBoneToWorldOut[pBone->parent][1][3], pBoneToWorldOut[pBone->parent][2][3]), vBonePos2))
						continue;
					
					else if (pCSPlayer->team() != csgo::local_player->team() && records[pCSPlayer->index()].size() > 0 && variables::aimbots::backtrack == true)
					{
						for (uint32_t i = 0; i < records[pCSPlayer->index()].size(); i++)
						{
							//render::draw_line(records[vBonePos1.x], vBonePos1.y, vBonePos2.x, vBonePos2.y, color::white());
						}
					}
				}

			}
		}
	}
}

void gernadepredict(c_usercmd* cmd) /* Grenade prediction */
{
	if (variables::Visuals::esp::espToggle == true) /* ??? Why did I ever do this... anyways I need to create a standalone variable for this */
	{
		if (WEAPONTYPE_GRENADE && cmd->buttons & in_attack || in_attack2)
		{

		}
	}
}

void bombesp() /* Bomb timer */
{
	if (variables::Visuals::esp::espToggle == true) /* Make seperate variable */
	{
		for (int bomb = 0; bomb < interfaces::entity_list->get_highest_index(); bomb++)
		{
			auto entity = reinterpret_cast<entity_t*>(interfaces::entity_list->get_client_entity_handle(183));

			if (entity->is_player() == false) /* Don't do anything if localplayer */
			{
				vec3_t vecFoot;
				vec2_t vecScreen;
				vec2_t vecHeadScreen;
				vecFoot = entity->origin();
				if (!(math::world_to_screen(vecFoot, vecScreen)))
					continue;

				vecFoot.z += 72.f;
				if (!(math::world_to_screen(vecFoot, vecHeadScreen)))
					continue;

				float bombTime = *(float*)((DWORD)+0x2990); /* Maybe works??? */
				float detonateTime = bombTime - interfaces::globals->interval_per_tick * csgo::local_player->get_tick_base();
				std::string bombtimer = std::to_string(detonateTime);
				render::draw_text_string(vecHeadScreen.x, vecHeadScreen.y, render::fonts::watermark_font, bombtimer, true, color::white());
			}
		}
	}
	else {}
}