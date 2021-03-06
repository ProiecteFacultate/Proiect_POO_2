#include "PreparateNormale.h"
#include "MyExceptions.h"

using namespace std;

PreparateNormale::PreparateNormale()
{
    setParentClass();
    ingrediente = NULL;
}

PreparateNormale::PreparateNormale(string felDeMancare, int nrIngrediente, string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare):Produs(nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare)
{
    setParentClass();
    this->felDeMancare = felDeMancare;
    this->nrIngrediente = nrIngrediente;
    this->ingrediente = new string[this->nrIngrediente];

    cout<<"Introduceti ingredientele: "<<endl;
    for(int i = 0; i < this->nrIngrediente; i++)
    {
        cout<<"Ingredientul numarul "<<i + 1<<" (un cuvant): ";
        cin>>this->ingrediente[i];
    }
}

PreparateNormale::PreparateNormale(const PreparateNormale& obj):Produs(obj)
{
    setParentClass();
    this->felDeMancare = obj.felDeMancare;
    this->nrIngrediente = obj.nrIngrediente;

    if(this->ingrediente != nullptr)
        delete[] this->ingrediente;

    this->ingrediente = new string[this->nrIngrediente];

    for(int i = 0; i < this->nrIngrediente; i++)
        this->ingrediente[i] = obj.ingrediente[i];
}

PreparateNormale& PreparateNormale::operator=(PreparateNormale& obj)
{
    if(this != &obj)
    {
        this->Produs::operator=(obj);
        this->felDeMancare = obj.felDeMancare;
        this->nrIngrediente = obj.nrIngrediente;

        if(this->ingrediente != nullptr)
            delete[] this->ingrediente;

        this->ingrediente = new string[nrIngrediente];

        for(int i = 0; i < this->nrIngrediente; i++)
            this->ingrediente[i] = obj.ingrediente[i];
    }

    return *this;
}

PreparateNormale::~PreparateNormale()
{
    delete[] this->ingrediente;
    cout<<"Destroyed ~PreparateNormale"<<endl;
}

void PreparateNormale::setParentClass()
{
    this->parentClass = dynamic_cast<Produs*> (this);
}

Produs* PreparateNormale::getParentClass()
{
    return this->parentClass;
}

void PreparateNormale::afiseazaTipulProdusului()
{
    cout<<"Acest produs este preparat normal!"<<endl;
}

void PreparateNormale::afiseazaProdus()
{
    cout<<"Acest produs este "<<this->felDeMancare<<" care contine "<<this->nrIngrediente<<" si costa "<<this->pret<<" lei!"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>>(istream& in, PreparateNormale& obj)
{
    try
    {
        in>>*obj.getParentClass();     //poate veni exceptie de aici
        string val;
        vector<string> acceptedValuesString;
        acceptedValuesString.resize(3);
        acceptedValuesString[0] = "GARNITURA";
        acceptedValuesString[1] = "FRIPTURA";
        acceptedValuesString[2] = "APERITIV";

        cout<<"Precizati tipul preparatului [Garnitura/Friptura/Aperitiv]: ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::acceptedInputException(val, acceptedValuesString, 3);
        obj.felDeMancare = val;

        cout<<"Precizati numarul de ingrediente (apoi va trebui sa introduceti numele fiecarui ingredient): ";
        in.clear();
        in.sync();
        getline(in, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        obj.nrIngrediente = stoi(val);

        if(obj.ingrediente != nullptr)
            delete[] obj.ingrediente;

        obj.ingrediente = new string[obj.nrIngrediente];


        for(int i = 0; i < obj.nrIngrediente; i++)
        {
            cout<<"Ingredientul numarul "<<i + 1<<": ";
            in.clear();
            in.sync();
            getline(in, obj.ingrediente[i]);
        }

        cout<<endl;

        return in;
    }
    catch(MyExceptions e)
    {
        throw;
    }
}

ostream& operator<<(ostream& out, PreparateNormale& obj)
{
    out<<*obj.getParentClass();

    out<<"Preparatul este "<<obj.felDeMancare<<endl;
    out<<"Preparatul contine "<<obj.nrIngrediente<<" ingrediente:"<<endl;

    for(int i = 0; i < obj.nrIngrediente; i++)
        cout<<"Ingredientul numarul "<<i + 1<<" este '"<<obj.ingrediente[i]<<"'"<<endl;

    out<<endl;

    return out;
}


