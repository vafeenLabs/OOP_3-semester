#include <iostream>
using namespace std;

class Triad
{
protected:
    short a, b, c;

public:
    Triad(short _a = 0, short _b = 0, short _c = 0);
    void setA(short _A);
    void setB(short _B);
    void setC(short _C);

    short getA() const;
    short getB() const;
    short getC() const;

    Triad plusA(const short &_delta = 1);
    Triad plusB(const short &_delta = 1);
    Triad plusC(const short &_delta = 1);

    friend ostream &operator<<(ostream &stream, const Triad &object);
    friend istream &operator>>(istream &stream, Triad &object);
};

class Time : Triad
{
#define hours a
#define minutes b
#define seconds c
public:
    Time(short _hours = 0, short _minutes = 0, short _seconds = 0) : Triad(_hours, _minutes, _seconds) {}

    void setA(short _h);
    void setB(short _m);
    void setC(short _s);

    

    void normalize();

    Time plusA(const short &_delta = 1);
    Time plusB(const short &_delta = 1);
    Time plusC(const short &_delta = 1);

    friend ostream &operator<<(ostream &stream, const Time &object);
    friend istream &operator>>(istream &stream, Time &object);
};