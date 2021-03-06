#ifndef PREPARATENORMALE_H
#define PREPARATENORMALE_H
#include "Produs.h"
#include <vector>


class PreparateNormale: virtual public Produs
{
protected:
     int nrIngrediente;

private:
    std::string felDeMancare;  //Garnitura/Friptura/Aperitiv
    std::string *ingrediente;

    Produs *parentClass;

public:
    PreparateNormale();
    PreparateNormale(std::string, int, std::string, int, int, int, int, int);
    PreparateNormale(const PreparateNormale&);
    PreparateNormale& operator=(PreparateNormale&);
    ~PreparateNormale();

    friend std::istream& operator>>(std::istream&, PreparateNormale&);
    friend std::ostream& operator<<(std::ostream&, PreparateNormale&);

    void afiseazaProdus();

    void setParentClass();
    Produs* getParentClass();

    void afiseazaTipulProdusului();

};

#endif // PREPARATENORMALE_H
