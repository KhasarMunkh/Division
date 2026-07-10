add_library(Division SHARED
    src/Division/Application.cpp
    src/Division/Log.cpp
    src/Division/Window.h
)

target_include_directories(Division
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(OpenGL REQUIRED)

target_link_libraries(Division
    PUBLIC
        spdlog::spdlog
    PRIVATE
        glfw
        OpenGL::GL
)

target_precompile_headers(Division
    PRIVATE
        src/dvpch.h
)

target_compile_definitions(Division
    PRIVATE
        DV_BUILD_DLL
    PUBLIC
        $<$<CONFIG:Debug>:DV_ENABLE_ASSERTS>
)

if(WIN32)
    target_compile_definitions(Division PUBLIC DV_PLATFORM_WINDOWS)
    target_sources(Division PRIVATE src/Platform/Windows/WindowsWindow.cpp)
elseif(APPLE)
    target_compile_definitions(Division PUBLIC DV_PLATFORM_MACOS)
    target_sources(Division PRIVATE src/Platform/MACOS/MACOSWindow.cpp)
elseif(UNIX)
    target_compile_definitions(Division PUBLIC DV_PLATFORM_LINUX)
    target_sources(Division PRIVATE src/Platform/Linux/LinuxWindow.cpp)
else()
    message(FATAL_ERROR "Unsupported platform!")
endif()
