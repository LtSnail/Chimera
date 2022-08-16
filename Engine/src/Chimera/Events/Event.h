#pragma once

#include <string>
#include <functional>

#include "../Core.h"

namespace Chimera
{
    // Blocking events, refactor to an event bus later on.

    enum class EventType
    {
        None = 0,

        // Window
        EventTypeWindowClose,
        EventTypeWindowResize,
        EventTypeWindowFocus,
        EventTypeWindowLostFocus,
        EventTypeWindowMoved,

        // Application
        EventTypeAppTick,
        EventTypeAppUpdate,
        EventTypeAppRender,

        // Input
        EventTypeKeyPressed,
        EventTypeKeyReleased,
        EventTypeMouseButtonPressed,
        EventTypeMouseMoved,
        EventTypeMouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication      = BIT(0),
        EventCategoryInput            = BIT(1),
        EventCategoryKeyboard         = BIT(2),
        EventCategoryMouse            = BIT(3),
        EventCategoryMouseButton      = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::EventType##type; }\
                                EventType GetEventType() const { return GetStaticType(); }\
                                const char* GetName() const { return #type; }

#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const { return category; }

    template<typename D>
    class CH_API Event
    {
    public:
        EventType GetEventType() const
        {
            return self()->GetEventType();
        }

        const char* GetName() const
        {
            return self()->GetName();
        }

        int GetCategoryFlags() const
        {
            return self()->GetCategoryFlags();
        }

        std::string ToString() const
        {
            return GetName();
        }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        template <typename T>
        void Dispatch(std::function<bool(T&)> func)
        {
            m_handled = func(*static_cast<T*>(this));
        }

    protected:
        Event() = default;
        friend D;

        bool m_handled = false;

    private:
        inline D& self() { return *static_cast<D*>(this); }
        inline const D& self() const { return *static_cast<D*>(this); }
    };
}