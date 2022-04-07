//
// Created by roagen on 07.04.2022.
//

#include "Czlowiek.h"

std::string Czlowiek::rysowanie() const {
    return "웃";
}

Czlowiek::Czlowiek(Wektor2d polozenie) : Zwierze(polozenie,CZLOWIEK_SILA,CZLOWIEK_INICJATYWA){

}

Czlowiek *Czlowiek::kopia() const {
    return new Czlowiek{*this};
}
