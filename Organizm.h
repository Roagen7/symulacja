#pragma once

#include <string>

#include "Punkt.h"
#include "deklaracje.h"

class Organizm {

public:

    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    [[nodiscard]] virtual std::string rysowanie() const = 0;

    [[nodiscard]] Punkt getPolozenie() const;
    void setSwiat(Swiat* swiat);
    Swiat* getSwiat();

    virtual ~Organizm() = default;

protected:

    Organizm(Punkt polozenie, uint sila, uint inicjatywa);
    uint sila;
    uint inicjatywa;
    Punkt polozenie;

private:

    Swiat* swiat;


};

