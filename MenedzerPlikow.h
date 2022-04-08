#pragma once

#include "Swiat.h"
#include "symulacja.h"

#include <fstream>

class MenedzerPlikow {

public:

    void zapisz(Swiat* swiat, std::string plik);
    int wczytaj(Swiat*& swiat, std::string plik);

private:

    void wczytajOrganizm(std::ifstream& in, std::vector<Organizm*>& orgs);

    Organizm* alokujPoNazwie(std::string nazwa);


};


