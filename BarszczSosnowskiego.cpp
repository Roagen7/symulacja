#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

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

void BarszczSosnowskiego::akcja() {

    for(int y = -1; y <= 1; y++){

        for(int x = -1; x <= 1; x++){

            Organizm* org = swiat->getOrganizmNaPozycji(polozenie + Wektor2d{y,x});

            if(dynamic_cast<Zwierze*>(org) != nullptr){
                org->zabij();
            }

        }

    }

    Roslina::akcja();


}
