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

            rozsiej();

    }


}

std::string Mlecz::jakoString() const {
    return "MLECZ";
}
