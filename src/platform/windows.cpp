#include "engine.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Engine
{

  bool running{true};
  HWND window;

  namespace Window
  {

    LRESULT CALLBACK window_callback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
      LRESULT result;

      switch (msg)
      {
      case WM_CLOSE:
      {
        Engine::running = false;
        DestroyWindow(window);
        break;
      }
      default:
        result = DefWindowProcA(hwnd, msg, wParam, lParam);
      }

      return result;
    }

    bool create(const WindowProperties &p)
    {

      HINSTANCE instance = GetModuleHandleA(nullptr);
      WNDCLASSA wc = {};

      wc.hInstance = instance;
      wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
      wc.hCursor = LoadCursor(instance, IDC_ARROW);
      wc.lpszClassName = p.m_title;
      wc.lpfnWndProc = window_callback;

      if (!RegisterClassA(&wc))
      {
        return false;
      }

      int dwStyle = WS_OVERLAPPEDWINDOW;

      window = CreateWindowExA(
          0,
          p.m_title,
          p.m_title,
          dwStyle,
          100,
          100,
          p.m_width,
          p.m_height,
          nullptr,
          nullptr,
          instance,
          nullptr);

      if (!window)
      {
        return false;
      }

      ShowWindow(window, SW_SHOW);

      return true;
    }
    void update()
    {
      MSG msg{};

      while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
      {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }

  } // namespace Window

  void setup(const WindowProperties &p)
  {
    Window::create(p);
  }

  void run()
  {
    while (Engine::running)
    {
      Window::update();
    }
  }

} // namespace Engine
