#pragma once

#include <vector>

#include "Organizm.h"



class Swiat {

public:

    enum Ruch {
        GORA,
        DOL,
        LEWO,
        PRAWO,
        SPECJALNY
    };

    Swiat(uint wysokosc, uint szerokosc);
    Swiat(uint wysokosc, uint szerokosc, std::vector<Organizm*>&& organizmy);

    ~Swiat();

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

    void setRuch(Ruch ruch);

private:

    uint wysokosc;
    uint szerokosc;

    uint nrTury = 0;

    Ruch ruch;

    std::vector<Organizm*> organizmy;

    void logOrganizmy();


    void ruchOrganizmow();
    void rysujNaglowek() const;
    void rysujGranice() const;

    void rysujSwiat();

    void pozbadzSieZwlok();




};
