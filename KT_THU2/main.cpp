/*********Mai Sĩ Tuấn - 2001216281****************/
#include <iostream>
#include <Windows.h>
#include "kt.h"
using namespace std;

void menuKiemTra()
{
    
}

void main()
{
    SetConsoleOutputCP(CP_UTF8);
    char chonCau = 48;
    do
    {
        system("cls");
        menuKiemTra();
        cout << "\nChọn câu: ";
        cin >> chonCau;
        switch (chonCau)
        {
        case 48:
        {
            cout << "Thoát" << endl;
            break;
        }
        case 'a':
        {
            break;
        }
        case 'b':
        {
            break;
        }
        case 'c':
        {
            break;
        }
        case 'd':
        {
            break;
        }
        default:
            break;
        }
        system("pause");
    } while (chonCau != 48);
}