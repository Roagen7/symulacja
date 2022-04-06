#include "Trawa.h"

Trawa::Trawa(Wektor2d polozenie): Roslina(polozenie, TRAWA_SILA) {

}

std::string Trawa::rysowanie() const {
    return "\e[32m╧\e[0m";
}

Trawa *Trawa::kopia() const {
    return new Trawa{*this};
}
