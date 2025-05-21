#include <iostream>
#include <Windows.h>
#include <minwindef.h>
#include "Window.h"

#if defined(_WIN64) || defined(_WIN32)

    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR,int nCmdShow){
        
        return 1; 

    }

#elif defined(__linux__)
#elif defined(__APPLE__) && defined(__MACH__)
#endif        
