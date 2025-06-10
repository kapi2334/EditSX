#include <Windows.h>
namespace sxEditCore{
    class CursorHandler{
        private:
            int x = 0;
            int y = 0;
            const int width = 2;
            const int height = 2;
        public:
            //Sets new X param 
            void updateCursorX(int newX){
                x = newX;
            } 

            //Sets new Y param 
            void updateCursorY(int newY){
                y = newY;
            } 

            //Moves cursor by X value
            void moveCursorByX(int x){
                this->x = this->x + x;
            }

            //Moves cursor by Y value
            void moveCursorByY(int y){
                this->y = this->y + y; 
            }

            void drawCursor(HWND hwnd, PAINTSTRUCT ps){
                HDC deviceHande = BeginPaint(hwnd, &ps);
                    MoveToEx(deviceHande,x,y,NULL);
                    LineTo(deviceHande,x+width,y+height);
                EndPaint(hwnd, &ps);
            }
    };


}


