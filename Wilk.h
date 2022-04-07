#pragma once

#include "Zwierze.h"
#include "config.h"

class Wilk : public Zwierze {

public:

    explicit Wilk(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;
    std::string jakoString() const override;

private:

    [[nodiscard]] Wilk* kopia() const override;

};



