include(FetchContent)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(SOURCE_SDK_TAG x86-64-branch) # This constantly breaks due to force pushes, let's just use the latest commit.
else()
	set(SOURCE_SDK_TAG 02b6679d1b3f90117d4bbcfe2b1f71ee9250014f)
endif()

FetchContent_Declare(
	sourcesdk_minimal
	GIT_REPOSITORY https://github.com/RaphaelIT7/sourcesdk-minimal.git
	GIT_TAG        ${SOURCE_SDK_TAG}
	GIT_PROGRESS TRUE
)
message("sourcesdk-minimal")
FetchContent_MakeAvailable(sourcesdk_minimal)

file(GLOB SOURCE_INCLUDES
	"${sourcesdk_minimal_SOURCE_DIR}/common"
	"${sourcesdk_minimal_SOURCE_DIR}/public"
	"${sourcesdk_minimal_SOURCE_DIR}/public/tier0"
	"${sourcesdk_minimal_SOURCE_DIR}/public/tier1"
	"${sourcesdk_minimal_SOURCE_DIR}/game/shared"
	"${sourcesdk_minimal_SOURCE_DIR}/game/server"
	"${sourcesdk_minimal_SOURCE_DIR}/engine"
)

add_library(common STATIC
	"${sourcesdk_minimal_SOURCE_DIR}/common/netmessages.cpp"
	"${sourcesdk_minimal_SOURCE_DIR}/game/server/gameinterface.cpp"
)


target_include_directories(common PRIVATE ${SOURCE_INCLUDES})
target_compile_definitions(common PRIVATE
	"RAD_TELEMETRY_DISABLED"
	"COMMON_STATIC_LIB"
	"GAME_DLL"
)

if (WIN32)

else()
	add_compile_definitions(
		"_DLL_EXT=.so"
		"COMPILER_GCC"
		"POSIX"
		"_POSIX"
		"LINUX"
		"_LINUX"
		"GNUC"
		"NO_MALLOC_OVERRIDE"
	)
endif()
