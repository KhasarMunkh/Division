#pragma once

#include "Division/Application.h"
#include "Division/Log.h"

extern Division::Application* Division::CreateApplication();

int main(int argc, char** argv) {
    Division::Log::Init(); // temporary... will move to some system initialization
    DV_CORE_WARN("Initialized Log!");
    DV_CORE_ERROR("Hello!");
    auto app = Division::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
