#include "GarrysMod/Lua/Interface.h"

#include "common.hpp"
#include "pointers.hpp"
#include "kill_on_hang.hpp"

#include <memory>
#include <thread>

std::unique_ptr<gm_kill_on_hang::pointers> pointers_instance;
std::unique_ptr<std::thread> killer_instance;

GMOD_MODULE_OPEN()
{
	using namespace gm_kill_on_hang;

	pointers_instance = std::make_unique<pointers>();
	Msg("Pointers initialized.\n");
	
	g_running = true;

	killer_instance = std::make_unique<std::thread>(update_kill_on_hang);
	Msg("Killer initialized.\n");


	return 0;
}

GMOD_MODULE_CLOSE()
{
	using namespace gm_kill_on_hang;

	pointers_instance.reset();
	Msg("Pointers uninitialized.\n");

	g_running = false;

	killer_instance->join();
	killer_instance.reset();
	Msg("Killer uninitialized.\n");

	return 0;
}
