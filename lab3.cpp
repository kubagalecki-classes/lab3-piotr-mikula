#include <iostream>

class Figura
{
public:
    double getPole() { return pole; }

protected:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : r(r_in)
    {
        pole = 3.1415 * r * r;
        std::cout << "Pole kola wynosi " << pole << std::endl;
    }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : a(a_in)
    {
        pole = a * a;
        std::cout << "Pole kwadratu wynosi " << pole << std::endl;
    }

private:
    double a;
};

int main()
{
    Kolo    kolko{3};
    Kwadrat square{4};

    puts("Ostatnia linijka w kodzie");
}