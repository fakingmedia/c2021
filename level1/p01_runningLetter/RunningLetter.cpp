#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main()
{
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO scr;
    int times = 0, direction = 0;
    char ch;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut, &scr);
    cin >> ch;
    while (1)
    {
        for (int i = 0; i < times; i++)
            cout << " ";
        cout << ch;
        system("cls");
        if (direction == 0)
            times++;
        else
            times--;
        if (times == 0)
            direction = 0;
        if (times == scr.dwMaximumWindowSize.X)
            direction = 1;
    }

    return 0;
}
