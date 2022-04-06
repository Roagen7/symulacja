
#include "Wilk.h"

Wilk::Wilk(Wektor2d polozenie) : Zwierze(polozenie, WILK_SILA, WILK_INICJATYWA) {

}

std::string Wilk::rysowanie() const {
    return "\e[31mw\e[0m";
}

Wilk *Wilk::kopia() const{
    return new Wilk{polozenie};
}
