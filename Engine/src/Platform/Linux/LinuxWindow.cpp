#include "LinuxWindow.h"

#include <dvpch.h>

#include "Division/Window.h"

namespace Division
{
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props) { return new LinuxWindow(props); }

    LinuxWindow::LinuxWindow(const WindowProps& props) { Init(props); }
    LinuxWindow::~LinuxWindow() { Shutdown(); }
    void LinuxWindow::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
    }
    void LinuxWindow::Shutdown() {}
    bool IsVSync() {
    }

}  // namespace Division
