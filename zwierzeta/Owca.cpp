#include "Owca.h"

Owca::Owca(Wektor2d polozenie): Zwierze(polozenie,OWCA_SILA,OWCA_INICJATYWA) {

}

std::string Owca::rysowanie() const {
    return "\e[30mo\e[0m";;
}

Owca *Owca::kopia() const {
    return new Owca{polozenie};
}

std::string Owca::jakoString() const {
    return "OWCA";
}
