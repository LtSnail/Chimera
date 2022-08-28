#pragma once

#include "Core.h"

#include "Window.h"

namespace Chimera
{
    class WindowMacOS : public Window
    {
    public:
        WindowMacOS(const WindowProps& props, const EventQueue& eventQueue);
        ~WindowMacOS();

        virtual void OnUpdate() override;

        inline virtual unsigned int GetWidth() const override { return m_Props.Width; }
        inline virtual unsigned int GetHeight() const override { return m_Props.Height; }

        inline virtual void SetVSync(bool enabled) override { UNUSED(enabled); }
        inline virtual bool IsVSync() const override { return true; }

    private:
        void Init(const WindowProps& props, const EventQueue& eventQueue);
        void Shutdown();

        // ChimeraWindow*
        void* m_Window;

        // ChimeraView*
        void* m_View;

        WindowProps m_Props;
    };
}
