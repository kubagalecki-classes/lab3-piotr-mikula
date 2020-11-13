#include <iostream>

class Figura
{
public:
    Figura(double pole_in) : pole(pole_in) {}
    ~Figura() {}

    double getPole() const { return pole; }
    void   id() const { std::cout << "Figura o polu rownym " << pole << std::endl; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo(double r_in) : Figura{3.1415 * r_in * r_in} {}
    ~Kolo() {}

    void id() const { std::cout << "Kolo o polu rownym " << getPole() << std::endl; }

private:
    double r;
};

class Kwadrat : public Figura
{
public:
    Kwadrat(double a_in) : Figura{a_in * a_in} {}
    ~Kwadrat() {}

    void id() const { std::cout << "Kwadrat o polu rownym " << getPole() << std::endl; }

private:
    double a;
};

void id(const Figura& A)
{
    A.id();
}

int main()
{
    Kwadrat square{5};
    id(square);

    puts("Ostatnia linijka w kodzie");
}