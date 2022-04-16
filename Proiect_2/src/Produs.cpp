#include "Produs.h"
#include "MyExceptions.h"
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

void Produs::afiseazaProdus()
{
    cout<<"Produsul "<<nume<<" costa "<<pret<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>>(istream& in, Produs& obj)
{
    try
    {
        string val;

        cout<<"Introduceti nume produs: ";
        in.clear();
        in.sync();
        getline(in, obj.nume);

        cout<<"Introduceti pret produs: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.pret = stoi(val);

        cout<<"Introduceti calorii produs (un int): ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.calorii = stoi(val);

        cout<<"Introduceti zi expirare produs: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.ziExpirare = stoi(val);

        cout<<"Introduceti luna expirare produs: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.lunaExpirare = stoi(val);

        cout<<"Introduceti an expirare produs: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.anExpirare = stoi(val);

        cout<<endl;
        return in;
    }
    catch (MyExceptions e)
    {
        throw;
    }

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
