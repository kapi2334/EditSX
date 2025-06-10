#include <Windows.h>
#include <string>
#include <wchar.h>
namespace sxEditCore{
    class KeyActionHander{
        private:
            WCHAR getCharFromWparam(WPARAM key){
                WCHAR tmp[2];
                tmp[0] = (WCHAR)key;
                tmp[1] = L'\0';
                //Checking if SHIFT or CAPS are pressed
                bool shift = (GetKeyState(VK_SHIFT)&0x8000) != 0; //Checking if 15th bit = 1 - it means that shift is pressed.
                bool caps = (GetKeyState(VK_CAPITAL)&0x0001) !=0; //Checking if first bit = 1 - it means that shift is pressed.
                if(!(shift ^ caps)){ //!XOR 
                    tmp[0] = towlower(tmp[0]);
                }
                    
                return *tmp;
            }
        public:
            void registerPress(WPARAM key, HWND hwnd){
                /*switch(key){
                    case 0x09: //TAB
                    case 0x0D: //ENTER
                    break;
                }*/
                //Normal button clicked
                if(key >= 0x30 && key <= 0x5A){
                    WCHAR tmp = getCharFromWparam(key);

                    MessageBoxW(hwnd,&tmp,L"Button clicked", MB_OK);
                }
            }
    };


}
