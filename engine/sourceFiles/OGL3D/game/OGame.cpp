#include <D:/code/openGLgame/engine/headerFiles/OGL3D/game/OGame.h>
#include <D:/code/openGLgame/engine/headerFiles/OGL3D/window/OWindow.h>
#include <windows.h>

OGame::OGame()
{
}

OGame::~OGame()
{
}

void OGame::run()
{
    MSG msg;
    while (m_isRunning)
    {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
        {
            // if there is a messa the peekmessage function will return true
            TranslateMessage(&msg);
            DispatchMessage(&msg); // It sends the message to the window procedure associated with the window handle (HWND) specified in the msg structure
        }

        Sleep(1); // Sleep(1) is used to reduce the CPU usage of the game loop. It will cause the game loop to sleep for 1 millisecond each time it is called.
    }
}

// pm_remove allows for removing every message from the queue every time PeekMessage is called