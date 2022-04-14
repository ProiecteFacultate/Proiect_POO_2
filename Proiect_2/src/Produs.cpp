#include "Produs.h"
#include <iostream>

using namespace std;

Produs::Produs(string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare)  //constr de initializare
{
    this->nume = nume;
    this->pret = pret;
    this->calorii = calorii;
    this->ziExpirare = ziExpirare;
    this->lunaExpirare = lunaExpirare;
    this->anExpirare = anExpirare;
}

Produs::Produs(const Produs& obj)
{
    this->nume = obj.nume;
    this->pret = obj.pret;
    this->calorii = obj.calorii;
    this->ziExpirare = obj.ziExpirare;
    this->lunaExpirare = obj.lunaExpirare;
    this->anExpirare = obj.anExpirare;
}

Produs& Produs::operator=(Produs& obj)
{
    if(this != &obj)
    {
        this->nume = obj.nume;
        this->pret = obj.pret;
        this->calorii = obj.calorii;
        this->ziExpirare = obj.ziExpirare;
        this->lunaExpirare = obj.lunaExpirare;
        this->anExpirare = obj.anExpirare;
    }

    return *this;
}

Produs::~Produs()
{
    cout<<"Destroyed ~Produs"<<endl;
}

istream& operator>>(istream& in, Produs& obj)
{
    cout<<"Introduceti nume produs: ";
    in>>obj.nume;

    cout<<"Introduceti pret produs: ";
    in>>obj.pret;

    cout<<"Introduceti calorii produs: ";
    in>>obj.calorii;

    cout<<"Introduceti zi expirare produs: ";
    in>>obj.ziExpirare;

    cout<<"Introduceti luna expirare produs: ";
    in>>obj.lunaExpirare;

    cout<<"Introduceti an expirare produs: ";
    in>>obj.anExpirare;

    cout<<endl;

    return in;
}

ostream& operator<<(ostream& out, Produs& obj)
{
    out<<"Nume: "<<obj.nume<<endl;
    out<<"Pret: "<<obj.pret<<endl;
    out<<"Calorii: "<<obj.calorii<<endl;
    out<<"Zi expirare: "<<obj.ziExpirare<<endl;
    out<<"Luna expirare: "<<obj.lunaExpirare<<endl;
    out<<"An expirare: "<<obj.anExpirare<<endl;
    out<<endl;

    return out;
}
