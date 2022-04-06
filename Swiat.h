#pragma once

#include <vector>

#include "Organizm.h"



class Swiat {

public:
    Swiat(uint wysokosc, uint szerokosc);

    void obecnyStan();
    void wykonajTure();

    void oglosNowaTure();

    void addOrganizm(Organizm* organizm);
    void zabijOrganizm(Organizm* organizm);


    uint getWysokosc();
    uint getSzerokosc();
    uint getNrTury() const;

    Organizm* getKolidujacy(Organizm* org);
    Wektor2d getWolnePoleObok(Wektor2d p);
    Organizm* getOrganizmNaPozycji(Wektor2d p);

private:

    uint wysokosc;
    uint szerokosc;

    uint nrTury = 0;

    std::vector<Organizm*> organizmy;

    void logOrganizmy();


    void ruchOrganizmow();
    void rysujNaglowek() const;
    void rysujGranice() const;

    void rysujSwiat();

    void pozbadzSieZwlok();




};
