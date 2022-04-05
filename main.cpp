
#include <iostream>
#include "symulacja.h"


int main() {

    std::string input;
    Swiat swiat(10,20);


    auto* zwie = new Zwierze(Wektor2d{0, 0}, 1, 2);

    swiat.addOrganizm(new Roslina({1,0},0));
    swiat.addOrganizm(zwie);
    swiat.addOrganizm(new Zwierze(Wektor2d{1, 1}, 1, 1));



    while(1){

        swiat.wykonajTure();

        getchar();

    }











    return 0;
}
