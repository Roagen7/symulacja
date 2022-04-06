
#include <iostream>
#include "symulacja.h"
#include "Wilk.h"

int main() {

    std::string input;
    Swiat swiat(DOMYSLNA_WYSOKOSC,DOMYSLNA_SZEROKOSC);


    auto* zwie = new Wilk(Wektor2d{0, 0});

    swiat.addOrganizm(new Trawa({5,5}));
    swiat.addOrganizm(zwie);
    swiat.addOrganizm(new Wilk(Wektor2d{9, 9}));



    while(1){

        swiat.wykonajTure();

        getchar();

    }











    return 0;
}
