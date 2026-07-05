#pragma once

#include "Division/Events/Event.h"
namespace Division {

    class DIVISION_API KeyEvent : public Event {
    protected:
        int m_KeyCode;
public: 
        KeyEvent(int key) {

    }
    };
}



        // KeyPressed,
        // KeyReleased,
        // KeyTyped,
        // MouseButtonPressed,
        // MouseButtonReleased,
        // MouseMoved,
        // MouseScrolled



