#include <iostream>

class Figura
{
public:
    Figura(double pole_in) : pole(pole_in) {}
    double getPole() { return pole; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : Figura{3.1415 * r_in * r_in}
    {
        std::cout << "Pole kola wynosi " << getPole() << std::endl;
    }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : Figura{a_in * a_in}
    {
        std::cout << "Pole kwadratu wynosi " << getPole() << std::endl;
    }

private:
    double a;
};

int main()
{
    Kolo    kolko{2};
    Kwadrat square{5};

    puts("Ostatnia linijka w kodzie");
}