#include "symulacja.h"


int main() {

    Swiat swiat(10,20);

    auto* zwie = new Zwierze(Wektor2d{0, 0}, 1, 2);


    swiat.addOrganizm(new Roslina({3,7},0));
    swiat.addOrganizm(zwie);
    swiat.addOrganizm(new Zwierze(Wektor2d{2, 0}, 1, 1));

    swiat.obecnyStan();


    swiat.wykonajTure();
    swiat.zabijOrganizm(zwie);
    swiat.wykonajTure();


    return 0;
}
