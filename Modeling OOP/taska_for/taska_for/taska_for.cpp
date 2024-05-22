// taska_for.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
class MFun {
public:
    int argnum;
    MFun(int argnum) :
        argnum(argnum)
    {};
    virtual double func(std::vector<double> a) = 0;
};
/*
class EF1 : public MFun {
public:
    EF1() :
        MFun(4)
    {};
    double func(std::vector<double> a) {
        double q = a[0];
        double h = a[1];
        double ro = a[2];
        double p = a[3];
        return (9.81 * ro * q * h) / (p * 1000);
    }
};
*/
class EF: public MFun {
public:
    EF() :
        MFun(4)
    {};
    double func(std::vector<double> a) {
        double q = a[0];
        double h = a[1]; 
        double ro = a[2]; 
        double p = a[3];
        return (9.81 * ro * q * h) / (p * 1000);
    }
};

class PN : public MFun {
public:
    PN() :
        MFun(5)
    {};
    double func(std::vector<double> a) {
        double q = a[0];
        double h = a[1];
        double ro = a[2];
        double p = a[3];
        double p_n = a[4];
        std::vector <double> a1;
        for (int i = 0; i < a.size() - 1; i++) {
            a1.push_back(a[i]);
        }
        EF *mEF = new EF();
        return (9.81 * ro * q * h) / (p_n * 1000 * mEF->func(a1));
    }
};
class Pump {
public:
    std::vector <double> params;
    std::vector <MFun*> funs;
    Pump(std::vector <double> params){
        this->params = params;
    };
    void addFun(MFun* f) {
        this->funs.push_back(f);
    }
    void changePar(std::vector <double> new_args) {
        this->params = new_args;
    }
    double retFun() {
        for (int i = 0; i < this->funs.size(); i++) {
            if (funs[i]->argnum == this->params.size()) {
                return funs[i]->func(params);
            }
        }
        std::cout << "no function";
    }
};

int main()
{
    std::vector<double> a = { 1, 2, 3, 4, 5 };
    std::cout << a.size() << std::endl;
    PN* f1 = new PN();
    EF* f2 = new EF();
    Pump* this_pump = new Pump(a);
    this_pump->addFun(f1);
    this_pump->addFun(f2);
    std::cout << this_pump->retFun() << std::endl;
    a = { 1, 2, 3, 4 };
    this_pump->changePar(a);
    std::cout << this_pump->retFun();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
