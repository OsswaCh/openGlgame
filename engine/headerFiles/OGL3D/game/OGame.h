#pragma once
#include <memory>

class OWindow;

class OGame
{
private:
public:
    OGame();
    ~OGame();

    void run(); // run the game
    void quit();

protected:
    bool m_isRunning = true;
    std::unique_ptr<OWindow> m_window; // smart pointer to the window class, when the destructor is called it automatically deletes the object
                                       //  also avoids memory leaks
};