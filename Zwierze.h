#pragma once

#include <random>

#include "Organizm.h"
#include "Swiat.h"

class Zwierze : public Organizm {

public:

    Zwierze(Wektor2d polozenie, uint sila, uint inicjatywa);

    void akcja() override;
    void kolizja() override;

    void info(std::ostream &os) const override;

    [[nodiscard]] std::string rysowanie() const override;


private:

    void zmienPolozenie(Wektor2d przemieszczenie);
    void cofnijSie();

    Wektor2d wczesniejszePolozenie;

};


