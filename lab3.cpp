#include <iostream>

class BytGeometryczny
{
public:
    virtual void id() = 0;
};

class Figura : public BytGeometryczny
{
public:
    Figura() : pole(0){};
    Figura(double pole_in) : pole(pole_in) {}
    virtual ~Figura() { std::cout << "Figura zniszczona" << std::endl; }

    double       getPole() const { return pole; }
    virtual void id() { std::cout << "Figura o polu rownym " << pole << std::endl; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : Figura{3.1415 * r_in * r_in} {}
    virtual ~Kolo() { std::cout << "Kolo zostalo zniszczone\n"; }

    void id() override { std::cout << "Kolo o polu rownym " << getPole() << std::endl; }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : Figura{a_in * a_in} {}
    virtual ~Kwadrat() { std::cout << "Kwadrat zostal zniszczony\n"; }

    void id() override { std::cout << "Kwadrat o polu rownym " << getPole() << std::endl; }

private:
    double a;
};

class WektorFigur
{
public:
    WektorFigur() : licznikFigur{0} { tablica = new Figura[100]; }
    ~WektorFigur() { delete[] tablica; }

    Figura* operator[](int n)
    {
        if (n < licznikFigur)
            return &tablica[n];
        else
            return nullptr;
    }

private:
    Figura* tablica;
    int     licznikFigur;
};

void id(Figura& A)
{
    A.id();
}

int main()
{
    Kolo    k1(4);
    Kwadrat k2(3);
    Figura  k3(5);

    puts("Ostatnia linijka w kodzie");
}