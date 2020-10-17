#pragma once

namespace variables {

	///////////////////////////////////////////

	namespace misc
	{
		inline bool pbunny = true;
		inline bool lbunny = false;
		inline bool antiflash = true;
		inline bool hvhmode = false;
		inline bool thirdperson = false;
		inline bool dtag = false;
		inline bool stag = false;
		inline bool backtrack = true;
		inline bool airstuck = false;
	}

	///////////////////////////////////////////

	namespace Visuals
	{
		namespace esp
		{
			inline bool espToggle = true;
			inline bool box = true;
			inline bool healthbar = true;
			inline bool shieldbar = true;
			inline bool name = true;
			inline bool bonevisible = true;
			inline bool bonealways = false;
			inline bool weaponesp = false;
		}

		namespace chams
		{
			inline bool chams = true;
			inline bool chamsxqz = false;
			inline bool chamsvisible = false;
			inline bool chamsalways = true;
			inline bool nohands = false;
			inline bool armschams = false;
		}

	}

	///////////////////////////////////////////

	namespace aimbots
	{
		namespace trigger
		{
			namespace pistols
			{
				inline bool enabled = false;
				inline float delay = 0.f;
				inline bool head = false;
				inline bool neck = true;
				inline bool chest = true;
				inline bool legs = false;
			}

			namespace smgs
			{
				inline bool enabled = false;
				inline float delay = 0.f;
				inline bool head = false;
				inline bool neck = true;
				inline bool chest = true;
				inline bool legs = false;
			}

			namespace rifles
			{
				inline bool enabled = false;
				inline float delay = 0.f;
				inline bool head = false;
				inline bool neck = true;
				inline bool chest = true;
				inline bool legs = false;
			}
				
			namespace snipers
			{
				inline bool enabled = false;
				inline float delay = 0.f;
				inline bool head = false;
				inline bool neck = true;
				inline bool chest = true;
				inline bool legs = false;
			}
			
			namespace bones
			{
				inline bool head = false;
				inline bool neck = true;
				inline bool chest = true;
				inline bool legs = false;
			}

		}

		namespace legit
		{
			namespace pistols
			{
				inline bool aimbotToggle = true;
				inline bool crosshair = true;
				inline bool rcs = false;
				inline float smoothing = 2.0f;
				inline bool silentaim = false;
				inline bool randombones = true;
				inline bool ahead = false;
				inline bool aneck = false;
				inline bool achest = false;
				inline bool apelvis = false;
				inline bool afeet = false;
				inline bool yisopened = false;
			}

			namespace smgs
			{
				inline bool aimbotToggle = true;
				inline bool crosshair = true;
				inline bool rcs = false;
				inline float smoothing = 2.0f;
				inline bool silentaim = false;
				inline bool randombones = true;
				inline bool ahead = false;
				inline bool aneck = false;
				inline bool achest = false;
				inline bool apelvis = false;
				inline bool afeet = false;
				inline bool yisopened = false;
			}

			namespace rifles
			{
				inline bool aimbotToggle = true;
				inline bool crosshair = true;
				inline bool rcs = false;
				inline float smoothing = 2.0f;
				inline bool silentaim = false;
				inline bool randombones = true;
				inline bool ahead = false;
				inline bool aneck = false;
				inline bool achest = false;
				inline bool apelvis = false;
				inline bool afeet = false;
				inline bool yisopened = false;
			}

			namespace snipers
			{
				inline bool aimbotToggle = true;
				inline bool crosshair = true;
				inline bool rcs = false;
				inline float smoothing = 2.0f;
				inline bool silentaim = false;
				inline bool randombones = true;
				inline bool ahead = false;
				inline bool aneck = false;
				inline bool achest = false;
				inline bool apelvis = false;
				inline bool afeet = false;
				inline bool yisopened = false;

				namespace keybindings
				{
					inline int aimbotbind;
				}
				
			}

			inline bool aimbotToggle = true;
			inline bool crosshair = true;
			inline bool rcs = false;
			inline float smoothing = 2.0f;
			inline bool silentaim = false;
			
		}

		namespace rage
		{
			inline bool ragebot = false; /* Variable that enables */
			inline bool ctarget = false;
			inline bool chealth = false;
			inline bool cdistance = false;
		}

		
	}
	///////////////////////////////////////////

	inline bool randombones = true;
	
	namespace fov
	{
		inline bool fovOveride = false;
		inline float fovamount = 5.0f;
	}

	///////////////////////////////////////////

	namespace colors
	{

		namespace cFloats
		{
			inline float chamfloat;
		}

		inline color chamcolor = color::red();

	}

	///////////////////////////////////////////

	inline bool ahead = false;
	inline bool aneck = false;
	inline bool achest = false;
	inline bool apelvis = false;
	inline bool afeet = false;
	inline bool yisopened = false;

	///////////////////////////////////////////

	namespace antiaim {
		inline bool enabled = false;
		inline bool pUp = false;
		inline bool pDown = false;
		inline bool yStatic = false;
		inline bool yJitter = false;
	}

	///////////////////////////////////////////

	namespace weapontypes
	{
		inline bool rifles = false;
		inline bool lmg = false;
		inline bool pistol = false;
		inline bool smg = false;
		inline bool sniper = false;
	}

	///////////////////////////////////////////

	namespace menu {
		
		namespace combos
		{
			inline bool wgIsOpened = false;
			inline bool lbsIsOpened = false;
			inline bool pisopened = false;
			inline bool boneComboToggle = false;
			inline bool tHOpened = false;
			inline bool cCOpened = false;
		}

		inline bool opened = true;
		inline int x = 140, y = 140;
		inline int w = 800, h = 625;
	}

	///////////////////////////////////////////

}