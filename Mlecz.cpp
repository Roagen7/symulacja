//
// Created by roagen on 06.04.2022.
//

#include "Mlecz.h"

Mlecz::Mlecz(Wektor2d polozenie): Roslina(polozenie,MLECZ_SILA) {

}

std::string Mlecz::rysowanie() const {
    return "\e[32m✿\e[0m";
}

Mlecz *Mlecz::kopia() const {
    return new Mlecz{*this};
}

void Mlecz::akcja() {

    for(int i = 0; i < MLECZ_PROBY; i++){

        if((float)rand()/(float)RAND_MAX < P_ROZSIANIA){

            rozsiej();
            break;

        }

    }


}
