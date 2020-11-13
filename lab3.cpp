#include <iostream>

class Figura
{
public:
    void   setPole(double p) { pole = p; }
    double getPole() { return pole; }

private:
    double pole;
};

int main()
{
    Figura f;
    f.setPole(5);
    std::cout << "Pole figury wynosi " << f.getPole() << std::endl;
    puts("Ostatnia linijka w kodzie");
}
