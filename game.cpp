#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
using namespace std;


BOOL set_coursor_posision(int x, int y){
     COORD c;
    c.X=x;
    c.Y=y;

    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    

}
bool is_virtual_key(int virtual_key){
    return GetAsyncKeyState(virtual_key) & 0x8000;
}

int main(){
    int moveX = 0, moveY = 0;
    set_coursor_posision(22,33);

    while (true)
    {
        if (is_virtual_key(VK_LEFT))
            --moveX;
        else if (is_virtual_key(VK_RIGHT))
            ++moveX;
        else if (is_virtual_key(VK_UP))
            --moveY;
        else if (is_virtual_key(VK_DOWN))
            ++moveY;
        else if (is_virtual_key(VK_ESCAPE))
            break;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        set_coursor_posision(5 + moveX, 5 + moveY );
        cout << "*";
    }


return 0;
}