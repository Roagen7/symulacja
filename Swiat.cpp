#include <iostream>
#include "Swiat.h"

void Swiat::wykonajTure() {

}

void Swiat::rysujSwiat() {

    for(uint y = 0; y < wysokosc; y++){

        for(uint x = 0; x < szerokosc; x++){

            auto* lokator = getOrganizmNaPozycji({y,x});

            if(lokator == nullptr){

                std::cout << "#";

            } else {

                std::cout << lokator->rysowanie();

            }

        }

        std::cout << std::endl;

    }

}

Swiat::Swiat(uint wysokosc, uint szerokosc):
    wysokosc(wysokosc),
    szerokosc(szerokosc) {

}

Organizm *Swiat::getOrganizmNaPozycji(Punkt p) {

    for(auto* organizm : organizmy){

        if(p == organizm->getPolozenie()){

            return organizm;

        }

    }
    return nullptr;

}

void Swiat::addOrganizm(Organizm* organizm) {

    organizm->setSwiat(this);
    organizmy.push_back(organizm);

}
