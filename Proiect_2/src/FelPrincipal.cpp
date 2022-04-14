#include "FelPrincipal.h"

using namespace std;

FelPrincipal::FelPrincipal(string isSupaCrema, string contineLegume, string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare):Produs(nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare)
{
    this->isSupaCrema = isSupaCrema;
    this->contineLegume = contineLegume;
}

FelPrincipal::FelPrincipal(const FelPrincipal& obj):Produs(obj)
{
    this->isSupaCrema = obj.isSupaCrema;
    this->contineLegume = obj.contineLegume;
}

FelPrincipal& FelPrincipal::operator=(FelPrincipal& obj)
{
    if(this != &obj)
    {
        this->Produs::operator=(obj);
        this->isSupaCrema = obj.isSupaCrema;
        this->contineLegume = obj.contineLegume;
    }

    return *this;
}

FelPrincipal::~FelPrincipal()
{
    cout<<"Destroyed ~FelPrincipal"<<endl;
}

istream& operator>>(istream& in, FelPrincipal& obj)
{
    in>>dynamic_cast<Produs&> (obj);

    cout<<"Precizati daca este supa crema [TRUE/FALSE]: ";
    in>>obj.isSupaCrema;

    cout<<"Precizati daca contine legume [TRUE/FALSE]: ";
    in>>obj.contineLegume;

    cout<<endl;
}

ostream& operator<<(ostream& out, FelPrincipal& obj)
{
    out<<dynamic_cast<Produs&> (obj);

    out<<"Este supa crema: "<<obj.isSupaCrema<<endl;
    out<<"Contine legume: "<<obj.contineLegume<<endl;
    out<<endl;

    return out;
}
