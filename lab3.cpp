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
    virtual ~Figura() {}

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

    void push(const Figura& n_fig)
    {
        tablica[licznikFigur] = n_fig;
        licznikFigur += 1;
    }
    void printLicznik() { std::cout << "Licznik = " << licznikFigur << std::endl; }

private:
    Figura* tablica;
    int     licznikFigur;
};

void id(Figura* A)
{
    A->id();
}

int main()
{
    Kolo    k1(4);
    Kwadrat k2(3);
    Figura  k3(5);

    WektorFigur w1;
    w1.push(k1);
    w1.printLicznik();
    w1[0]->id();

    w1.push(k2);
    w1.printLicznik();
    id(w1[1]);

    w1.push(k3);
    w1.printLicznik();
    id(w1[2]);

    puts("\nOstatnia linijka w kodzie");
}