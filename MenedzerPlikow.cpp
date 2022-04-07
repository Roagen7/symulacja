#include "MenedzerPlikow.h"

void MenedzerPlikow::zapisz(Swiat *swiat, std::string plik) {

    auto organizmy = swiat->getOrganizmy();

    std::ofstream out(plik);

    for(auto* organizm : organizmy){

        out <<  organizm->jakoString() << " " <<
                organizm->getWiek() << " " <<
                organizm->getPolozenie().y << " " <<
                organizm->getPolozenie().x << std::endl;

    }

    out.close();

}

void MenedzerPlikow::wczytaj(Swiat *swiat, std::string plik) {

}
