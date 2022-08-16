#pragma once

#include <sstream>

#include "Event.h"

namespace Chimera
{
    template <typename D>
    class CH_API KeyEvent : public Event<KeyEvent<D>>
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class CH_API KeyPressedEvent : public KeyEvent<KeyPressedEvent>
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };
}