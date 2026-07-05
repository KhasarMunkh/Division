#pragma once

#include <sstream>

#include "Division/Core.h"
#include "Division/Events/Event.h"
namespace Division {

    class DIVISION_API KeyEvent : public Event
    {
      protected:
        int m_KeyCode;
        KeyEvent(int key) : m_KeyCode(key) {}

      public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    };

    class DIVISION_API KeyPressedEvent : public KeyEvent
    {
      private:
        bool m_IsRepeat;

      public:
        KeyPressedEvent(int key, bool isRepeat = false) : KeyEvent(key), m_IsRepeat(isRepeat) {}

        inline bool GetIsRepeat() const { return m_IsRepeat; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    };

    class DIVISION_API KeyReleasedEvent : public KeyEvent
    {
      public:
        KeyReleasedEvent(int key) : KeyEvent(key) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class DIVISION_API KeyTypedEvent : public KeyEvent
    {
      public:
        KeyTypedEvent(int key) : KeyEvent(key) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

}  // namespace Division
