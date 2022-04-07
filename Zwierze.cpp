#include <iostream>
#include "Zwierze.h"

void Zwierze::akcja() {
    losowyRuch();

}

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

    if(ucieczka() || drugi->ucieczka()) return;

    if(*this < *drugi){

        if(this->czyOdbilAtak(drugi)){

            cofnijSie();
            return;

        }

        std::cout << drugi->jakoString() << " zjada " << this->jakoString() << std::endl;
        this->zabij();
        dodajModyfikator(drugi);

    } else {

        if(drugi->czyOdbilAtak(this)){

            cofnijSie();
            return;

        }

        std::cout << this->jakoString() << " zjada " << drugi->jakoString() << std::endl;
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

    std::cout << this->jakoString() << " rozmnaza sie z " << drugi->jakoString() << std::endl;

}

void Zwierze::nowaTura() {

    rozmnozylSie = false;

}

void Zwierze::losowyRuch(int zasieg) {

    int koordynaty[] = {-1 * (int)zasieg,0,zasieg};

    Wektor2d przemieszczenie{0,0};
    Wektor2d wczesniejsze = polozenie;

    do {
        polozenie = wczesniejsze;

        int randX = koordynaty[random() % 3];
        int randY = koordynaty[random() % 3];

        przemieszczenie = {randY, randX};

        zmienPolozenie(przemieszczenie);

    } while(wczesniejsze == polozenie ||
            (czyMaDobryWech() &&
            swiat->getOrganizmNaPozycji(przemieszczenie) != nullptr &&
            swiat->getOrganizmNaPozycji(przemieszczenie)->getSila() > getSila()));


}

std::string Zwierze::jakoString() const {
    return "";
}




