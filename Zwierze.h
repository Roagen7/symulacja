#pragma once

#include "Organizm.h"
#include "Swiat.h"
#include "config.h"

#include <random>

class Zwierze : public Organizm {

public:

    Zwierze(Wektor2d polozenie, uint sila, uint inicjatywa);

    void akcja() override;
    void kolizja() override;

    void nowaTura() override;

    std::string jakoString() const override;

protected:

    void losowyRuch(int zasieg = 1);

    void zmienPolozenie(Wektor2d przemieszczenie);

private:

    bool rozmnozylSie = false;
    Wektor2d wczesniejszePolozenie;


    void walcz(Organizm* drugi);

    void rozmnozSie(Zwierze* drugi);

    void cofnijSie();


    bool wszyscySasiedziSilniejsi();


};


