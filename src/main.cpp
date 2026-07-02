#include <iostream>
#include "engine.hpp"

int main()
{

    Engine::WindowProperties wp{
        .m_width = 700,
        .m_height = 700,
        .m_title = "Hi"};

    Engine::setup(wp);
    Engine::run();

    return 0;
}
