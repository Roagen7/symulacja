#pragma once

#include "Roslina.h"

class Trawa : public Roslina{

public:

    explicit Trawa(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

private:

    [[nodiscard]] Trawa* kopia() const override;

};

