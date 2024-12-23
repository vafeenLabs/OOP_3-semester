#include "ModelWindow.hpp"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(65001);
    ModelWindow model("OOP", 0, 0, 1000, 1000, 0, 1);

    short key = 0;
    switch (key)
    {
    case 0:
    {
        model.moving_of_window();
        break;
    }
    case 1:
    {
        model.toString();
        break;
    }
    }

    system("pause");
    return 0;
}
