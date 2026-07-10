#pragma once

#include <memory>

#include "Core.h"
#include "Division/Window.h"

namespace Division
{

    class DIVISION_API Application
    {
      public:
        Application();
        virtual ~Application();
        void Run();

      private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}  // namespace Division
