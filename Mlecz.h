#pragma once

#include "Roslina.h"

class Mlecz : public Roslina {

public:

    explicit Mlecz(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void akcja() override;

private:

    [[nodiscard]] Mlecz* kopia() const override;

};
