#pragma once

#include <vector>
#include <string>
#include <iostream>

class Dziennik {
public:

    void operator<<(std::string komunikat);
    void wypisz();


    void czysc();

private:

    std::vector<std::string> komunikaty;


};

