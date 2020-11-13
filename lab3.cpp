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
    void printKolo() { std::cout << "Klasa Kolo, dziedzicze po Figura\n"; }
};

class Kwadrat : public Figura
{
public:
    void printKwadrat() { std::cout << "Klasa Kwadrat, dziedzicze po Figura\n"; }
};

int main()
{
    Kwadrat kwad;
    Kolo    kol;
    kwad.printKwadrat();
    kol.printKolo();

    puts("Ostatnia linijka w kodzie");
}
