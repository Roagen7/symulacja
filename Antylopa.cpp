//
// Created by roagen on 06.04.2022.
//

#include "Antylopa.h"

Antylopa::Antylopa(Wektor2d polozenie) : Zwierze(polozenie,ANTYLOPA_SILA,ANTYLOPA_INICJATYWA){

}

std::string Antylopa::rysowanie() const {
    return "\e[30mA\e[0m";
}

Antylopa *Antylopa::kopia() const {
    return new Antylopa{polozenie};
}

void Antylopa::akcja() {

    losowyRuch(ANTYLOPA_ZASIEG);

}

bool Antylopa::czyUciekl() const {

    return (float)rand()/(float)RAND_MAX < ANTYLOPA_P_UCIECZKI;

}

std::string Antylopa::jakoString() const {
    return "ANTYLOPA";
}
