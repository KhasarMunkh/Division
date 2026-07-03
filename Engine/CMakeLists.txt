add_library(Division SHARED
    src/Division/Application.cpp
)

target_include_directories(Division
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(Division
    PRIVATE
        DIVISION_BUILD_DLL
)
