#include "Application.h"
#include <stdio.h>

namespace Division {

Application::Application() {
    printf("Divison::Application Constructed\n");
    // Constructor implementation
}

Application::~Application() {
    printf("Divison::Application Deconstructed\n");
}

void Application::Run() {
    printf("Hello");
    // while(true) {
    //     // Main loop implementation
    // }
}

} // namespace Division
