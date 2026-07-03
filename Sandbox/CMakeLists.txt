add_executable(Sandbox
    src/SandboxApp.cpp
)

target_link_libraries(Sandbox
    PRIVATE
        Division
)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Division>
        $<TARGET_FILE_DIR:Sandbox>
)
