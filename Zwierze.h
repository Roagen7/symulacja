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
    void nowaTura() override;

private:

    bool rozmnozylSie = false;

    void zmienPolozenie(Wektor2d przemieszczenie);

    void walcz(Organizm* drugi);

    void rozmnozSie(Zwierze* drugi);

    void cofnijSie();

    Wektor2d wczesniejszePolozenie;


};


