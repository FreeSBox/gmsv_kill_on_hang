// garrysmod_common has pattern scanning, but it's so fucking unreadable and not documented that I'm just gonna take the YimMenu classes instead.
#include "memory/batch.hpp"
#include "memory/handle.hpp"
#include "memory/pattern.hpp"
#include "memory/module.hpp"

#include "pointers.hpp"

#include "edict.h"

namespace gm_kill_on_hang
{
	void pointers::init_engine()
	{
		memory::batch batch;
		memory::module module("engine");

#if ARCHITECTURE_IS_X86_64
		batch.add("gpGlobals", "89 83 ? ? ? ? 48 8B 05 ? ? ? ? F3 0F 10 00", [this](memory::handle ptr) {
			m_globals = ptr.add(5).add(3).rip().as<CGlobalVars **>();
		});

		batch.add("CGameServer", "0F 85 ? ? ? ? 48 8B 1D ? ? ? ? 48 89 DF", [this](memory::handle ptr) {
			m_sv = ptr.add(5).add(3).rip().as<CGameServer *>();
		});
#elif ARCHITECTURE_IS_X86
		batch.add("gpGlobals", "F3 0F 10 05 ? ? ? ? 09", [this](memory::handle ptr) {
			m_globals = ptr.add(4).as<CGlobalVars **>();
		});

		batch.add("CGameServer", "C7 04 24 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? 84 C0 0F", [this](memory::handle ptr) {
			m_sv = *ptr.add(3).as<IServer **>();
		});
#endif


		batch.run(module);
	}

	pointers::pointers()
	{
		init_engine();

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}