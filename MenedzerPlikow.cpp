#include "MenedzerPlikow.h"


void MenedzerPlikow::zapisz(Swiat *swiat, std::string plik) {

    auto organizmy = swiat->getOrganizmy();

    std::ofstream out(plik);

    out << swiat->getNrTury() << " " << swiat->getWysokosc() << " " << swiat->getSzerokosc() << std::endl;


    for(auto* organizm : organizmy){

        out <<  organizm->jakoString() << " " <<
                organizm->getWiek() << " " <<
                organizm->getPolozenie().y << " " <<
                organizm->getPolozenie().x << std::endl;

    }

    out.close();

}

int MenedzerPlikow::wczytaj(Swiat*& swiat, std::string plik) {

    try {

        std::ifstream in(plik);
        if(in.fail()){

            in.close();
            throw std::runtime_error("plik nie istnieje lub wystąpił błąd z jego otwarciem");

        }

        int tura,wys,szer;

        in >> tura >> wys >> szer;

        std::vector<Organizm*> orgs;

        int licznik = 0;

        while(!in.eof()){

            wczytajOrganizm(in,orgs);
            licznik++;

            if(licznik >= MAX_DLUGOSC_PLIKU_STATE){

                throw std::runtime_error("błąd składniowy lub plik za długi");

            }

        }

        swiat = new Swiat(wys,szer,std::move(orgs));
        swiat->setNrTury(tura);

        in.close();

        return 0;

    } catch (std::exception & ex){

        std::cout << ex.what() << std::endl;

        return 1;
    }


}

void MenedzerPlikow::wczytajOrganizm(std::ifstream &in, std::vector<Organizm *>& orgs) {

    std::string nazwa;
    int y,x;
    int wiek;

    in >> nazwa >> wiek >> y >> x;

    Organizm* nowy = alokujPoNazwie(nazwa);

    if(nowy != nullptr){

        nowy->setPolozenie({y,x});
        nowy->setWiek(wiek);

        orgs.push_back(nowy);

    }


}

Organizm *MenedzerPlikow::alokujPoNazwie(std::string nazwa) {

    Wektor2d p0 = {0,0};

    std::vector<Organizm*> wszystkie = {
        new Czlowiek(p0),
        new Wilk(p0),
        new Owca(p0),
        new Lis(p0),
        new Zolw(p0),
        new Antylopa(p0),
        new Trawa(p0),
        new Mlecz(p0),
        new Guarana(p0),
        new WilczeJagody(p0),
        new BarszczSosnowskiego(p0)
    };

    Organizm* wybrany = nullptr;


    for(auto* org : wszystkie){

        if(org->jakoString() == nazwa){

            wybrany = org->kopia();

        }

    }

    for(auto* org : wszystkie){

        delete org;

    }

    if(wybrany != nullptr){

        return wybrany;

    }
    return nullptr;

}
