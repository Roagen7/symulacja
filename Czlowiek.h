#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze {

public:

    explicit Czlowiek(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void akcja() override;

    std::string jakoString() const override;

private:

    int turySpecjalne = 0;


    [[nodiscard]] Czlowiek* kopia() const override;




};

