#pragma once

#include "Division/Core.h"
#include "Event.h"

namespace Division {

    class DIVISION_API WindowClose : public Event  {

    };

    class DIVISION_API WindowMoved : public Event  {

    };

    class DIVISION_API WindowFocus : public Event  {

    };

    class DIVISION_API WindowLostFocus : public Event  {

    };

    class DIVISION_API WindowResize : public Event  {

    };

    class DIVISION_API AppTick : public Event  {

    };

    class DIVISION_API AppUpdate : public Event  {

    };

    class DIVISION_API AppRender : public Event  {

    };
}
