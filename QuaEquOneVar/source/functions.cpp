#include "../header/EquGroup.h"
#include "../header/ConsoleSetting.h"

EquGroup group;

void Step2SolveAndOutput()
{
    typedef std::pair<ComplexNumber, ComplexNumber> Ty_X;
    std::vector<Ty_X> res = group.solveEquGroup();
    setOutputColor(2);
    std::cout << "* ���̼������!\n";
    setOutputColor();
    for (const Ty_X &a : res) {
        static int i = 1;
        std::cout << "* |- ���� " << i++ << ": X = {(" << a.first << "), (" << a.second << ")} " << std::endl;
    }
    setOutputColor(2);
    std::cout << "* ========== \n" << std::endl;
    setOutputColor();
}

void Step1InputEquationGroup()
{
    setOutputColor(2);
    std::cout << "* ���뷽�̸���: ";
    int size = 0;
    std::cin >> size;
    group.reSetSize(size);
    std::vector<Equation> equations(size);
    std::cout << "* ����ʹ���˹�ʽ (rand() % 7 + 1) ^ 2 ������� {0,1,3,4,5,6,7} �е�Ԫ��, �����趨��ȥ��ɫ�������ɫ. \n";
    for (Equation &e : equations) {
        static int i = 1;
        // Set seed for rand():
        srand(unsigned int(i * time(0)));
        setOutputColor(int((rand() % 7 + 1) ^ 2));
        std::cout << "* ����� " << i++ << " �����̵�����ϵ��(�Կո�ָ�): ";
        std::cin >> e;
    }
    setOutputColor(2);
    group.setGroup(equations);
    std::cout << "\n* �������趨���." << std::endl;
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
    std::cout << "******************************\n* --- һԪ���η��̼����� --- *\n* --- Made By JamesNULLiu -- *\n******************************\n\n";
    setOutputColor(6);
    std::cout << "*  ������:\n"
        << "* 1. ������ class ComplexNumber, ������ + - * / > < = �Լ� << >> �����, ֮�����м����� ComplexNumber �Ķ���Ϊ����.\n"
        << "* 2. ���� std::vector<ComplexNumber>, ������ class Equation ���Ա�ʾ��������, ������ [] << >> = �����, ���� calculateDelta() ����.\n"
        << "* 3. ���� std::vector<Equation>, ������ class EquGroup �����ṩ���ɵķ�����������һԪ���η���.\n"
        << "* 4. ��ֶ���쳣�׳�, ���ڳ������.\n"
        << "* 5. �ṩ���Զ��庯���������ƿ���̨���ڴ�С�Լ���ɫ���.\n\n";
    setOutputColor();
}