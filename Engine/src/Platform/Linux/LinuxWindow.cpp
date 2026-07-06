#include <dvpch.h>

#include "LinuxWindow.h"

#include "Division/Window.h"

namespace Division
{

    static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps()) {
        return std::make_unique<LinuxWindow>(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps& props) { Init(props);}
    LinuxWindow::~LinuxWindow() { Shutdown(); }

}  // namespace Division
