#include "../header/EquGroup.h"
#include "../header/functions.h"
#include "../header/ConsoleSetting.h"
#include "string.h"

int main()
{
    const char *p1 = "aaa";
    const char *p2 = "bbb";
    char *pp = const_cast<char *>(p2);
    char a[20] = "ddd";
    char *pa = a;

    std::swap(pa, pp);

    std::cout << p1;
    Step0Welcome();
    Step1InputEquationGroup();
    Step2SolveAndOutput();
    std::cin.ignore((std::numeric_limits< std::streamsize >::max)(), '\n');
    setOutputColor(2);
    std::cout << "* °´ ENTER ÖÕÖ¹³ÌÐò: ";
    std::cin.get();
}