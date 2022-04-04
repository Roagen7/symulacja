#include "Zwierze.h"

void Zwierze::akcja() {

}

std::string Zwierze::rysowanie() const {

    return "z";
}

void Zwierze::kolizja() {

}

Zwierze::Zwierze(Punkt polozenie, uint sila, uint inicjatywa) : Organizm(polozenie, sila, inicjatywa) {

}
