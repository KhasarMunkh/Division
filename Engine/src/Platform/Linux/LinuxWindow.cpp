#include "LinuxWindow.h"

#include <dvpch.h>

#include "Division/Window.h"
#include "GLFW/glfw3.h"

namespace Division
{
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props) { return new LinuxWindow(props); }

    LinuxWindow::LinuxWindow(const WindowProps& props) { Init(props); }
    LinuxWindow::~LinuxWindow() { Shutdown(); }
    void LinuxWindow::Init(const WindowProps& props) {
        if (!s_GLFWInitialized) {
            // TODO: add init hints
            //glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
            glfwInit();
            s_GLFWInitialized = !s_GLFWInitialized;
        }

        m_Data.Title  = props.Title;
        m_Data.Width  = props.Width;
        m_Data.Height = props.Height;
        m_Window      = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
        if (m_Window == nullptr) {
            DV_CORE_ERROR("glfwCreateWindow failed!");
        }
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
    }
    void LinuxWindow::Shutdown() {
        // In the future, we will want to be able to create multiple windows,
        // so we will need to check for window counts
        // before terminating for now just terminate
        glfwTerminate();
    }
    bool LinuxWindow::IsVSync() const {
        return m_Data.Vsync;
    }

}  // namespace Division
