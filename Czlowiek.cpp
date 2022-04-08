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

    int zasieg;

    if(turySpecjalne == 0){

        zasieg = 1;

    } else if(turySpecjalne > CZLOWIEK_SPECJALNY_MNIEJ){

        zasieg = ANTYLOPA_ZASIEG;
        turySpecjalne--;

    } else {

        if((float) rand()/(float) RAND_MAX < CZLOWIEK_P_MNIEJ){

            zasieg = ANTYLOPA_ZASIEG;

        }

        turySpecjalne--;

    }



    switch(swiat->popRuch()){

        case Swiat::Ruch::STOJ:
            break;

        case Swiat::Ruch::GORA:
            zmienPolozenie({-1 * zasieg,0});
            break;

        case Swiat::Ruch::DOL:
            zmienPolozenie({zasieg,0});
            break;

        case Swiat::Ruch::PRAWO:
            zmienPolozenie({0,zasieg});
            break;

        case Swiat::Ruch::LEWO:
            zmienPolozenie({0,-1 * zasieg});
            break;

        case Swiat::Ruch::SPECJALNY:

            if(!turySpecjalne){

                turySpecjalne = CZLOWIEK_SPECJALNY_TURY;

            }

            break;



    }

}

std::string Czlowiek::jakoString() const {
    return "CZLOWIEK";
}
