#pragma once

class CGlobalVars;
class CGameServer;

namespace gm_kill_on_hang
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

	private:
		void init_engine();

	public:

		CGlobalVars** m_globals{};
		CGameServer* m_sv{};
	};

	inline pointers* g_pointers{};
}
