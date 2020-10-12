#pragma once

namespace variables {
	inline bool pbunny = true;
	inline bool lbunny = false;
	inline bool antiflash = true;
	inline bool rcs = false;
	inline bool bonevisible = true;
	inline bool bonealways = false;
	inline bool espToggle = true;
	inline bool hvhmode = false;
	inline bool aimbotToggle = true;
	inline bool thirdperson = false;
	inline bool chams = true;
	inline bool dtag = false;
	inline bool stag = false;
	inline bool crosshair = true;
	inline int arms = 0;
	inline bool normalmenu = false;
	inline bool backtrack = true;
	inline float smoothing = 2.0f;
	inline bool silentaim = false;
	inline bool box = true;
	inline bool healthbar = true;
	inline bool shieldbar = true;
	inline bool name = true;
	inline bool chamsxqz = false;
	inline bool chamsvisible = false;
	inline bool chamsalways = true;
	inline bool nohands = false;
	inline bool armschams = false;
	inline bool ragebot = false;
	inline bool ctarget = false;
	inline bool chealth = false;
	inline bool cdistance = false;
	inline bool airstuck = false;
	inline color chamcolor = color::red();
	inline float chamfloat;
	inline bool pisopened;

	///////////////////////////////////////////
	
	inline bool randombones = true;
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

	namespace menu {
		inline bool opened = true;
		inline int x = 140, y = 140;
		inline int w = 800, h = 625;
	}

}