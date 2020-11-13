#include <iostream>

class Figura
{
public:
    void   setPole(double p) { pole = p; }
    double getPole() { return pole; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : r(r_in)
    {
        setPole(3.1415 * r * r);
        std::cout << "Pole kola wynosi " << getPole() << std::endl;
    }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : a(a_in)
    {
        setPole(a * a);
        std::cout << "Pole kwadratu wynosi " << getPole() << std::endl;
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