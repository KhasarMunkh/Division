#pragma once

#include "Core.h"

namespace Division {

    class DIVISION_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}  // namespace Division
