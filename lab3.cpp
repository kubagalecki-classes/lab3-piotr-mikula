#include <iostream>

class BytGeometryczny
{
public:
    virtual void id() const = 0;
};

class Figura : public BytGeometryczny
{
public:
    Figura(double pole_in) : pole(pole_in) {}
    virtual ~Figura() {}

    double getPole() const { return pole; }
    // virtual void id() const { std::cout << "Figura o polu rownym " << pole << std::endl; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : Figura{3.1415 * r_in * r_in} {}
    virtual ~Kolo() { std::cout << "Kolo zostalo zniszczone\n"; }

    void id() const override { std::cout << "Kolo o polu rownym " << getPole() << std::endl; }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : Figura{a_in * a_in} {}
    virtual ~Kwadrat() { std::cout << "Kwadrat zostal zniszczony\n"; }

    void id() const override { std::cout << "Kwadrat o polu rownym " << getPole() << std::endl; }

private:
    double a;
};

class WektorFigur
{
public:
    WektorFigur(int n = 0) : licznikFigur{n} {};

private:
    Figura* tablica[100];
    int     licznikFigur;
};

void id(const Figura& A)
{
    A.id();
}

int main()
{

    puts("Ostatnia linijka w kodzie");
}