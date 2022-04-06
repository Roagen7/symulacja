#pragma once

#include "Zwierze.h"

class Lis : public Zwierze{

public:

    explicit Lis(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;


private:

    bool czyMaDobryWech() const override;

    [[nodiscard]] Lis* kopia() const override;


};

