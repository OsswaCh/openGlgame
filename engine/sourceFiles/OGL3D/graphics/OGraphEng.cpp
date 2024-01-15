#include "../../../headerFiles/OGL3D/graphics/OGraphEng.h"
#include "D:/code/openGLgame/glad/include/KHR/khrplatform.h"
// #include "D:/code/openGLgame/glad/include/glad/gl.h"
#include "gl.c"
#include "gl.h"
#include "wgl.c"
#include <windows.h>
#include <assert.h>
#include <stdexcept>

OGraphEng::OGraphEng()
{
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = TEXT("OG3DDummyWindow");
    wc.lpfnWndProc = DefWindowProc;
    wc.style = CS_OWNDC;

    auto classID = RegisterClassEx(&wc);
    assert(classID);

    LPCSTR winName = "";

    auto dummyWind = CreateWindowEx(0, MAKEINTATOM(classID), winName, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
                                    CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);
    // This shows an error but it actually works, ignore it

    assert(dummyWind);

    // to retrieve a specific pixel format, for teh window just created to be used for OpenGL rendering

    auto DummyDc = GetDC(dummyWind);

    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.iPixelType = PFD_TYPE_RGBA;                                           // 32 bit color
    pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER; // support for OpenGL, draw to window, double buffer
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;

    int pixFormat = ChoosePixelFormat(DummyDc, &pfd);
    SetPixelFormat(DummyDc, pixFormat, &pfd);

    // now we start creating the opengl context

    HGLRC dumContext = wglCreateContext(DummyDc); // we need the context to initialize the other opengl functions for all versions
                                                  // without the context we will not be able to load opengl
    assert(dumContext);

    bool res = wglMakeCurrent(DummyDc, dumContext);
    assert(res);

    // if (!gladLoadGL())
    // {
    //     throw std::runtime_error("Failed to initialize glad");
    // }

    ///////////////////////////////////////////find a way to include glad_wgl.h/////////////////////////////////////
    if (!gladLoadWGL(DummyDc, reinterpret_cast<GLADloadfunc>(wglGetProcAddress)))
    {
        throw std::runtime_error("Failed to initialize glad");
    }

    wglMakeCurrent(DummyDc, 0);
    wglDeleteContext(dumContext);
    ReleaseDC(dummyWind, DummyDc);
    DestroyWindow(dummyWind);
}

OGraphEng::~OGraphEng()
{
}
