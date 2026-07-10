#include "Application.h"

#include <dvpch.h>

namespace Division
{

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        spdlog::info("Application Constructed");
        // Constructor implementation
    }

    Application::~Application() { printf("Divison::Application Deconstructed\n"); }

    void Application::Run() {
        while(m_Running) {
            m_Window->OnUpdate();
        }
    }

}  // namespace Division
