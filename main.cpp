#include "symulacja.h"

int main() {

    Swiat swiat(10,20);

    swiat.addOrganizm(new Zwierze(Punkt{0,0},1u,1u));
    swiat.addOrganizm(new Zwierze(Punkt{2,0},1u,1u));
    swiat.addOrganizm(new Roslina({3,7},0));


    swiat.rysujSwiat();



    return 0;
}
