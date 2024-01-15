#include "../../../headerFiles/OGL3D/game/OGame.h"
#include "../../../headerFiles/OGL3D/window/OWindow.h"
#include "../../../headerFiles/OGL3D/graphics/OGraphEng.h"
#include <windows.h>

OGame::OGame()
{
    m_graphEng = std::unique_ptr<OGraphEng>();
    m_window = std::unique_ptr<OWindow>();
}

OGame::~OGame()
{
}

void OGame::run()
{

    while (m_isRunning)
    {
        MSG msg = {};
        if (PeekMessage(&msg, HWND(), 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                m_isRunning = false;
                continue;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            Sleep(1);
        }
    }
}

// pm_remove allows for removing every message from the queue every time PeekMessage is called

void OGame::quit()
{
    m_isRunning = false;
}