#include <Windows.h>
#include <iostream>
#include <winuser.h>
namespace sxEditCore{
    class CursorHandler{
        private:
            int x = 0;
            int y = 0;
            int type = 0;
            /* 0 = |
             * 1 = _
             * */
            const int width = 2;
            const int height = 18;
            const int offsetX = 10;
            const int offsetY = 10;
            HWND  handle;
        public:
            CursorHandler(){
                std::cout<<"Creating cursor...\n";
            }

            void writeOutDebug(){
                std::cout<<"Cursor data:\n"
                    << "X:" << x << 
                    "\nY:" << y << 
                    "\nWidth:" << width << 
                    "\nHeight:" << height << 
                    "\nRealX: "<< x + offsetX << 
                    "\nRealY:" << y + offsetY;
            }

            //Sets new X param 
            void updateCursorX(int newX){
                x = newX*width;
            } 

            //Sets new Y param 
            void updateCursorY(int newY){
                y = newY*height;
            } 

            //Moves cursor by X value
            void moveCursorByX(int x){
                this->x = this->x + (x*width);
            }

            //Moves cursor by Y value
            void moveCursorByY(int y){
                this->y = this->y + (y*height); 
            }
            int getXPosition(){
                return x;
            }
            int getYPosition(){
                return y;
            }
            void redraw(){
                InvalidateRect(handle,NULL,true);
                UpdateWindow(handle);
            }

            void drawCursor(HWND hwnd, PAINTSTRUCT ps){
                std::cout<<"Drawing cursor...";
                handle = hwnd;
                writeOutDebug();
                HDC deviceHande = BeginPaint(hwnd, &ps);
                HPEN cursorPen = CreatePen(PS_SOLID, 1,RGB(255,255,255));
                HPEN oldPen = (HPEN) SelectObject(deviceHande, cursorPen);
                switch(type){
                    case 0:{
                    Rectangle(deviceHande,x+offsetX,y+offsetY,(width+x+offsetX),(height+y+offsetY));
                    break;
                    }
                    case 1:{
                    Rectangle(deviceHande,x+offsetX,y+offsetY+(height-(width+x+offsetX)),(height+y+offsetY),(width+x+offsetX));
                    break;
                    }
                }
                SelectObject(deviceHande, oldPen);
                DeleteObject(cursorPen);
                EndPaint(hwnd, &ps);
                redraw();
            }
    };


}


