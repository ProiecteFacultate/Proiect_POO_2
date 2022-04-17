#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "Produs.h"
#include "FelPrincipal.h"
#include "PreparateDePost.h"
#include "PreparateNormale.h"
#include "PreparateDePeste.h"

#include "MyExceptions.h"

using namespace std;

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void comanda2(vector<string> comenzi, int nrComenzi)
{
    cout<<"Comenzile care pot fi folosite sunt: "<<endl;
    SetColor(10);
    for(int i = 1; i <= nrComenzi; i++)
        cout<<"'"<<comenzi[i]<<"'"<<endl;

    SetColor(15);
    cout<<endl;
}

void comanda3(vector<FelPrincipal> &vFelPrincipal, int &vFelPrincipalSize)
{
    cout<<"Introduceti numarul de feluri principale (un int): ";
    try
    {
        string val;
        cin.clear();
        cin.sync();
        getline(cin, val);

        MyExceptions::badTypeIntegerException(val);
        MyExceptions::vectorLengthException(stoi(val));

        vFelPrincipalSize = stoi(val);
        vFelPrincipal.resize(vFelPrincipalSize + 1);

        for(int i = 1; i <= vFelPrincipalSize; i++)
        {
            cout<<"Introduceti felul principal numarul "<<i<<": "<<endl;
            try
            {
                cin>>vFelPrincipal[i];
            }
            catch(MyExceptions e)
            {
                SetColor(12);
                cout<<endl<<e.getException()<<endl<<endl;
                SetColor(15);
                i--;
            }
        }
    }
    catch(MyExceptions e)
    {
        SetColor(12);
        cout<<endl<<e.getException()<<endl<<endl;
        SetColor(15);
    }
}

void comanda4(vector<FelPrincipal> &vFelPrincipal, int vFelPrincipalSize)
{
    cout<<"Felurile principale sunt: ";
    for(int i = 1; i <= vFelPrincipalSize; i++)
    {
        cout<<"Felul principal numarul "<<i<<" este: ";
        cout<<vFelPrincipal[i];
    }

    cout<<endl;
}

