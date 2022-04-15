#include "PreparateDePost.h"

using namespace std;

PreparateDePost::PreparateDePost()
{
    setParentClass();
}

PreparateDePost::PreparateDePost(std::string esteDinSoia, std::string contineOua, std::string contineLapte, string nume, int pret, int calorii, int ziExpirare, int lunaExpirare, int anExpirare):Produs(nume, pret, calorii, ziExpirare, lunaExpirare, anExpirare)
{
    setParentClass();
    this->esteDinSoia = esteDinSoia;
    this->contineOua = contineOua;
    this->contineLapte = contineLapte;
}

PreparateDePost::PreparateDePost(const PreparateDePost& obj):Produs(obj)
{
    setParentClass();
    this->esteDinSoia = obj.esteDinSoia;
    this->contineOua = obj.contineOua;
    this->contineLapte = obj.contineLapte;
}

PreparateDePost& PreparateDePost::operator=(PreparateDePost& obj)
{
    if(this != &obj)
    {
        this->Produs::operator=(obj);
        this->esteDinSoia = obj.esteDinSoia;
        this->contineOua = obj.contineOua;
        this->contineLapte = obj.contineLapte;
    }

    return *this;
}

PreparateDePost::~PreparateDePost()
{
    cout<<"Destroyed ~PreparateDePost"<<endl;
}

void PreparateDePost::setParentClass()
{
    this->parentClass = dynamic_cast<Produs*> (this);
}

Produs* PreparateDePost::getParentClass()
{
    return parentClass;
}

void PreparateDePost::afiseazaProdus()
{
    if(this->esteDinSoia == "TRUE")
        cout<<"Preparatul de post "<<nume<<" ESTE din soia si costa "<<pret<<" lei!"<<endl;
    else if(this->esteDinSoia == "FALSE")
        cout<<"Preparatul de post "<<nume<<" NU ESTE din soia si costa "<<pret<<" lei!"<<endl;
}

void PreparateDePost::esteProdusVegan() const
{
    if(this->contineLapte == "FALSE" && this->contineOua == "FALSE")
        cout<<"Produs vegan!"<<endl;
    else
        cout<<"NU este produs vegan!"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>>(istream& in, PreparateDePost& obj)
{
    in>>*obj.getParentClass();

    cout<<"Precizati daca este din soia [TRUE/FALSE]: ";
    in>>obj.esteDinSoia;

    cout<<"Precizati daca contine oua [TRUE/FALSE]: ";
    in>>obj.contineOua;

    cout<<"Precizati daca contine lapte [TRUE/FALSE]: ";
    in>>obj.contineLapte;

    cout<<endl;

    return in;
}

ostream& operator<<(ostream& out, PreparateDePost& obj)
{
    out<<*obj.getParentClass();

    out<<"Este din soia: "<<obj.esteDinSoia<<endl;
    out<<"Contine oua: "<<obj.contineOua<<endl;
    out<<"Contine lapte: "<<obj.contineLapte<<endl;
    out<<endl;

    return out;
}

