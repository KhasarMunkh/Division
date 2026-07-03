#include "Application.h"
#include <stdio.h>
#include <spdlog/spdlog.h>

namespace Division {

Application::Application() {
    spdlog::info("Application Constructed");
    // Constructor implementation
}

Application::~Application() {
    printf("Divison::Application Deconstructed\n");
}

void Application::Run() {
    printf("Hello\n");
    // while(true) {
    //     // Main loop implementation
    // }
}

} // namespace Division
