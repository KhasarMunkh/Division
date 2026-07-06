#pragma once

#include <dvpch.h>

#include "Division/Core.h"
#include "Division/Events/Event.h"

namespace Division
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Height;
        unsigned int Width;
        WindowProps(const std::string& title = "Divsion Engine", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    // Interface representing a desktop system based Window
    // Implmentation will be per platform, e.g. Windows, Linux, MacOS
    class DIVISION_API Window
    {
      public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}  // this is a virtual destructor, so that the derived class's destructor is called when
                              // deleting an instance of the base class

        virtual void OnUpdate() = 0;  // called once per frame by the run loop. It does two things: poll OS events and
                                      // swap buffers. The name is deliberately vague so a platform can do whatever
                                      // "per-frame window work" means for it

        virtual unsigned int GetWidth() const  = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled)                            = 0;
        virtual void IsVSync() const                                   = 0;

        // Implemented by the platform-specific .cpp — the compile-time factory.
        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
    };
}  // namespace Division
