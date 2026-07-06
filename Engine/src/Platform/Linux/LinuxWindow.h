#pragma once

#include <Division/Window.h>

#include "GLFW/glfw3.h"
namespace Division
{

    // Interface representing a desktop system based Window
    // Implmentation will be per platform, e.g. Windows, Linux, MacOS
    class DIVISION_API LinuxWindow : public Window
    {
      private:
        GLFWwindow* m_Window;
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool Vsync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

        void Init(const WindowProps& props);
        void Shutdown();

      public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow() {}

        virtual void OnUpdate() override;  // called once per frame by the run loop. It does two things: poll OS events
                                           // and swap buffers. The name is deliberately vague so a platform can do
                                           // whatever "per-frame window work" means for it

        virtual unsigned int GetWidth() const override { return m_Data.Width; };
        virtual unsigned int GetHeight() const override { return m_Data.Height; };

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
        virtual void SetVSync(bool enabled) override;
        virtual void IsVSync() const override;

        // Implemented by the platform-specific .cpp — the compile-time factory.
        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
    };
}  // namespace Division
