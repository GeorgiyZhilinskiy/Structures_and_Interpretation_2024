// Interface.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Figure
{
public:
    virtual double square() = 0;
};

class Rectangle :public Figure
{
public:
    double a;
    double b;

    Rectangle(double a, double b)
    {
        this->a = a;
        this->b = b;
    }

    double square()
    {
        return a * b;
    }
};


int main()
{
    Rectangle rect(2, 5);
    cout << rect.square()<<endl;
}

