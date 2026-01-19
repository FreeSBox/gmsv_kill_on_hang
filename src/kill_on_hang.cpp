#include "pointers.hpp"

#include "edict.h"
#include "../engine/server.h"

#include <thread>

namespace gm_kill_on_hang
{
	using namespace std::chrono_literals;
	static float old_curtime = 0;
	void update_kill_on_hang()
	{
		while (g_running)
		{
			float curtime = (*g_pointers->m_globals)->curtime;
			int player_count = g_pointers->m_sv->GetNumPlayers();

			if (player_count > 0 && old_curtime == curtime)
			{
				Msg("HANG DETECTED, KILLING THE PROCESS");
				exit(1);
			}

			old_curtime = curtime;

			std::this_thread::sleep_for(10s);
		}
	}
}
