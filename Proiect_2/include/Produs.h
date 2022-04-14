#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>

class Produs
{
protected:
    std::string nume;
    int pret;
    int calorii;
    int ziExpirare;
    int lunaExpirare;
    int anExpirare;

public:
    Produs(){};
    Produs(std::string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare);
    Produs(const Produs&);
    Produs& operator=(Produs&);
    ~Produs();

    friend std::istream& operator>>(std::istream&, Produs&);
    friend std::ostream& operator<<(std::ostream&, Produs&);
};

#endif // PRODUS_H
