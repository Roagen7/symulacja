//
// Created by roagen on 06.04.2022.
//

#include "Lis.h"

Lis::Lis(Wektor2d polozenie) : Zwierze(polozenie, LIS_SILA, LIS_INICJATYWA){

}

std::string Lis::rysowanie() const {
    return "\e[31ml\e[0m";
}

Lis *Lis::kopia() const {
    return new Lis{this->polozenie};
}

bool Lis::czyMaDobryWech() const {
    return true;
}


