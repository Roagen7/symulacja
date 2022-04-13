#include "Dziennik.h"

void Dziennik::operator<<(std::string komunikat) {

    komunikaty.push_back(komunikat);

}

void Dziennik::wypisz() {

    std::cout <<"\e[34m Dziennik~~~~~~~~~~" << std::endl;

    for(const auto& kom : komunikaty){

        std::cout << kom << std::endl;

    }

    std::cout << "~~~~~~~~~~~~~~~~~~\e[0m" << std::endl << std::endl;

}

void Dziennik::czysc() {

    komunikaty.clear();

}
