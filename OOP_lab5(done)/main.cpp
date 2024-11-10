#include "PointCircleRing.hpp"

int main()
{

     Circumference *p = new Ring(5, 4);
     cout << p->area() << '\n';
     // Circle *s = dynamic_cast<Circle *>(p);
     Circumference *s = new Circle(5);
     cout << "\n"
          << s->area();

     system("pause");
     return 0;
}
