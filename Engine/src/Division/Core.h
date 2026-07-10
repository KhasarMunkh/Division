#pragma once

#ifdef DV_PLATFORM_WINDOWS
#ifdef DV_BUILD_DLL
#define DIVISION_API __declspec(dllexport)
#else
#define DIVISION_API __declspec(dllimport)
#endif
#else
#define DIVISION_API __attribute__((visibility("default")))
#endif

// ---- Debug break: platform-specific "trip the debugger" instruction ----
#ifdef DV_PLATFORM_WINDOWS
#define DV_DEBUGBREAK() __debugbreak()
#else
#include <signal.h>
#define DV_DEBUGBREAK() raise(SIGTRAP)
#endif

// ----- Asserts -----
#ifdef DV_ENABLE_ASSERTS
#define DV_ASSERT(x, ...)                                   \
    {                                                       \
        if (!(x)) {                                         \
            DV_ERROR("Assertion failed: {0}", __VA_ARGS__); \
            DV_DEBUGBREAK();                                \
        }                                                   \
    }
#define DV_CORE_ASSERT(x, ...)                                   \
    {                                                            \
        if (!(x)) {                                              \
            DV_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); \
            DV_DEBUGBREAK();                                     \
        }                                                        \
    }
#else
#define DV_ASSERT(x, ...)
#define DV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
