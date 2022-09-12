#include "../header/EquGroup.h"
#include "../header/ConsoleSetting.h"

EquGroup group;

void Step2SolveAndOutput()
{
    typedef std::pair<ComplexNumber, ComplexNumber> Ty_X;
    std::vector<Ty_X> res = group.solveEquGroup();
    setOutputColor(2);
    std::cout << "* 方程计算完成!\n";
    setOutputColor();
    for (const Ty_X &a : res) {
        static int i = 1;
        std::cout << "* |- 方程 " << i++ << ": X = {(" << a.first << "), (" << a.second << ")} " << std::endl;
    }
    setOutputColor(2);
    std::cout << "* ========== \n" << std::endl;
    setOutputColor();
}

void Step1InputEquationGroup()
{
    setOutputColor(2);
    std::cout << "* 输入方程个数: ";
    int size = 0;
    std::cin >> size;
    group.reSetSize(size);
    std::vector<Equation> equations(size);
    std::cout << "* 这里使用了公式 (rand() % 7 + 1) ^ 2 随机产生 {0,1,3,4,5,6,7} 中的元素, 用来设定除去绿色的随机颜色. \n";
    for (Equation &e : equations) {
        static int i = 1;
        // Set seed for rand():
        srand(unsigned int(i * time(0)));
        setOutputColor(int((rand() % 7 + 1) ^ 2));
        std::cout << "* 输入第 " << i++ << " 个方程的三个系数(以空格分割): ";
        std::cin >> e;
    }
    setOutputColor(2);
    group.setGroup(equations);
    std::cout << "\n* 方程组设定完成." << std::endl;
    setOutputColor();
    group.showGroup();
    setOutputColor(2);
    std::cout << "* ========== \n" << std::endl;
    setOutputColor();
    std::cout << std::endl;
}

void Step0Welcome()
{
    windowSize("100", "135", false);
    setOutputColor(4);
    std::cout << "******************************\n* --- 一元二次方程计算器 --- *\n* --- Made By JamesNULLiu -- *\n******************************\n\n";
    setOutputColor(6);
    std::cout << "*  技术点:\n"
        << "* 1. 定义了 class ComplexNumber, 重载了 + - * / > < = 以及 << >> 运算符, 之后所有计算以 ComplexNumber 的对象为基础.\n"
        << "* 2. 基于 std::vector<ComplexNumber>, 定义了 class Equation 用以表示单个方程, 重载了 [] << >> = 运算符, 内置 calculateDelta() 方法.\n"
        << "* 3. 基于 std::vector<Equation>, 定义了 class EquGroup 用以提供集成的方法处理复数个一元二次方程.\n"
        << "* 4. 充分多的异常抛出, 便于程序测试.\n"
        << "* 5. 提供了自定义函数用来限制控制台窗口大小以及彩色输出.\n\n";
    setOutputColor();
}