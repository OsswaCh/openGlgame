
#include "D:/code/openGLgame/engine/headerFiles/OGL3D/game/OGame.h"
#include "D:/code/openGLgame/engine/sourceFiles/OGL3D/game/OGame.cpp"
#include "D:/code/openGLgame/engine/sourceFiles/OGL3D/window/OWindow.cpp"
#include <iostream>

int main()
{
    try
    {
        OGame game;
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
