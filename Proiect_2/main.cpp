#include <iostream>
#include <vector>
#include <string>
#include "Produs.h"
#include "FelPrincipal.h"
#include "PreparateDePost.h"
#include "PreparateNormale.h"
#include "PreparateDePeste.h"

#include "MyExceptions.h"

using namespace std;

int FelPrincipal::codFelPrincipal;

int main()
{
    int vFelPrincipalSize;
    vector<FelPrincipal> vFelPrincipal;

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
                cout<<endl<<e.getException()<<endl;
                i--;
            }
        }
    }
    catch(MyExceptions e)
    {
        cout<<endl<<e.getException()<<endl;
    }

    /*FelPrincipal::setCodFelPrincipal(0);
    try {
          cout<<FelPrincipal::getCodFelPrincipal()<<endl;
    }
    catch(int e) {
        cout<<"EXCEPTION: "<<e;*/


    //Produs::afiseazaTipulProdusului();
    //FelPrincipal::afiseazaTipulProdusului();*/


    /*Produs *p1 = new FelPrincipal("TRUE", "FALSE", "paine", 5, 34, 324, 43, 34);
    p1->afiseazaProdus();*/

    /*FelPrincipal f1(5);
    cin>>f1;
    cout<<f1;*/

    /*PreparateDePost prep1;
    cin>>prep1;
    cout<<prep1;*/

    /*Produs *p1 = new PreparateDePost("TRUE", "TRUE", "FALSE", "paine", 5, 34, 324, 43, 34);
    p1->afiseazaProdus();*/

    /*Produs *p3 = new PreparateNormale("Garnitura", 3, "Friptura de pui", 35, 500, 2, 9, 2022);
    p3->afiseazaProdus();*/

    /*PreparateNormale pn1;
    cin>>pn1;
    cout<<pn1;*/


    return 0;
}
