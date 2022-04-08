#include "Swiat.h"

void Swiat::wykonajTure() {

    system("clear");
    oglosNowaTure();

    nrTury++;

    ruchOrganizmow();

    pozbadzSieZwlok();

}

void Swiat::rysujSwiat() {

    rysujNaglowek();

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

        if(p == organizm->getPolozenie() && organizm->isZywy()){

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


}

void Swiat::ruchOrganizmow() {

    std::sort(organizmy.begin(),organizmy.end(),[](Organizm* org1, Organizm* org2){

        if(org1->getInicjatywa() == org2->getInicjatywa()){

            return org1->getWiek() > org2->getWiek();

        }

        return org1->getInicjatywa() > org2->getInicjatywa();

    });

    int ix = 0;
    for(int i = 0; i < organizmy.size(); i++){

        auto* organizm = organizmy[i];

        if(organizm->isZywy() && organizm->getWiek() != 0){

            organizm->akcja();
            organizm->kolizja();

        }

        organizm->starzejSie();
        ix++;
    }



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

           
            org->zabij();


            return;

        }

    }

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
        && org != organizm
        && org->isZywy()){

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

Wektor2d Swiat::getWolnePoleObok(Wektor2d p) {

    for(int dy = -1; dy <= 1; dy++){

        for(int dx = -1; dx <= 1; dx++){

            Wektor2d sprawdzanyPunkt = {p.y + dy, p.x + dx};

            if(sprawdzanyPunkt != p
            && getOrganizmNaPozycji(sprawdzanyPunkt) == nullptr
            && !sprawdzanyPunkt.pozaGranicami(wysokosc,szerokosc)){

                return sprawdzanyPunkt;

            }

        }

    }

    return p;

}

void Swiat::oglosNowaTure() {

    dziennik.czysc();

    for(auto* organizm : organizmy){

        organizm->nowaTura();

    }

}

Swiat::Swiat(uint wysokosc, uint szerokosc, std::vector<Organizm*>&& organizmy):
    szerokosc(szerokosc),
    wysokosc(wysokosc),
    organizmy(std::move(organizmy)){

    for(auto* org : this->organizmy){

        org->setSwiat(this);

    }

}

Swiat::~Swiat() {

    for(auto* org : organizmy){

        delete org;

    }

}

void Swiat::setRuch(Swiat::Ruch ruch) {

    this->ruch = ruch;

}

Swiat::Ruch Swiat::getRuch() {
    return ruch;
}

Swiat::Ruch Swiat::popRuch() {
    auto obecny = ruch;
    ruch = Swiat::Ruch::STOJ;

    return obecny;
}

const std::vector<Organizm *> &Swiat::getOrganizmy() {

    return organizmy;

}

Dziennik &Swiat::getDziennik() {
    return dziennik;
}

void Swiat::setNrTury(int tura) {

    this->nrTury = tura;

}



