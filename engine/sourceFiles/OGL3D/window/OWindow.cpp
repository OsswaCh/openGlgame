#include <OWindow.h>
#include <windows.h>

OWindow::OWindow()
{

    WNDCLASSEX wc = {};             // This line initializes an instance of the WNDCLASSEX structure named wc to all zeros.
    wc.cbSize = sizeof(WNDCLASSEX); // sets the cbSize member of the WNDCLASSEX structure wc to the size of the WNDCLASSEX structure itself
}

OWindow::~OWindow()
{
}