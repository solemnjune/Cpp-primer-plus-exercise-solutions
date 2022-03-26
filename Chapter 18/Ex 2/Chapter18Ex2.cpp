//компилировать вместе с файлом Cpmv.cpp
#include "Cpmv.h"
int main()
{
    std::cout << "Empty constructor: \n";
    Cpmv test1;
    std::string a = "qtest";
    std::string b = "ztest";
    std::cout << "2 string constructor: \n";
    Cpmv test2(a, b);
    std::cout << "\ntest2 display:\n";
    test2.Display();
    std::cout << std::endl;

    std::cout << "Copy constructor: \n";
    Cpmv test3(test2);
    std::cout << "\ntest3 display:\n";
    test3.Display();
    std::cout << std::endl;

    a = "new qqq";
    b = "new zzz";
    std::cout << "2 string constructor + move assignment: \n";
    test3 = Cpmv(a, b);
    std::cout << "\ntest3 display:\n";
    test3.Display();
    std::cout << std::endl;

    std::cout << "Copy assignment operator: \n";
    test1 = test3;
    std::cout << "Plus operator + move assignment: \n";
    test3 = (test1 + test2);
    std::cout << "\ntest3 display:\n";
    test3.Display();
    std::cout << std::endl;


}
