#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;
const short MAX_X = 1920, MAX_Y = 1080;
const short MOVE_UP = 72, MOVE_DOWN = 80, MOVE_RIGHT = 77, MOVE_LEFT = 75;
// enum StateOfWindow
// {
//     INVISIBLE,
//     VISIBLE

// };
// enum StateOfFrame
// {
//     NO,
//     YES
// };
struct koords
{
    short x;
    short y;
};
class ModelWindow
{
public:
    ModelWindow(const string &arg_header_of_window, const short &koords_x, const short &koords_y, const short &arg_size_of_window_x, const short &arg_size_of_window_y, const bool &arg_state_of_window, const bool &arg_state_of_frame);
    void moving_of_window();
    string toString();

    koords get_size_of_window();
    void set_size_of_window(const short &x, const short &y);

    koords get_koords_of_left_korner();
    void set_koords_of_left_korner(const short &x, const short &y);

    void set_header_of_window(const string &header);
    string get_header_of_window();

private:
    string header_of_window;
    koords koords_of_left_korner, size_of_window;
    // StateOfWindow state_of_window;
    // StateOfFrame state_of_frame;
    bool state_of_window;
    bool state_of_frame;
    template <typename T>
    void cin_for_2_koords(T &arg1, T &arg2);
    template <typename T>
    void cin_for_1_arg(T &arg);
};