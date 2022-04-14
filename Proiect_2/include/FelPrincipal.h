#ifndef FELPRINCIPAL_H
#define FELPRINCIPAL_H
#include "Produs.h"


class FelPrincipal: public Produs
{
private:
    std::string isSupaCrema;
    std::string contineLegume;

public:

    FelPrincipal():Produs(){};
    FelPrincipal(std::string isSupaCrema, std::string contineLegume, std::string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare);
    FelPrincipal(const FelPrincipal&);
    FelPrincipal& operator=(FelPrincipal&);
    ~FelPrincipal();

    friend std::istream& operator>>(std::istream&, FelPrincipal&);
    friend std::ostream& operator<<(std::ostream&, FelPrincipal&);
};

#endif // FELPRINCIPAL_H
