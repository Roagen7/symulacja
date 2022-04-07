#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze {

public:

    explicit Czlowiek(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;


private:

    [[nodiscard]] Czlowiek* kopia() const override;




};

