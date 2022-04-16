#include "FelPrincipal.h"
#include "Produs.h"
#include "MyExceptions.h"

using namespace std;

FelPrincipal::FelPrincipal():Produs()
{
    setParentClass();
}

FelPrincipal::FelPrincipal(string isSupaCrema, string contineLegume, string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare):Produs(nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare)
{
    setParentClass();
    this->isSupaCrema = isSupaCrema;
    this->contineLegume = contineLegume;
}

FelPrincipal::FelPrincipal(const FelPrincipal& obj):Produs(obj)
{
    setParentClass();
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

void FelPrincipal::setParentClass()
{
    this->parentClass = dynamic_cast<Produs*> (this);
}

Produs* FelPrincipal::getParentClass()
{
    return parentClass;
}

void FelPrincipal::afiseazaProdus()
{
    if(isSupaCrema == "TRUE")
        cout<<"Felul principal "<<nume<<" ESTE supa crema si costa "<<pret<<" lei!"<<endl;
    else if(isSupaCrema == "FALSE")
        cout<<"Felul principal "<<nume<<" NU ESTE supa crema si costa "<<pret<<" lei!"<<endl;
}

void FelPrincipal::setCodFelPrincipal(int x)
{
    FelPrincipal::codFelPrincipal = x;
}

int FelPrincipal::getCodFelPrincipal()
{
    if(FelPrincipal::codFelPrincipal <= 0)
        throw FelPrincipal::codFelPrincipal;

    return FelPrincipal::codFelPrincipal;
}

void FelPrincipal::afiseazaTipulProdusului()
{
    cout<<"Acest produs este fel principal!"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>>(istream& in, FelPrincipal& obj)
{
    try
    {
        in>>*obj.getParentClass();   //throw poate veni de aici

        string val;
        vector<string> acceptedValuesString;
        acceptedValuesString.resize(2);
        acceptedValuesString[0] = "TRUE";
        acceptedValuesString[1] = "FALSE";

        cout<<"Precizati daca este supa crema [TRUE/FALSE]: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::acceptedInputException(val, acceptedValuesString, 2);
        obj.isSupaCrema = val;

        cout<<"Precizati daca contine legume [TRUE/FALSE]: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::acceptedInputException(val, acceptedValuesString, 2);
        obj.contineLegume = val;

        cout<<endl;

        return in;
    }
    catch(MyExceptions e)
    {
        throw;
    }
}

ostream& operator<<(ostream& out, FelPrincipal& obj)
{
    out<<*obj.getParentClass();

    out<<"Este supa crema: "<<obj.isSupaCrema<<endl;
    out<<"Contine legume: "<<obj.contineLegume<<endl;
    out<<endl;

    return out;
}


