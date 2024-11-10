#include "Angle_and_Traingle.hpp"
short Angle::get_degrees() const
{
    return degrees;
}
void Angle::set_degrees(float _degrees, float _minutes)
{
    degrees = trunc(_degrees);
    minutes = _minutes;
    if (_degrees != trunc(_degrees))
    {
        float delta = (_degrees - degrees) * 60;
        minutes += delta;
    }
}
// void Angle::set_minutes(short _minutes)
// {
//     minutes = _minutes;
//     if (minutes != 0)
//     {                                        // в любом случае, кроме 0 превращаем часть минут в градусы по возможности
//         short cel_deg = trunc(minutes / 60); // берем из минут градусы
//         degrees += cel_deg;                  // добавляем к градусам
//         minutes = minutes % 60;              // минуты становятся минутами по mod60}
//     }
// }
short Angle::get_minutes() const
{
    return minutes;
}
Angle::Angle(float _degrees, short _minutes)
{
    set_degrees(_degrees, _minutes);
}
string Angle::toString()
{
    return "{" + to_string(degrees) + "'" + to_string(minutes) + "}";
}
// перевод в радианы
float Angle::toRadians()
{
    return (degrees + minutes / 60) * PI / 180;
}
// возвращает нормализованную копирю в диапаоне 0-360
Angle Angle::normalize()
{
    return Angle(degrees % 360, minutes);
}
// нормализует себя в диапаоне 0-360
void Angle::normalize_self()
{
    degrees = degrees % 360;
}
// увеличение и уменьшение на заданную величину
void Angle::plusMinusDegreesMinutes(short delta_degrees, short delta_minutes)
{
    // добавляем обе величины к числам
    degrees += delta_degrees;
    minutes += delta_minutes;
    if (minutes != 0)
    {
        short cel_deg = trunc(minutes / 60); // берем из минут градусы
        degrees += cel_deg;                  // добавляем к градусам
        minutes = minutes % 60;              // минуты становятся минутами по mod60
    }
}

float Angle::sinus()
{
    return sin(toRadians());
}
bool Angle::operator==(const Angle &object)
{
    return (degrees == object.get_degrees() && minutes == object.get_minutes());
}
ostream &operator<<(ostream &stream, const Angle &object)
{
    string str_minutes = "";
    short min = object.get_minutes();
    if (min < 10)
        str_minutes = "0" + to_string(min);
    else
        str_minutes = to_string(min);
    stream << "(" << object.get_degrees() << "'" << str_minutes << ")";
    return stream;
}

istream &operator>>(istream &stream, Angle &object)
{
    float deg, min;
    stream >> deg >> min;
    object.set_degrees(deg, min);
    return stream;
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

Traingle::Traingle(float _a, float _b, float _c)
{
    if (true_lens(_a, _b, _c))
    {
        a = _a;
        b = _b;
        c = _c;
    }
    else
    {
        a = 0;
        b = 0;
        c = 0;
    }
    do_angles();
}
float Traingle::get_a()
{
    return a;
}
float Traingle::get_b()
{
    return b;
}
float Traingle::get_c()
{
    return c;
}
// высота к а
float Traingle::get_ah()
{
    return (2 * Square() / a);
}
// высота к b
float Traingle::get_bh()
{
    return (2 * Square() / b);
}
// высота к c
float Traingle::get_ch()
{
    return (2 * Square() / c);
}

void Traingle::set_a(float _a)
{
    if (true_lens(_a, b, c))
    {
        a = _a;
        do_angles();
    }
}
void Traingle::set_b(float _b)
{
    if (true_lens(a, _b, c))
    {
        b = _b;
        do_angles();
    }
}
void Traingle::set_c(float _c)
{
    if (true_lens(a, b, _c))
    {
        c = _c;
        do_angles();
    }
}
// Периметр
float Traingle::Perimetr()
{
    return (a + b + c);
}
// Площадь
float Traingle::Square()
{
    float pPer = Perimetr() / 2;
    return pow((pPer * (pPer - a) * (pPer - b) * (pPer - c)), 0.5);
}

// определение вида треугольника
string Traingle::kindOfTraingle()
{
    string result = "";
    if (a == b && b == c)
    {
        if (result != "")
            result += " и ";
        result += "Равносторонний";
    }
    if (a == b || b == c || a == c)
    {
        if (result != "")
            result += " и ";
        result += "Равнобедренный";
    }
    if (angle1.get_degrees() == 90 || angle2.get_degrees() == 90 || angle3.get_degrees() == 90)
    {
        if (result != "")
            result += " и ";
        result += "Прямоугольный";
    }
    if (result == "")
        return "Обычный";
    return result;
}
void Traingle::do_angles()
{
    if (a != 0 && b != 0 && c != 0)
    // a = 3 b = 4 c = 5
    {
        angle1.set_degrees(acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI);
        angle2.set_degrees(acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI);
        float deg1, min1 = 0;
        deg1 = 180 - angle1.get_degrees() - angle2.get_degrees();
        if (angle1.get_minutes() + angle2.get_minutes() > 0)
        {
            deg1 -= 1;
            min1 = 60 - angle1.get_minutes() - angle2.get_minutes();
        }
        angle3.set_degrees(deg1, min1);
    }
    else
    {
        angle1.set_degrees(0, 0);
        angle2.set_degrees(0, 0);
        angle3.set_degrees(0, 0);
    }
}
bool Traingle::true_lens(float _a, float _b, float _c)
{
    bool f = true;
    if (_a >= _b + _c)
        f = false;
    if (_b >= _a + _c)
        f = false;
    if (_c >= _a + _b)
        f = false;
    return f;
}

ostream &operator<<(ostream &stream, Traingle &object)
{
    stream << object.get_a() << ' ' << object.get_b() << ' ' << object.get_c() << '\n'
           << object.angle1 << ' ' << object.angle2 << ' ' << object.angle3 << '\n';
}

istream &operator>>(istream &stream, Traingle &object)
{
    float x;
    stream >> x;
    object.set_a(x);
    stream >> x;
    object.set_b(x);
    stream >> x;
    object.set_c(x);
}