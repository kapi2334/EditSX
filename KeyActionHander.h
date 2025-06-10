#include <Windows.h>
#include <string>
#include <winnt.h>
namespace sxEditCore{
    class KeyActionHander{
        public:
            void registerPress(WPARAM key, HWND hwnd){
                if(key >= 0x30 && key <= 0x5A){
                    WCHAR tmp[2];
                    tmp[0] = (WCHAR)key;
                    tmp[1] = L'\0';
                    MessageBoxW(hwnd,tmp, L"Wcisnieto przycisk", MB_OK);

                }
            }
    };


}
