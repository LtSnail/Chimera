#pragma once

#include "chpch.h"

#include "Events/Event.h"
#include "EventQueue.h"

namespace Chimera
{
    struct WindowProps
    {
        std::string Title = "Chimera Engine";
        long x = 0;
        long y = 0;
        unsigned int Width = 1280;
        unsigned int Height = 720;

        bool Centered = true;
        bool Resizable = true;
        bool Movable = true;
        bool Closable = true;
        bool Minimizable = true;
        bool Maximizable = true;
        bool CanFullscreen = true;

        unsigned BackgroundColor = 0xFFFFFFFF;
        bool Transparent = false;
        bool Frame = true;
        bool HasShadow = true;
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static std::unique_ptr<Window> CreateAppWindow(const WindowProps& props,
                                                       EventQueue& eventQueue);
    };
}
