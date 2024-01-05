#pragma once

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
    OWindow *m_window = nullptr; // pointer to the window class
};