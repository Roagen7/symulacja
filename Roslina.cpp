#include "Roslina.h"
#include <iostream>

std::string Roslina::rysowanie() const {

    return "\e[32mr\e[0m";

}

void Roslina::akcja() {



        rozsiej();




}

void Roslina::kolizja() {



}

Roslina::Roslina(Wektor2d pozycja, uint sila):
    Organizm(pozycja,sila,INICJATYWA_ROSLINY) {

}



void Roslina::rozsiej() {

    if((float)rand()/(float) RAND_MAX <= P_ROZSIANIA) {

        auto pNowy = swiat->getWolnePoleObok(polozenie);

        if (pNowy == polozenie) return;

        auto *org = this->kopia();

        org->setPolozenie(pNowy);

        swiat->addOrganizm(org);
    }

}

std::string Roslina::jakoString() const {
    return "";
}

//Roslina * Roslina::kopia() const {
//    return new Roslina{*this};
//}
