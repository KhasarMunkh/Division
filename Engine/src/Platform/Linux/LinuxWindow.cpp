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
        m_Data.Title  = props.Title;
        m_Data.Width  = props.Width;
        m_Data.Height = props.Height;

        DV_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            // TODO: add init hints
            // glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
            int success = glfwInit();
            DV_CORE_ASSERT(success, "Could not initialize GLFW!");
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
        if (m_Window == nullptr) {
            DV_CORE_ERROR("glfwCreateWindow failed!");
        }
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }
    void LinuxWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
        // In the future, we will want to be able to create multiple windows,
        // so we will need to check for window counts
        // before terminating for now just terminate
        glfwTerminate();
    }
    bool LinuxWindow::IsVSync() const { return m_Data.Vsync; }

    void LinuxWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        m_Data.Vsync = enabled;
    }

    void LinuxWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

}  // namespace Division
