#include <cmath>
#include <iostream>

const int SIZE = 10;

class BytGeometryczny
{
public:
    virtual void id() = 0;
};

class Figura : public BytGeometryczny
{
public:
    Figura() : pole{0.} {};
    Figura(double pole_in) : pole{pole_in} {}
    virtual ~Figura() {}

    double       getPole() const { return pole; }
    virtual void id() const { std::cout << "Figura o polu rownym " << pole << std::endl; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : Figura{M_PI * r_in * r_in} {}
    virtual ~Kolo() { std::cout << "Kolo zostalo zniszczone\n"; }

    void id() override { std::cout << "Kolo o polu rownym " << getPole() << std::endl; }
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : Figura{a_in * a_in} {}
    virtual ~Kwadrat() { std::cout << "Kwadrat zostal zniszczony\n"; }

    void id() override { std::cout << "Kwadrat o polu rownym " << getPole() << std::endl; }
};

void id(const Figura& A)
{
    A.id();
}

class WektorFigur
{
public:
    WektorFigur() : licznikFigur{0} { tablica = new Figura*[SIZE]; }
    ~WektorFigur()
    {
        if (*tablica != nullptr) {
            for (int i = 0; i < licznikFigur; i++)
                delete tablica[i];
        }
    }

    Figura* operator[](int n) const
    {
        if (n < licznikFigur)
            return tablica[n];
        else
            return nullptr;
    }

    void push(Figura* n_fig)
    {
        tablica[licznikFigur] = n_fig;
        licznikFigur += 1;
    }

    void pop()
    {
        if (licznikFigur > 0) {
            delete tablica[licznikFigur - 1];
            licznikFigur -= 1;
        }
    }

    void printLicznik() { std::cout << "Licznik = " << licznikFigur << std::endl; }

private:
    Figura** tablica;
    int      licznikFigur;
};

int main()
{
    Kolo    k1(4);
    Kwadrat k2(3);

    WektorFigur w1;
    w1.push(&k1);
    w1.printLicznik();
    w1[0]->id();

    w1.push(&k2);
    w1.printLicznik();
    w1[1]->id();

    std::cout << "Uzycie funkcji pop\n";
    w1.pop();
    w1.printLicznik();

    puts("\nOstatnia linijka w kodzie");
}