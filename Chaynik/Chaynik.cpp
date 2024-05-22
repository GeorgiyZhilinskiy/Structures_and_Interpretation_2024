#include <iostream>
using namespace std;


class Chainik
{
public:
    bool fullness; // наполнен чайник или нет
    bool posited; // помещен ли чайник куда-то
    bool boiled;  // вскипечен ли чайник
    Chainik():
        fullness(0),
        posited(0),
        boiled(0)
    {};
    bool isBoiled() {
        return boiled;
    }
    void boil() {
        this->boiled = true;
    }

    void removeFromChainik() // вылить воду из чайника
    {
        this->fullness = 0;
    }

};


class Tap
{
public:
    Tap()
    {
    }

    void putChainikUnderTap(Chainik *chainik) // помещаем под кран
    {
        if (chainik->posited == 0) // если чайник в руке
        {
            chainik->posited = 1; // помещаем его под раковину
            cout << "Чайник под краном" << endl;
        }
        else
            cout << "Поместить чайник под кран нельзя, т.к. он не в руке" << endl;
    }

    void removeChainikFromTap(Chainik* chainik) // убираем чайник из под крана
    {
        if (chainik->posited == 1) // если чайник под краном
        {
            chainik->posited = 0; // убираем его в руку
            cout << "Чайник в руке" << endl;
        }
        else
            cout << "Нельзя убрать чайник из под крана, т.к. он не под краном" << endl;

    }

    void fillChainik(Chainik* chainik) // наполнить чайник водой
    {
        if ((chainik->posited = 1) && (chainik->fullness == 0)) // если чайник под краном и пустой
        {
            chainik->fullness = 1; // наполняем чайник
            cout << "Чайник наполнен" << endl;
        }
        else
            if (chainik->posited = 0) // если чайник не под краном
                cout << "Нельзя наполнить чайник, т.к. он не под краном" << endl;
            else
                if (chainik->fullness = 0) // если чайник пустой
                    cout << "Нельзя наполнить чайник, т.к. он пустой" << endl;
                else
                    if (chainik->fullness == 1)
                        cout << "Нельзя наполнить чайник, т.к. он уже наполнен" << endl;
    }
};

class matchBox // коробка спичек
{
public:
    int match_count; // число спичек  коробке

    matchBox(int num)
    {
        match_count = num;
    }
};

class Cooker
{
public:
    void putOnCooker(Chainik* chainik) // поставить чайник на плиту
    {
        if (chainik->posited == 0) // если чайник в руке
        {
            chainik->posited = 1; // помещаем чайник на плиту
            cout << "Чайник на плите" << endl;
        }
        else
            cout << "Нельзя поставить чайник на плиту, т.к. он уже где-то" << endl; // (может быть и на плите в том числе)
    }

    void removeFromCooker(Chainik* chainik) // убрать чайник с плиты
    {
        if (chainik->posited == 1) // если чайник на плите
        {
            chainik->posited = 0; // берем чайник в руку
            cout << "Чайник в руке" << endl;
        }
        else
            cout << "Нельзя взять чайник  руку, т.к. он уже в руке" << endl;
    }

    void boil(Chainik* chainik, matchBox* Box) // кипечение чайника
    {
        if ((chainik != NULL) && (chainik->fullness == 1) && (Box->match_count != 0)) // если чайник на плите, в нем есть вода и есть спички в коробке
        {
            chainik->boil(); // вода вскипетилась
            cout << "Вода вскипятилась" << endl;
        }
        else
            if(chainik == NULL) // если чайник не на плите
                cout << "Вскипетить чайник нельзя, он не на плите"<<endl;
            else
                if (chainik->fullness == 0) // если чайник пустой
                    cout << "Вскипетить чайник нельзя, он пустой" << endl;
                else
                    if (Box->match_count == 0) // если спичек  коробке нет
                        cout << "Вскипетить чайник нельзя, нет спичек" << endl;

    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Chainik *chainik = new Chainik();
    Tap *tap = new Tap();
    matchBox *box = new matchBox(0);
    Cooker *cooker = new Cooker();

    tap->putChainikUnderTap(chainik);
    tap->fillChainik(chainik);
    tap->removeChainikFromTap(chainik);

    cooker->putOnCooker(chainik);
    cooker->boil(chainik, box);
    cooker->removeFromCooker(chainik);
}


