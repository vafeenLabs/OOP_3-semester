#include "FazzyNumber.hpp"
FazzyNumber::FazzyNumber()
{
    e1 = new float;
    a = new float;
    e2 = new float;
}
FazzyNumber::FazzyNumber(float arg_e1, float arg_x, float arg_e2)
{
    e1 = new float{arg_e1};
    a = new float{arg_x};
    e2 = new float{arg_e2};
}

FazzyNumber::FazzyNumber(const FazzyNumber &object)
{
    e1 = new float{*object.e1};
    a = new float{*object.a};
    e2 = new float{*object.e2};
}

FazzyNumber::~FazzyNumber()
{

    delete e1;
    e1 = nullptr;

    delete a;
    a = nullptr;

    delete e2;
    e2 = nullptr;
}

#define Ae1 (*e1)
#define A (*a)
#define Ae2 (*e2)

#define Be1 (*object.e1)
#define B (*object.a)
#define Be2 (*object.e2)
FazzyNumber FazzyNumber::operator+(const FazzyNumber &object)
{
    FazzyNumber result;
    result.set_e1((A - Ae1) + (B - Be1));
    result.set_a(A + B);
    result.set_e2((A + Ae2) + (B + Be2));
    return result;
}
FazzyNumber FazzyNumber::operator-(const FazzyNumber &object)
{
    FazzyNumber result;
    result.set_e1(A - B - Ae1 - Be1);
    result.set_a(A - B);
    result.set_e2(A - B + Ae2 + Be2);
    return result;
}

FazzyNumber FazzyNumber::operator*(const FazzyNumber &object)
{
    FazzyNumber result;
    result.set_e1((A - Ae1) * (B - Be1));
    result.set_a(A * B);
    result.set_e2((A + Ae2) * (B + Be2));
    return result;
}

FazzyNumber FazzyNumber::operator/(const FazzyNumber &object)
{
    FazzyNumber result;
    if (B != 0)
    {
        result.set_e1((A - Ae1) / (B + Be2));
        result.set_a(A / B);
        result.set_e2((A + Ae2) / (B - Be1));
    }
    return result;
}

FazzyNumber FazzyNumber::opposite()
{
    FazzyNumber result;
    if (A > 0)
    {
        result.set_e1(1 / (A + Ae2));
        result.set_a(1 / A);
        result.set_e2(1 / (A - Ae1));
    }
    return result;
}
bool FazzyNumber::operator>(const FazzyNumber &object)
{
    return (Ae1 > Be1 && A > B && Ae2 > Be2);
}
bool FazzyNumber::operator<(const FazzyNumber &object)
{
    return (Ae1 < Be1 && A < B && Ae2 < Be2);
}
bool FazzyNumber::operator==(const FazzyNumber &object)
{
    return (Ae1 == Be1 && A == B && Ae2 == Be2);
}

FazzyNumber &FazzyNumber::operator=(const FazzyNumber &object)
{
    set_e1(Be1);
    set_a(B);
    set_e2(Be2);
    return *this;
}
// Pair& operator=(const Pair& value)
// {
//     a = value.a;
//     b = value.b;
//     return *this;  
// }
// string FazzyNumber::toString()
// {
//     return "(" + to_string(Ae1) + ", " + to_string(A) + ", " + to_string(ar) + ")";
// }

ostream &operator<<(ostream &stream, FazzyNumber &object)
{
    stream << "Values: " << object.get_e1() << " " << object.get_a() << " " << object.get_e2();
    return stream;
}

istream &operator>>(istream &stream, FazzyNumber &object)
{

    // stream >> *object.Ae1 >> *object.a >> *object.e2;
    //  << ' ' >> object.get_A() >> ' ' >> object.get_ar();

    float x;
    stream >> x;
    object.set_e1(x);
    stream >> x;
    object.set_a(x);
    stream >> x;
    object.set_e2(x);
    return stream;
}
void FazzyNumber::set_e1(float value)
{
    Ae1 = value;
}
void FazzyNumber::set_a(float value)
{
    A = value;
}
void FazzyNumber::set_e2(float value)
{
    Ae2 = value;
}
float FazzyNumber::get_e1()
{
    return Ae1;
}
float FazzyNumber::get_a()
{
    return A;
}
float FazzyNumber::get_e2()
{
    return Ae2;
}