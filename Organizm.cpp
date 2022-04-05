
#include "Organizm.h"

Wektor2d Organizm::getPolozenie() const {
    return polozenie;
}

Organizm::Organizm(Wektor2d polozenie, uint sila, uint inicjatywa):
    polozenie(polozenie),
    sila(sila),
    inicjatywa(inicjatywa){



}

void Organizm::setSwiat(Swiat* swiat) {

    this->swiat = swiat;

}

Swiat *Organizm::getSwiat() {
    return swiat;
}

uint Organizm::getInicjatywa() const {
    return inicjatywa;
}

std::ostream &operator<<(std::ostream &os, const Organizm& organizm) {

        organizm.info(os);

}

void Organizm::starzejSie() {

    wiek++;

}

uint Organizm::getWiek() const {
    return wiek;
}

bool operator<(const Organizm &o1, const Organizm &o2) {
    return o1.sila < o2.sila;
}

bool operator>(const Organizm &o1, const Organizm &o2) {
    return o1.sila > o2.sila;
}

void Organizm::setWiek(uint wiek) {
    this->wiek = wiek;
}

bool Organizm::isZywy() const {
    return zywy;
}

void Organizm::zabij() {

    zywy = false;

}

