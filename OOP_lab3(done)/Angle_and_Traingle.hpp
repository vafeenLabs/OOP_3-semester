#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

const double PI = acos(-1.0);
class Angle
{
    short degrees;
    short minutes;

public: // 1 градус= 60 минут
    short get_degrees() const;
    void set_degrees(float _degrees, float _minutes = 0);
    short get_minutes() const;
    Angle(float _degrees = 0, short _minutes = 0);
    string toString();
    // операция << и >>
    friend ostream &operator<<(ostream &stream, const Angle &object);

    friend istream &operator>>(istream &stream, Angle &object);

    // перевод в радианы
    float toRadians();
    // возвращает нормализованную копию в диапаоне 0-360
    Angle normalize();
    // нормализует СЕБЯ в диапаоне 0-360
    void normalize_self();
    // увеличение и уменьшение на заданную величину
    void plusMinusDegreesMinutes(short delta_degrees = 0, short delta_minutes = 0);

    float sinus();
    bool operator==(const Angle &object);
};

class Traingle
{
    float a, b, c;
    Angle angle1, angle2, angle3;

public:
    Traingle(float _a, float _b, float _c);
    float get_a();
    float get_b();
    float get_c();
    // высота к а
    float get_ah();
    // высота к b
    float get_bh();
    // высота к c
    float get_ch();

    void set_a(float _a);
    void set_b(float _b);
    void set_c(float _c);
    // Периметр
    float Perimetr();
    // Площадь
    float Square();

    // операция << и >>
    friend ostream &operator<<(ostream &stream, Traingle &object);

    friend istream &operator>>(istream &stream, Traingle &object);

    // определение вида треугольника
    string kindOfTraingle();
    // может ли получиться треугольник с такими координатами
    bool true_lens(float _a, float _b, float _c);

    void do_angles();
};