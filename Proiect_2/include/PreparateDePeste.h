#ifndef PREPARATEDEPESTE_H
#define PREPARATEDEPESTE_H
#include "Produs.h"
#include "PreparateDePost.h"
#include "PreparateNormale.h"

class PreparateDePeste: public PreparateNormale, public PreparateDePost
{
private:
    std::string speciePeste;
    std::string contineOase;

    Produs *grandparentClass;
    PreparateDePost *parentPostClass;
    PreparateNormale *parentNormaleClass;

public:
    PreparateDePeste();
    PreparateDePeste(std::string, std::string, std::string, int, std::string, std::string, std::string, std::string, int, int, int, int, int); //PrepDePeste, PrepNorm, PrepPost, Produs
    PreparateDePeste(const PreparateDePeste&);
    PreparateDePeste& operator=(PreparateDePeste&);
    ~PreparateDePeste();

    void afiseazaProdus();

    void setParentClass();
    Produs* getGrandparentClass();
    PreparateNormale* getParentNormaleClass();
    PreparateDePost* getParentPostClass();
    void afiseazaTipulProdusului();
};

#endif // PREPARATEDEPESTE_H
