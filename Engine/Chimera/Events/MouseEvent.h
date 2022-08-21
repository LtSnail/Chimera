#pragma once

#include "Event.h"

namespace Chimera
{
    class CHIMERA_API MouseMovedEvent : public Event<MouseMovedEvent>
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };

    class CHIMERA_API MouseScrolledEvent : public Event<MouseScrolledEvent>
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_xOffset(xOffset), m_yOffset(yOffset) {}

        inline float GetXOffset() const { return m_xOffset; }
        inline float GetYOffset() const { return m_yOffset; }

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_xOffset, m_yOffset;
    };

    template <typename D>
    class CHIMERA_API MouseButtonEvent : public Event<MouseButtonEvent<D>>
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(int button)
            : m_Button(button) {}

        int m_Button;
    };

    class CHIMERA_API MouseButtonPressedEvent : public MouseButtonEvent<MouseButtonPressedEvent>
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class CHIMERA_API MouseButtonReleasedEvent : public MouseButtonEvent<MouseButtonReleasedEvent>
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}