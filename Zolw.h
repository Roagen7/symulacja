#pragma once

#include "Zwierze.h"

class Zolw : public Zwierze{

public:

    explicit Zolw(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void akcja() override;

    bool czyOdbilAtak(const Organizm *org) const override;

private:

    [[nodiscard]] Zolw* kopia() const override;


};

