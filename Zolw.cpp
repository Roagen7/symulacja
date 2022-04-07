#include <iostream>
#include "Zolw.h"

Zolw::Zolw(Wektor2d polozenie): Zwierze(polozenie,ZOLW_SILA,ZOLW_INICJATYWA) {

}

std::string Zolw::rysowanie() const {
    return "\e[33mt\e[0m";
}

Zolw *Zolw::kopia() const {
    return new Zolw{polozenie};
}

void Zolw::akcja() {

    if((float) rand() / (float) RAND_MAX < ZOLW_P_RUCHU) losowyRuch();

}

bool Zolw::czyOdbilAtak(const Organizm *org) const {

    return org->getSila() < ZOLW_OBRONA;
}

std::string Zolw::jakoString() const {
    return "ZOLW";
}
