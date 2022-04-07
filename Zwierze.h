#pragma once

#include <random>

#include "Organizm.h"
#include "Swiat.h"
#include "config.h"

class Zwierze : public Organizm {

public:

    Zwierze(Wektor2d polozenie, uint sila, uint inicjatywa);

    void akcja() override;
    void kolizja() override;

    void info(std::ostream &os) const override;

    void nowaTura() override;

protected:

    void losowyRuch(int zasieg = 1);

    void zmienPolozenie(Wektor2d przemieszczenie);

private:

    bool rozmnozylSie = false;


    void walcz(Organizm* drugi);

    void rozmnozSie(Zwierze* drugi);

    void cofnijSie();

    Wektor2d wczesniejszePolozenie;


};


