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


// if compiling on Windows:
//   if building the engine (DIVISION_BUILD_DLL is defined):
//       DIVISION_API = __declspec(dllexport)
//   else (building the sandbox):
//       DIVISION_API = __declspec(dllimport)
// else (Linux/Mac):
//   DIVISION_API = __attribute__((visibility("default")))
