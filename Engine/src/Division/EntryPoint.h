#pragma once

#include "Division/Application.h"

extern Division::Application* Division::CreateApplication();

int main(int argc, char** argv) {
    auto app = Division::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
