
#include <iostream>
#include "symulacja.h"
#include "Wilk.h"

int main() {

    std::string input;
    Swiat swiat(DOMYSLNA_WYSOKOSC,DOMYSLNA_SZEROKOSC);


    auto* zwie = new Wilk(Wektor2d{0, 0});

    swiat.addOrganizm(new Trawa({5,5}));
    swiat.addOrganizm(zwie);
    swiat.addOrganizm(new Owca(Wektor2d{9, 9}));
    swiat.addOrganizm(new Mlecz({1,7}));
    swiat.addOrganizm(new Owca({4,4}));
    swiat.addOrganizm(new Owca(Wektor2d{9, 8}));


    while(1){

        swiat.wykonajTure();

        getchar();

    }











    return 0;
}
