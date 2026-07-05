add_library(Division SHARED
    src/Division/Application.cpp
    src/Division/Log.cpp
)

target_include_directories(Division
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Division
    PUBLIC
        spdlog::spdlog
)

target_precompile_headers(Division
    PRIVATE
        src/dvpch.h
)

target_compile_definitions(Division
    PRIVATE
        DV_BUILD_DLL
)

if(WIN32)
    target_compile_definitions(Division 
        PUBLIC 
            DV_PLATFORM_WINDOWS
    )
endif()
