#pragma once

class OWindow
{

private:
    void *m_handle = nullptr; // void pointer is used to hold the address of a memory location without specifying the type of data that is being pointed to.

public:
    OWindow();
    ~OWindow();
};