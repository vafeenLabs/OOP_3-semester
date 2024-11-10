#include "class.hpp"
#include <conio.h>
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Traingle tr1(5, 6, 5);
    cout << tr1;
    bool f = true;
    while (f)
    {
        short key = getch() - 48;
        system("cls");
        switch (key)
        {
        case 0:
            // высоты
            cout << tr1.get_ah() << ' ' << tr1.get_bh() << ' ' << tr1.get_ch() << '\n';
            break;
        case 1:
            tr1.set_a(3);
            tr1.set_b(4);
            tr1.set_c(5);
            cout << tr1;
            break;
        case 2:
            tr1.set_a(5);
            tr1.set_b(5);
            tr1.set_c(5);
            cout << tr1;
            break;
        case 3:
            // периметр, площадь и вид
            cout << tr1.Perimetr() << ' ' << tr1.Square() << '\n';
            cout << tr1.kindOfTraingle() << '\n';
            break;
        }
    }

    system("pause");
    return 0;
}