#include <dvpch.h>

#include "Application.h"

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
