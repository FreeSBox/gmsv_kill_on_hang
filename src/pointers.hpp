#pragma once

class CGlobalVars;
class IServer;

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
		IServer* m_sv{};
	};

	inline pointers* g_pointers{};
}
