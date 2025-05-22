//Window logic handling f.e. drawing, getting keys etc.
#include <windows.h>
#include <winuser.h>
namespace sxEditCore{

    class WindowsWindowLogic {
        public:
            LRESULT CALLBACK Procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
                //Window message loop
                switch(uMsg){
                    case WM_DESTROY:
                        PostQuitMessage(0);
                        return 0;
                    default:
                        return DefWindowProc(hwnd,uMsg,wParam,lParam);
                }

            }
            
            WNDCLASS RegisterWindow(LRESULT Proc, HINSTANCE WinHandle, const char WinName[]){
                WNDCLASS wclass = {};
                wclass.lpfnWndProc = Proc;
                wclass.hInstance = WinHandle;
                wclass.lpszClassName = WinName;
                return wclass;
            }
            


    };


}