void comanda5()
{
    cout<<"Introduceti codul felurilor principale: ";
    try
    {
        string val;
        cin.clear();
        cin.sync();
        getline(cin, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::negativeValueException(stoi(val));
        FelPrincipal::setCodFelPrincipal(stoi(val));
    }
    catch(MyExceptions e)
    {
        SetColor(12);
        cout<<endl<<e.getException()<<endl<<endl;
        SetColor(15);
    }
    catch(std::out_of_range e)
    {
        SetColor(12);
        cout<<endl<<"Out of range exception"<<endl<<endl;
        SetColor(15);
    }

}

void comanda6()
{
    try
    {
        cout<<"Codul pentru felurile principale este: "<<FelPrincipal::getCodFelPrincipal()<<endl;
    }
    catch (int e)
    {
        SetColor(12);
        cout<<endl<<"INT Exception: "<<e<<endl<<endl;
        SetColor(15);
    }

}

void comanda7(vector<PreparateNormale> &vPreparateNormale, int &vPreparateNormaleSize)
{
    cout<<"Introduceti numarul de preparate normale (un int): ";
    try
    {
        string val;
        cin.clear();
        cin.sync();
        getline(cin, val);

        MyExceptions::badTypeIntegerException(val);
        MyExceptions::vectorLengthException(stoi(val));

        vPreparateNormaleSize = stoi(val);
        vPreparateNormale.resize(vPreparateNormaleSize + 1);

        for(int i = 1; i <= vPreparateNormaleSize; i++)
        {
            cout<<"Introduceti preparatul normal numarul "<<i<<": "<<endl;
            try
            {
                cin>>vPreparateNormale[i];
            }
            catch(MyExceptions e)
            {
                SetColor(12);
                cout<<endl<<e.getException()<<endl<<endl;
                SetColor(15);
                i--;
            }
        }
    }
    catch(MyExceptions e)
    {
        SetColor(12);
        cout<<endl<<e.getException()<<endl<<endl;
        SetColor(15);
    }
}

void comanda8(vector<PreparateNormale> &vPreparateNormale, int vPreparateNormaleSize)
{
    cout<<"Preparatele normale sunt: ";
    for(int i = 1; i <= vPreparateNormaleSize; i++)
    {
        cout<<"Preparatul normal numarul "<<i<<" este: ";
        cout<<vPreparateNormale[i];
    }

    cout<<endl;
}

void comanda9(vector<PreparateNormale> &vPreparateNormale, int vPreparateNormaleSize)
{
    try
    {
        cout<<"Introduceti numarul preparatului normal pe care doriti sa il afisati (indexare de la 1): ";
        string val;
        cin.clear();
        cin.sync();
        getline(cin, val);
        MyExceptions::badTypeIntegerException(val);
        MyExceptions::outOfBoundsException(stoi(val), vPreparateNormaleSize, 1);
        cout<<"Preparatul normal cu numarul "<<stoi(val)<<" este:"<<endl;
        vPreparateNormale[stoi(val)].afiseazaProdus();
        cout<<endl;
    }
    catch(MyExceptions e)
    {
        SetColor(12);
        cout<<endl<<e.getException()<<endl<<endl;
        SetColor(15);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int FelPrincipal::codFelPrincipal;
int main()
{
    SetColor(15);
    int vFelPrincipalSize, vPreparateNormaleSize, nrComenzi = 9;
    vector<FelPrincipal> vFelPrincipal;
    vector<PreparateNormale> vPreparateNormale;
    vector<string> comenzi;
    string comanda;

    comenzi.resize(nrComenzi + 1);
    comenzi[1] = "Inchide";
    comenzi[2] = "Ajutor";
    comenzi[3] = "Introdu feluri principale";
    comenzi[4] = "Afiseaza feluri principale";
    comenzi[5] = "Seteaza codul felurilor principale";
    comenzi[6] = "Afiseaza codul felurilor principale";
    comenzi[7] = "Introdu preparate normale";
    comenzi[8] = "Afiseaza preparate normale";
    comenzi[9] = "Afiseaza un preparat normal";

    comanda2(comenzi, nrComenzi);

    cin.clear();
    cin.sync();
    SetColor(10);
    getline(cin, comanda);
    SetColor(15);

    while(comanda != "Inchide")
    {
        bool validCommand = false;
        for(int i = 2; i <= nrComenzi; i++)
            if(comanda == comenzi[i])
            {
                validCommand = true;
                break;
            }

        if(validCommand == false)
        {
            cout<<"Comanda invalida. Introduceti alta comanda: ";
            cin.clear();
            cin.sync();
            SetColor(10);
            getline(cin, comanda);
            SetColor(15);
        }
        else
        {
            if(comanda == comenzi[2])
                comanda2(comenzi, nrComenzi);
            else if(comanda == comenzi[3])
                comanda3(vFelPrincipal, vFelPrincipalSize);
            else if(comanda == comenzi[4])
                comanda4(vFelPrincipal, vFelPrincipalSize);
            else if(comanda == comenzi[5])
                comanda5();
            else if(comanda == comenzi[6])
                comanda6();
            else if(comanda == comenzi[7])
                comanda7(vPreparateNormale, vPreparateNormaleSize);
            else if(comanda == comenzi[8])
                comanda8(vPreparateNormale, vPreparateNormaleSize);
            else if(comanda == comenzi[9])
                comanda9(vPreparateNormale, vPreparateNormaleSize);

            cout<<"Introduceti o comanda: ";
            cin.clear();
            cin.sync();
            SetColor(10);
            getline(cin, comanda);
            SetColor(15);;
        }
    }

    cout<<endl<<"Proces incheiat!"<<endl<<endl;
    cout<<endl<<"DIVERSE FUNCTII: "<<endl<<endl;

    FelPrincipal f1;
    PreparateNormale pn1;
    PreparateDePost ppost1;
    PreparateDePeste ppeste1;

    f1.afiseazaTipulProdusului();
    pn1.afiseazaTipulProdusului();
    ppost1.afiseazaTipulProdusului();
    ppeste1.afiseazaTipulProdusului();

    Produs *p1 = new PreparateDePeste("Peste auriu", "TRUE", "Garnitura", 3, "FALSE", "FALSE", "FALSE", "Peste prajit", 65, 400, 3, 9, 2022);
    p1->afiseazaProdus();

    Produs *p2 = new PreparateDePost("TRUE", "TRUE", "FALSE", "Paine", 2, 200, 24, 4, 2022);
    p2->afiseazaProdus();

    ppost1.esteProdusVegan();


    return 0;
}
