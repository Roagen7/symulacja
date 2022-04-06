#pragma once

#include "Organizm.h"
#include "Swiat.h"

#define INICJATYWA_ROSLINY 0
#define P_ROZSIANIA 0.03


class Roslina : public Organizm {


public:

    Roslina(Wektor2d pozycja, uint sila);

    [[nodiscard]] std::string rysowanie() const override;
    void akcja() override;

    void kolizja() override;

    void info(std::ostream &os) const override;

    void nowaTura() override {};

private:
    void rozsiej();

};


