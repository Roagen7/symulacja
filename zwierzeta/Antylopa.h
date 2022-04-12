#pragma once

#include "../Zwierze.h"

class Antylopa : public Zwierze {

public:

    explicit Antylopa(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void akcja() override;

    bool czyUciekl() const override;

    std::string jakoString() const override;

private:

    [[nodiscard]] Antylopa* kopia() const override;


};



