#include <iostream>
#include "Swiat.h"

void Swiat::wykonajTure() {

    nrTury++;

    rysujNaglowek();


    ruchOrganizmow();

    std::cout << "~~~~~~~~~~~~~~~~~~\e[0m" << std::endl << std::endl;


    rysujSwiat();

}

void Swiat::rysujSwiat() {

    for(uint y = 0; y < wysokosc; y++){

        for(uint x = 0; x < szerokosc; x++){

            auto* lokator = getOrganizmNaPozycji({(int) y,(int) x});

            if(lokator == nullptr){

                std::cout << " ";

            } else {

                std::cout << lokator->rysowanie();

            }

        }

        std::cout << std::endl;

    }

}

Swiat::Swiat(uint wysokosc, uint szerokosc):
    wysokosc(wysokosc),
    szerokosc(szerokosc) {

    srand(time(nullptr));

}

Organizm *Swiat::getOrganizmNaPozycji(Wektor2d p) {

    for(auto* organizm : organizmy){

        if(p == organizm->getPolozenie()){

            return organizm;

        }

    }
    return nullptr;

}

void Swiat::addOrganizm(Organizm* organizm) {

    organizm->setSwiat(this);
    organizmy.push_back(organizm);

}

void Swiat::rysujNaglowek() const {

    std::cout <<  std::endl<<"\e[35mtura nr " << nrTury  <<"\e[0m"<<std::endl << std::endl;

    std::cout <<"\e[34m Dziennik~~~~~~~~~~" << std::endl;




}

void Swiat::ruchOrganizmow() {

    std::sort(organizmy.begin(),organizmy.end(),[](Organizm* org1, Organizm* org2){

        return org1->getInicjatywa() > org2->getInicjatywa();

    });

    for(auto* organizm: organizmy){

        organizm->akcja();

    }



    logOrganizmy();

}

void Swiat::logOrganizmy() {
    std::cout << "lista zywych zwierzat: [ " << std::endl;
    for(const auto* organizm : organizmy){

        std::cout << "-" <<*organizm << std::endl;

    }
    std::cout << "]" << std::endl;
}

uint Swiat::getWysokosc() {
    return wysokosc;
}

uint Swiat::getSzerokosc() {
    return szerokosc;
}

uint Swiat::getNrTury() const {
    return nrTury;
}

void Swiat::zabijOrganizm(Organizm *organizm) {

    int ix = 0;

    for(const auto* org : organizmy){

        if(org == organizm){

            std::cout << *organizm << " umiera" << std::endl;

            organizmy.erase(organizmy.begin() + ix);
            return;

        }

        ix++;

    }

}

void Swiat::obecnyStan() {
    std::cout << "\e[34m";
    logOrganizmy();
    std::cout << "\e[0m";


    rysujSwiat();


}
