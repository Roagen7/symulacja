#include "Guarana.h"

Guarana::Guarana(Wektor2d polozenie) : Roslina(polozenie, GUARANA_SILA){

}

std::string Guarana::rysowanie() const {
    return "\e[33m✾\e[0m";
}

Guarana *Guarana::kopia() const {
    return new Guarana{*this};
}

void Guarana::dodajModyfikator(Organizm *organizm) const {

    organizm->setSila(organizm->getSila() + GUARANA_ZWIEKSZENIE_SILY);

}

std::string Guarana::jakoString() const {
    return "GUARANA";
}
