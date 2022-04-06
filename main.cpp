
#include <iostream>
#include "symulacja.h"

int main() {

    std::string input;
    Swiat swiat(DOMYSLNA_WYSOKOSC,DOMYSLNA_SZEROKOSC);


    auto* zwie = new Wilk(Wektor2d{0, 0});

    swiat.addOrganizm(new Trawa({5,5}));
    swiat.addOrganizm(zwie);
    swiat.addOrganizm(new Wilk({3,4}));
    swiat.addOrganizm(new Owca(Wektor2d{9, 9}));
    swiat.addOrganizm(new Mlecz({1,7}));
    swiat.addOrganizm(new Guarana({2,8}));
    swiat.addOrganizm(new Guarana({2,9}));
    swiat.addOrganizm(new Owca({4,4}));
    swiat.addOrganizm(new Owca(Wektor2d{9, 8}));
    swiat.addOrganizm(new WilczeJagody(Wektor2d{10, 10}));
    swiat.addOrganizm(new WilczeJagody(Wektor2d{10, 9}));
    swiat.addOrganizm(new BarszczSosnowskiego(Wektor2d{9, 10}));

    swiat.addOrganizm(new Owca(Wektor2d{19, 19}));
    swiat.addOrganizm(new Owca(Wektor2d{19, 18}));
    swiat.addOrganizm(new Owca(Wektor2d{18, 18}));
    swiat.addOrganizm(new Owca(Wektor2d{17, 18}));
    swiat.addOrganizm(new Zolw(Wektor2d{15, 16}));
    swiat.addOrganizm(new Zolw(Wektor2d{14, 15}));
    swiat.addOrganizm(new Lis({10,14}));
    swiat.addOrganizm(new Lis({10,15}));
    swiat.addOrganizm(new Lis({11,14}));
    swiat.addOrganizm(new Lis({11,15}));

    swiat.addOrganizm(new Antylopa({10,0}));
    swiat.addOrganizm(new Antylopa({12,0}));

    swiat.addOrganizm(new Lis({11,14}));
    swiat.addOrganizm(new Lis({11,15}));


    while(1){

        swiat.wykonajTure();

        getchar();

    }











    return 0;
}
