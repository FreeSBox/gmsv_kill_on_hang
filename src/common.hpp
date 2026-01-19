#pragma once

#include "gmod/platform.hpp"
#include "tier0/dbg.h"

#include <atomic>
#include <cstdint>

#include <memory>


#include <string>
#include <string_view>

#include <vector>

namespace gm_kill_on_hang
{
	inline std::atomic_bool g_running{true};
}
