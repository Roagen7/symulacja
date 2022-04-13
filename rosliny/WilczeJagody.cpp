#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Wektor2d polozenie): Roslina(polozenie,WILCZE_JAGODY_SILA){

}

std::string WilczeJagody::rysowanie() const {
    return "\e[31m◎\e[0m";
}

void WilczeJagody::dodajModyfikator(Organizm *organizm) const {
    organizm->zabij();
}

WilczeJagody *WilczeJagody::kopia() const {
    return new WilczeJagody{*this};
}

std::string WilczeJagody::jakoString() const {
    return "WILCZE_JAGODY";
}
