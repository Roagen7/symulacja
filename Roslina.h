#pragma once

#include "Organizm.h"
#include "Swiat.h"

#include "config.h"

#define INICJATYWA_ROSLINY 0


class Roslina : public Organizm {


public:

    Roslina(Wektor2d pozycja, uint sila);

    [[nodiscard]] std::string rysowanie() const override;
    void akcja() override;

    void kolizja() override;


    void nowaTura() override {};

    std::string jakoString() const override;

protected:
    void rozsiej();

};


