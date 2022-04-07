#include "Czlowiek.h"

std::string Czlowiek::rysowanie() const {

    return "웃";

}

Czlowiek::Czlowiek(Wektor2d polozenie) : Zwierze(polozenie,CZLOWIEK_SILA,CZLOWIEK_INICJATYWA){

}

Czlowiek *Czlowiek::kopia() const {
    return new Czlowiek{*this};
}

void Czlowiek::akcja() {

    switch(swiat->popRuch()){

        case Swiat::Ruch::STOJ:
            break;

        case Swiat::Ruch::GORA:
            zmienPolozenie({-1,0});
            break;


        case Swiat::Ruch::DOL:
            zmienPolozenie({1,0});
            break;

        case Swiat::Ruch::PRAWO:
            zmienPolozenie({0,1});
            break;

        case Swiat::Ruch::LEWO:
            zmienPolozenie({0,-1});
            break;

        case Swiat::Ruch::SPECJALNY:
            break;



    }

}
