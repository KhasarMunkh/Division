#pragma once

#include <sstream>

#include "Division/Core.h"
#include "Event.h"

namespace Division {

    class DIVISION_API WindowResizeEvent : public Event
    {
      private:
        unsigned int m_Width, m_Height;

      public:
        WindowResizeEvent(unsigned int w, unsigned int h) : m_Width(w), m_Height(h) {}
        unsigned int GetWidth() { return m_Width; }
        unsigned int GetHeight() { return m_Height; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class DIVISION_API WindowCloseEvent : public Event
    {
      public:
        WindowCloseEvent() = default;
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    // class DIVISION_API WindowMoved : public Event
    // {
    // };
    //
    // class DIVISION_API WindowFocus : public Event
    // {
    // };
    //
    // class DIVISION_API WindowLostFocus : public Event
    // {
    // };
    

    // the below events may or may not be needed, but they are here for now
    class DIVISION_API AppTickEvent : public Event
    {
      public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class DIVISION_API AppUpdateEvent : public Event
    {
      public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class DIVISION_API AppRenderEvent : public Event
    {
      public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}  // namespace Division
