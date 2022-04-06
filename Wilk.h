#pragma once

#include "Zwierze.h"
#include "config.h"

class Wilk : public Zwierze {

public:

    Wilk(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

private:

    [[nodiscard]] Wilk* kopia() const override;


};



