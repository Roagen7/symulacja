#pragma once

#include <vector>

#include "Organizm.h"



class Swiat {

public:
    Swiat(uint wysokosc, uint szerokosc);


    void wykonajTure();
    void rysujSwiat();

    void addOrganizm(Organizm* organizm);

    Organizm* getOrganizmNaPozycji(Punkt p);


private:

    uint wysokosc;
    uint szerokosc;

    std::vector<Organizm*> organizmy;

};
