#ifndef FELPRINCIPAL_H
#define FELPRINCIPAL_H
#include "Produs.h"

class FelPrincipal: public Produs
{
private:
    static int codFelPrincipal;         //toate felurile princ au acelasi cod
    const int cod;    //fiecare fel principal are un cod care e constant
    std::string isSupaCrema;
    std::string contineLegume;
    Produs *parentClass;

public:

    FelPrincipal();
    FelPrincipal(int, std::string, std::string, std::string, int, int, int, int, int);
    FelPrincipal(const FelPrincipal&);
    FelPrincipal& operator=(FelPrincipal&);
    ~FelPrincipal();

    friend std::istream& operator>>(std::istream&, FelPrincipal&);
    friend std::ostream& operator<<(std::ostream&, FelPrincipal&);

    void afiseazaProdus();

    void setParentClass();
    Produs* getParentClass();
    static void setCodFelPrincipal(int);
    static int getCodFelPrincipal();
    void afiseazaTipulProdusului();
    int getCod() const;
};

#endif // FELPRINCIPAL_H
