#pragma once

#include <string>

namespace Engine
{
    extern bool running;

    struct WindowProperties
    {
        int m_width{}, m_height{};
        const char *m_title{nullptr};
    };

    namespace Window
    {
        bool create(const WindowProperties &properties);
        void update();

    } // namespace Window

    void setup(const WindowProperties &properties);
    void run();

} // namespace Engine
