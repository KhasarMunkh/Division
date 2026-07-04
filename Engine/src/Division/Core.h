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

#define BIT(x) (1 << x)
