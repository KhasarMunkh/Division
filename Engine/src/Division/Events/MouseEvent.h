#pragma once

#include <sstream>

#include "Division/Core.h"
#include "Division/Events/Event.h"

namespace Division {
    // currently, no type for mouse buttons, so using int for now.
    class DIVISION_API MouseButtonEvent : public Event
    {
      protected:
        int m_Button;
        MouseButtonEvent(int button) : m_Button(button) {}

      public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
    };

    class DIVISION_API MouseButtonPressedEvent : public MouseButtonEvent
    {
      public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "ButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class DIVISION_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
      public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class DIVISION_API MouseMovedEvent : public Event
    {
      private:
        float m_MouseX, m_MouseY;

      public:
        MouseMovedEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) {}

        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class DIVISION_API MouseScrolledEvent : public Event
    {
      private:
        float m_XOffset, m_YOffset;

      public:
        MouseScrolledEvent(const float x, const float y) : m_XOffset(x), m_YOffset(y) {}

        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };
}  // namespace Division
