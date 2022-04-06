#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Wektor2d polozenie) : Roslina(polozenie,BARSZCZ_SOSNOWSKIEGO_SILA){

}

std::string BarszczSosnowskiego::rysowanie() const {
    return "\e[31m!\e[0m";
}

void BarszczSosnowskiego::dodajModyfikator(Organizm *organizm) const {
    organizm->zabij();
}

BarszczSosnowskiego *BarszczSosnowskiego::kopia() const {
    return new BarszczSosnowskiego{*this};
}
