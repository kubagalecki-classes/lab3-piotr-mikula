#include <iostream>

class Figura
{
public:
    Figura(double pole_in) : pole(pole_in) {}
    virtual ~Figura() {}

    double       getPole() const { return pole; }
    virtual void id() const { std::cout << "Figura o polu rownym " << pole << std::endl; }

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

void id(const Figura& A)
{
    A.id();
}

int main()
{
    Figura* f = new Kwadrat{4};
    id(*f);
    delete f;

    Figura* f2 = new Kolo{3};
    id(*f2);
    delete f2;

    puts("Ostatnia linijka w kodzie");
}