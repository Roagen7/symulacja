#include "Roslina.h"
#include <iostream>

std::string Roslina::rysowanie() const {

    return "\e[32mr\e[0m";

}

void Roslina::akcja() {



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
