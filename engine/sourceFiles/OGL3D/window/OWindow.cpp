#include "../../../headerFiles/OGL3D/window/OWindow.h"
#include <windows.h>
#include <assert.h>

OWindow::OWindow()
{

    WNDCLASSEX wc = {};             // This line initializes an instance of the WNDCLASSEX structure named wc to all zeros.
    wc.cbSize = sizeof(WNDCLASSEX); // sets the cbSize member of the WNDCLASSEX structure wc to the size of the WNDCLASSEX structure itself

    wc.lpszClassName = TEXT("OG3DWindow");
    // wc.lpszClassName = L"OG3DWindow"; // The lpszClassName member is where you specify the unique name by which the window class will be known.
    wc.lpfnWndProc = DefWindowProc; // The lpfnWndProc member is a pointer to the window procedure that you want to associate with this window class.

    // we need to register this class in order to let the operating system know about it and use it

    assert(RegisterClassEx(&wc)); // The RegisterClassEx function takes a pointer to a WNDCLASSEX structure and a handle to the application instance as its parameters. It returns a class atom that uniquely identifies the window class. If the function fails, it returns zero.
    // The assert macro is used to check for errors during runtime. If the expression inside the assert macro evaluates to false, the program will terminate and an error message will be displayed.

    RECT rc = {0, 0, 1024, 768};                                           // The RECT structure defines the coordinates of the upper-left and lower-right corners of a rectangle.
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false); // The AdjustWindowRect function takes a pointer to a RECT structure and a window style as its parameters. It returns a RECT structure with the coordinates of the window adjusted to account for the window style.

    m_handle = CreateWindowExW(0, L"OG3DWindow", L"Osswa's openGL 3d game", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

    assert(m_handle);

    // to store the old window instance pointer in a secific data structure
    SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow((HWND)m_handle, SW_SHOW); // The ShowWindow function takes a handle to a window and a show command as its parameters. It returns a Boolean value indicating success or failure. The show command can be one of the following values:
    UpdateWindow((HWND)m_handle);
}

OWindow::~OWindow()
{

    DestroyWindow((HWND)m_handle);
}

// to terminate the program when we close the window
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
    {
        OWindow *window = (OWindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        break;
    }
    case WM_CLOSE:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}