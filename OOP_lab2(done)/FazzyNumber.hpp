#include <iostream>
// #include <string>
using std::istream;
using std::ostream;
using namespace std;

class FazzyNumber
// перегрузить знаки, оператор присваивания
{
public:
    // конструктор
    FazzyNumber(float arg_e1, float arg_x, float arg_e2);

    // констркутор без аргументов
    FazzyNumber();
    // констркуктор копирования
    FazzyNumber(const FazzyNumber &object);
    ~FazzyNumber();
    
    // сложение
    FazzyNumber operator+(const FazzyNumber &object);

    // вычитание
    FazzyNumber operator-(const FazzyNumber &object);

    // умножение
    FazzyNumber operator*(const FazzyNumber &object);

    // деление
    FazzyNumber operator/(const FazzyNumber &object);

    // обратное
    FazzyNumber opposite();

    // присвавивание
    FazzyNumber &operator=(const FazzyNumber &object);

    // сравнение
    bool operator==(const FazzyNumber &object);
    bool operator>(const FazzyNumber &object);
    bool operator<(const FazzyNumber &object);

    // string toString();

    // операция << и >>
    friend ostream &operator<<(ostream &stream, FazzyNumber &object);

    friend istream &operator>>(istream &stream, FazzyNumber &object);

    void set_e1(float value);
    void set_a(float value);
    void set_e2(float value);
    float get_e1();
    float get_a();
    float get_e2();

private:
    float *e1;
    float *a;
    float *e2;
};
