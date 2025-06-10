//Window logic handling f.e. drawing, getting keys etc.
#include <windows.h>
#include <string.h>
#include <winuser.h>
#include "KeyActionHander.h"
namespace sxEditCore{

    class WindowsWindowLogic {
        private:
            int _windowLength;
            int _windowHeight;
            LPCSTR _windowName;
            LPCSTR _className;
            HINSTANCE _windowInstance;
            KeyActionHander _keyHander;

            HWND _windowHandle;

            static LRESULT CALLBACK Procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
                
                WindowsWindowLogic* pThis;

                //On window creation
                if(uMsg == WM_NCCREATE){
                    //Casting lParam as CREATESTRUCT pointer
                    CREATESTRUCT* cstruct = reinterpret_cast<CREATESTRUCT*>(lParam);
                    //Obtaining create params of our window
                    pThis = reinterpret_cast<WindowsWindowLogic*>(cstruct->lpCreateParams);
                    //Saving pointer to our class in userdata
                    SetWindowLongPtrA(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
                    
                }else{
                    //Saving pointer to our class in pThis
                    pThis = reinterpret_cast<WindowsWindowLogic*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));
                }
                if(pThis){
                    //If pThis obtained correctly - call window message handler
                    return pThis->HandleMessage(hwnd,uMsg,wParam,lParam);
                }
                //default procedure
                return DefWindowProcA(hwnd, uMsg, wParam, lParam);



            }

            LRESULT HandleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
                //Window message loop
                switch(uMsg){
                    case WM_DESTROY:
                        PostQuitMessage(0);
                        return 0;
                        //Setting min. window size    
                    case WM_GETMINMAXINFO:{
                        MINMAXINFO* minmax = (MINMAXINFO*)lParam;
                        minmax->ptMinTrackSize.x = 300;
                        minmax->ptMinTrackSize.y = 300;
                    }
                    case WM_KEYDOWN:
                        _keyHander.registerPress(wParam,hwnd);
                    default:
                        return DefWindowProc(hwnd,uMsg,wParam,lParam);
                }

            }

            WNDCLASS GetWindowClass(WNDPROC Proc){
                WNDCLASS wclass = {};
                wclass.lpfnWndProc = Proc;
                wclass.hInstance = _windowInstance;
                wclass.lpszClassName = _className;
                wclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+15);  
                return wclass;
            }

        public:
            //Default constructor
            WindowsWindowLogic(HINSTANCE instace = nullptr){
                _windowLength = 400;
                _windowHeight = 400;
                _windowName = "Window";
                _className = "Main Window Class";
                _windowInstance = instace;
            }
            //UserInput Constructor 
            WindowsWindowLogic(HINSTANCE instace, const char windowName[],const char windowClassName[], int length, int height){
                _windowLength = length;
                _windowHeight = height;
                _windowName = windowName;
                _className = windowClassName;
                _windowInstance = instace;
            }
            //Deconstructor
            ~WindowsWindowLogic(){
            }

            //Window creation
            bool Create(){
                WNDCLASS wClass = GetWindowClass(Procedure);
                RegisterClass(&wClass);

               _windowHandle = CreateWindowExA(
                        0,
                        _className,
                        _windowName,
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        _windowHeight, _windowLength,
                        nullptr, nullptr,
                        _windowInstance, this);
                //if _windowHandle is nullptr return false
               return _windowHandle != nullptr; 
            }
            //Show created window
            void Show(int nCmdShow, bool cmdWindowVisibility = true){
               if(!cmdWindowVisibility){
                    ShowWindow(GetConsoleWindow(),SW_HIDE);
               } 
               ShowWindow(_windowHandle,nCmdShow); 
            }

            
            


    };


}
