#include <iostream>
#include "Zwierze.h"

void Zwierze::akcja() {

    int koordynaty[] = {-1,0,1,};

    Wektor2d przemieszczenie{0,0};
    Wektor2d wczesniejsze = polozenie;

    do {
        polozenie = wczesniejsze;

        int randX = koordynaty[random() % 3];
        int randY = koordynaty[random() % 3];

        przemieszczenie = {randY, randX};

        zmienPolozenie(przemieszczenie);

    } while(wczesniejsze == polozenie);

    std::cout << "Zwierze zmienilo polozenie z "
    << wczesniejsze.y << " " << wczesniejsze.x << " na "
    << polozenie.y << " " << polozenie.x << std::endl;


}

std::string Zwierze::rysowanie() const {

    return "\e[31mz\e[0m";
}

void Zwierze::kolizja() {

}

Zwierze::Zwierze(Wektor2d polozenie, uint sila, uint inicjatywa) :
Organizm(polozenie, sila, inicjatywa),
wczesniejszePolozenie(polozenie) {

    std::cout << *this << " rodzi sie" << std::endl;

}

void Zwierze::info(std::ostream &os) const {

    os << "Zwierze";

}

void Zwierze::zmienPolozenie(Wektor2d przemieszczenie) {



    if(!(polozenie + przemieszczenie).pozaGranicami(
            swiat->getWysokosc(),
            swiat->getSzerokosc())){

        wczesniejszePolozenie = polozenie;
        polozenie += przemieszczenie;

    }


}

void Zwierze::cofnijSie() {

    polozenie = wczesniejszePolozenie;

}
