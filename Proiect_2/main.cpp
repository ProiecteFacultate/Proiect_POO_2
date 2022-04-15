#include <iostream>
#include "Produs.h"
#include "FelPrincipal.h"
#include "PreparateDePost.h"
#include "PreparateNormale.h"

using namespace std;

int FelPrincipal::codFelPrincipal;

int main()
{
    /*FelPrincipal::setCodFelPrincipal(12345);
    cout<<FelPrincipal::getCodFelPrincipal()<<endl;
    Produs::afiseazaTipulProdusului();
    FelPrincipal::afiseazaTipulProdusului();*/


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

    PreparateNormale pn1;
    cin>>pn1;
    cout<<pn1;


    return 0;
}
