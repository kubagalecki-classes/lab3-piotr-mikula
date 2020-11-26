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

    void idWszystkie()
    {
        for (int i = 0; i < licznikFigur; i++)
            tablica[i]->id();
    }

    void printLicznik() { std::cout << "Licznik = " << licznikFigur << std::endl; }

private:
    Figura** tablica;
    int      licznikFigur;
};

class FabrykaFigur
{
public:
    Figura* operator()(const std::string& str, double n)
    {
        if (str == "Kwadrat")
            return (new Kwadrat{n});
        else if (str == "Kolo")
            return (new Kolo{n});
        else
            return nullptr;
    }
};

class WizytatorFigurBaza
{
    virtual void wizytuj(Kwadrat&) = 0;
    virtual void wizytuj(Kolo&)    = 0;
};

int main()
{
    WektorFigur  wektor;
    FabrykaFigur fabryka;
    wektor.push(fabryka("Kolo", 3));
    wektor.push(fabryka("Kwadrat", 5));
    wektor.pop();
    wektor.push(fabryka("Kwadrat", 2));
    wektor.push(fabryka("Kolo", 2));

    wektor.idWszystkie();
    puts("\nOstatnia linijka w kodzie");
}