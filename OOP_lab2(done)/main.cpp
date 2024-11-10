#include "FazzyNumber.hpp"
#include <conio.h>
int main()
{
    // объект и дельты!
    //  A1 = new float{x - e1};
    //  A2 = new float{x};
    //  A3 = new float{x + e2};
    FazzyNumber object1(0.1, 5, 0.2);
    FazzyNumber object2(0.1, 3, 0.2);
    FazzyNumber object3;

    while(true)
    {
        short num = _getch() - 48;
        system("cls");
        switch (num)
        {
        case 0:
        { // сложение
            object3 = object1 + object2;
            cout << object3; // 7.8 8 8.4
            break;
        }
        case 1:
        { // вычитание
            object3 = object1 - object2;
            cout << object3;
            break;
        }
        case 2:
        { // умножения
            object3 = object1 * object2;
            cout << object3;
            break;
        }
        case 3:
        { // обратное
            object3 = object1.opposite();
            cout << object3;
            break;
        }
        case 4:
        { // деление
            object3 = object1 / object2;
            cout << object3;
            break;
        }
        case 5:
        { // сравнение
            bool f = object1 == object2;
            cout << f;
            break;
        }
        case 6:
        { // присваивание
            object1 = object2;
            cout << object1;
            break;
        }
        case 7:
        { // сеттеры
            object1.set_e1(100.0);
            object1.set_a(100.0);
            object1.set_e2(100.0);
            cout << object1;
            break;
        }
        case 8:
        {
            // ввод
            cin >> object1;

            cout << object1;
        }

        }
    }
    cout << "\n\n\n";
    system("pause");
}