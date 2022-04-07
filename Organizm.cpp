
#include <iostream>
#include "Organizm.h"
#include "Swiat.h"

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
    std::cout << this->jakoString() << " umiera" << std::endl;
    zywy = false;

}

void Organizm::setPolozenie(Wektor2d polozenie) {

    this->polozenie = polozenie;

}

void Organizm::dodajModyfikator(Organizm *organizm) const {

}

void Organizm::setSila(uint sila) {
    this->sila = sila;
}

uint Organizm::getSila() const {
    return sila;
}

bool Organizm::czyOdbilAtak(const Organizm *org) const{
    return false;
}

bool Organizm::czyMaDobryWech() const{
    return false;
}

bool Organizm::czyUciekl() const {
    return false;
}

bool Organizm::ucieczka() {

    if(czyUciekl()){

        Wektor2d nowePole = swiat->getWolnePoleObok(polozenie);

        if(nowePole == polozenie){

            return false;

        }

        setPolozenie(nowePole);
        return true;


    }

    return false;
}

