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




}

//std::string Zwierze::rysowanie() const {
//
//    return "\e[31mz\e[0m";
//}

void Zwierze::kolizja() {

    Organizm* drugi = swiat->getKolidujacy(this);

    if(drugi == nullptr) return;

    if(drugi->rysowanie() == this->rysowanie()){

        rozmnozSie((Zwierze*) drugi);

    } else {

        walcz(drugi);

    }


}

Zwierze::Zwierze(Wektor2d polozenie, uint sila, uint inicjatywa) :
Organizm(polozenie, sila, inicjatywa),
wczesniejszePolozenie(polozenie) {

    std::cout << *this << " rodzi sie" << std::endl;

}

void Zwierze::info(std::ostream &os) const {

    os << "Zwierze" <<
    " w wieku " << wiek;

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

void Zwierze::walcz(Organizm *drugi) {

    if(*this < *drugi){

        std::cout << *drugi << " zjada " << *this << std::endl;
        this->zabij();
        dodajModyfikator(drugi);

    } else {

        std::cout << *this << " zjada " << *drugi << std::endl;
        drugi->zabij();
        drugi->dodajModyfikator(this);
    }

}

void Zwierze::rozmnozSie(Zwierze *drugi) {

    if(drugi->getWiek() == 0 ){

        return;

    }

    auto* org = this->kopia();

    this->cofnijSie();
    Wektor2d miejsceNarodzin = swiat->getWolnePoleObok(drugi->getPolozenie());

    if(miejsceNarodzin == drugi->getPolozenie() || rozmnozylSie || drugi->rozmnozylSie){

        delete org;
        return;

    }
    org->setPolozenie(miejsceNarodzin);

    swiat->addOrganizm(org);
    rozmnozylSie = true;
    drugi->rozmnozylSie = true;

    std::cout << *this << " rozmnaza sie z " << *drugi << std::endl;

}

void Zwierze::nowaTura() {

    rozmnozylSie = false;

}


