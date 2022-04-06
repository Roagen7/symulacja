#include "Roslina.h"
#include <iostream>

std::string Roslina::rysowanie() const {

    return "\e[32mr\e[0m";

}

void Roslina::akcja() {

    if((float)rand()/(float) RAND_MAX <= P_ROZSIANIA){

        rozsiej();

    }


}

void Roslina::kolizja() {



}

Roslina::Roslina(Wektor2d pozycja, uint sila):
    Organizm(pozycja,sila,INICJATYWA_ROSLINY) {

    std::cout << *this << " wyrasta" << std::endl;

}

void Roslina::info(std::ostream &os) const {

    os << "Roslina " <<

    " w wieku " << wiek;


}

void Roslina::rozsiej() {

    auto pNowy = swiat->getWolnePoleObok(polozenie);

    if(pNowy == polozenie) return;

    auto* org = this->kopia();

    org->setPolozenie(pNowy);

    swiat->addOrganizm(org);

}

Roslina * Roslina::kopia() const {
    return new Roslina{*this};
}
