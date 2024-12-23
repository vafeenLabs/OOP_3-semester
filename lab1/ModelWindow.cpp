#include "ModelWindow.hpp"
ModelWindow::ModelWindow(const string &arg_header_of_window, const short &koords_x, const short &koords_y, const short &arg_size_of_window_x, const short &arg_size_of_window_y, const bool &arg_state_of_window, const bool &arg_state_of_frame)
{
    header_of_window = arg_header_of_window;
    koords_of_left_korner.x = koords_x;
    koords_of_left_korner.y = koords_y;
    size_of_window.x = arg_size_of_window_x;
    size_of_window.y = arg_size_of_window_y;
    state_of_window = arg_state_of_window;
    state_of_frame = arg_state_of_frame;
}

koords ModelWindow::get_size_of_window()
{
    koords structure;
    structure.x = size_of_window.x;
    structure.y = size_of_window.y;
    return structure;
}
void ModelWindow::set_size_of_window(const short &x, const short &y)
{
    if (x > 0 && x <= MAX_X)
        size_of_window.x = x;
    else if (x > MAX_X)
        size_of_window.x = MAX_X;
    else
        size_of_window.x = 1;
    if (y > 0 && y <= MAX_Y)
        size_of_window.y = y;
    else if (y > MAX_Y)
        size_of_window.y = MAX_Y;
    else
        size_of_window.y = 1;
}
koords ModelWindow::get_koords_of_left_korner()
{
    koords structure;
    structure.x = koords_of_left_korner.x;
    structure.y = koords_of_left_korner.y;
    return structure;
}
void ModelWindow::set_koords_of_left_korner(const short &x, const short &y)
{
    if (x > 0 && x <= MAX_X)
        koords_of_left_korner.x = x;
    else if (x > MAX_X)
        koords_of_left_korner.x = MAX_X;
    else
        koords_of_left_korner.x = 1;
    if (y > 0 && y <= MAX_Y)
        koords_of_left_korner.y = y;
    else if (y > MAX_Y)
        koords_of_left_korner.y = MAX_Y;
    else
        koords_of_left_korner.y = 1;
}
void ModelWindow::set_header_of_window(const string &header)
{
    header_of_window = header;
}
string ModelWindow::get_header_of_window()
{
    return header_of_window;
}
string ModelWindow::toString()
{
    return "header=" + header_of_window + ", size = (" + to_string(size_of_window.x) + ", " + to_string(size_of_window.y) + "),\nleft korner = (" + to_string(koords_of_left_korner.x) + ", " + to_string(koords_of_left_korner.y) +
           "), right corner = (" + to_string(koords_of_left_korner.x + size_of_window.x) + ", " + to_string(koords_of_left_korner.y + size_of_window.y) + "), \nstate_of_window(vis/invis) = " + to_string(state_of_window) + ", state_of_frame(yes\\no) = " + to_string(state_of_frame);
}

void ModelWindow::moving_of_window()
{
    short move = -1;

    while (move != 48)
    {
        move = _getch();
        if (move == 224)
        {
            move = _getch();
            switch (move)
            {
            // вверх
            case MOVE_UP:
            {
                if (koords_of_left_korner.y > 0)
                {
                    koords_of_left_korner.y -= 1;
                }
                break;
            }
            // вниз
            case MOVE_DOWN:
            {
                if (koords_of_left_korner.y + size_of_window.y < MAX_Y)
                {
                    koords_of_left_korner.y += 1;
                }
                break;
            }
            // вправо
            case MOVE_RIGHT:
            {
                if (koords_of_left_korner.x + size_of_window.x < MAX_X)
                {
                    koords_of_left_korner.x += 1;
                }
                break;
            }
            // влево
            case MOVE_LEFT:
            {
                if (koords_of_left_korner.x > 0)
                {
                    koords_of_left_korner.x -= 1;
                }
                break;
            }
            }
        }
        cout << toString() << "\n\n";
    }

    // вверх 224 72
    // вниз 224 80
}

template <typename T>
void ModelWindow::cin_for_1_arg(T &arg)
{
    cin >> arg;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\nОшибка ввода! Повторите ввод!\n->";
        cin >> arg;
    }
}
template <typename T>
void ModelWindow::cin_for_2_koords(T &arg1, T &arg2)
{
    cin >> arg1 >> arg2;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\nОшибка ввода! Повторите ввод!\n->";
        cin >> arg1 >> arg2;
    }
}