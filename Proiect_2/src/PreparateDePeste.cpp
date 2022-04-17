#include "PreparateDePeste.h"
#include "Produs.h"
#include "PreparateDePost.h"
#include "PreparateNormale.h"

using namespace std;

PreparateDePeste::PreparateDePeste()
{
    this->PreparateNormale::setParentClass();
    this->PreparateDePost::setParentClass();
    setParentClass();
}

PreparateDePeste::PreparateDePeste(string speciePeste, string contineOase, std::string felDeMancare, int nrIngrediente, string esteDinSoia, string contineOua, string contineLapte,
                                    string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare):Produs(nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare),
                                     PreparateNormale(felDeMancare, nrIngrediente, nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare),
                                      PreparateDePost(esteDinSoia, contineOua, contineLapte, nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare)
{
    setParentClass();
    this->speciePeste = speciePeste;
    this->contineOase = contineOase;
}

PreparateDePeste::PreparateDePeste(const PreparateDePeste& obj):PreparateNormale(obj), PreparateDePost(obj)
{
    setParentClass();
    this->speciePeste = obj.speciePeste;
    this->contineOase = obj.contineOase;
}

PreparateDePeste& PreparateDePeste::operator=(PreparateDePeste& obj)
{
    if(this != &obj)
    {
        this->PreparateNormale::operator=(obj);
        this->PreparateDePost::operator=(obj);

        this->speciePeste = obj.speciePeste;
        this->contineOase = obj.contineOase;
    }

    return  *this;
}

PreparateDePeste::~PreparateDePeste()
{
    cout<<"Destroyed ~PreparateDePeste"<<endl;
}



void PreparateDePeste::setParentClass()
{
    this->grandparentClass = dynamic_cast<Produs*> (this);
    this->parentNormaleClass = dynamic_cast<PreparateNormale*> (this);
    this->parentPostClass = dynamic_cast<PreparateDePost*> (this);
}

Produs* PreparateDePeste::getGrandparentClass()
{
    return this->grandparentClass;
}

PreparateNormale* PreparateDePeste::getParentNormaleClass()
{
    return this->parentNormaleClass;
}

PreparateDePost* PreparateDePeste::getParentPostClass()
{
    return this->parentPostClass;
}

void PreparateDePeste::afiseazaTipulProdusului()
{
    cout<<"Acest produs este preparat de peste!"<<endl;
}

void PreparateDePeste::afiseazaProdus()
{
    if(this->contineOase == "TRUE")
        cout<<"Acest produs este "<<this->speciePeste<<" care contine oase, are "<<this->nrIngrediente<<" ingrediente si costa "<<this->pret<<" lei!"<<endl;
    else
        cout<<"Acest produs este "<<this->speciePeste<<" care NU contine oase, are "<<this->nrIngrediente<<" ingrediente si costa "<<this->pret<<" lei!"<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
