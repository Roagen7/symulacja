#pragma once

#include "../Zwierze.h"
#include "../Roslina.h"

class BarszczSosnowskiego : public Roslina{

public:

    explicit BarszczSosnowskiego(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void dodajModyfikator(Organizm* organizm) const override;

    void akcja() override;

    std::string jakoString() const override;

private:
    
    [[nodiscard]] BarszczSosnowskiego* kopia() const override;





};

