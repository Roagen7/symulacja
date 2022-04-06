#pragma once

#include "Roslina.h"

class Mlecz : public Roslina {

public:

    explicit Mlecz(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void akcja() override;

    [[nodiscard]] Mlecz* kopia() const override;



};
