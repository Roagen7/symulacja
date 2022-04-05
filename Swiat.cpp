#include <iostream>
#include "Swiat.h"

void Swiat::wykonajTure() {

    system("clear");
    nrTury++;

    rysujNaglowek();

    ruchOrganizmow();

    std::cout << "~~~~~~~~~~~~~~~~~~\e[0m" << std::endl << std::endl;

    rysujSwiat();
    pozbadzSieZwlok();

}

void Swiat::rysujSwiat() {

    rysujGranice();

    for(uint y = 0; y < wysokosc; y++){

        std::cout << "\e[35m|\e[0m";
        for(uint x = 0; x < szerokosc; x++){

            auto* lokator = getOrganizmNaPozycji({(int) y,(int) x});

            if(lokator == nullptr || !lokator->isZywy()){

                std::cout << " ";

            } else {

                std::cout << lokator->rysowanie();

            }

        }

        std::cout << "\e[35m|\e[0m";

        std::cout << std::endl;

    }

    rysujGranice();

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

        if(org1->getInicjatywa() == org2->getInicjatywa()){

            return org1->getWiek() > org2->getWiek();

        }

        return org1->getInicjatywa() > org2->getInicjatywa();

    });


    for(auto* organizm: organizmy){

        if(organizm->getWiek() != 0){

            organizm->akcja();
            organizm->kolizja();

        }

        organizm->starzejSie();

    }

    logOrganizmy();

}

void Swiat::logOrganizmy() {
    std::cout << "lista zywych zwierzat: [ " << std::endl;
    for(const auto* organizm : organizmy){

        if(organizm->isZywy()){

            std::cout << "-" <<*organizm << std::endl;

        }

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



    for(auto* org : organizmy){

        if(org == organizm){

            std::cout << *organizm << " umiera" << std::endl;
            org->zabij();


            return;

        }



    }

}

void Swiat::obecnyStan() {
    std::cout << "\e[34m";
    logOrganizmy();
    std::cout << "\e[0m";


    rysujSwiat();


}

void Swiat::rysujGranice() const {

    std::cout << "\e[35m+";

    for(int i = 0; i < szerokosc; i++){

        std::cout << "-";

    }

    std::cout << "+\e[0m" << std::endl;

}

Organizm *Swiat::getKolidujacy(Organizm* org) {

    for(auto* organizm : organizmy){

        if(org->getPolozenie() == organizm->getPolozenie()
        && org != organizm){

            return organizm;

        }

    }

    return nullptr;
}

void Swiat::pozbadzSieZwlok() {

    int ix = 0;

    for(auto* organizm: organizmy){

        if(!organizm->isZywy()){

            organizmy.erase(organizmy.begin()+ix);
            pozbadzSieZwlok();
            break;

        }
        ix++;

    }


}
