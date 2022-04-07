#pragma once

#include "Roslina.h"

class Guarana : public Roslina {

public:

    explicit Guarana(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void dodajModyfikator(Organizm* organizm) const override;

    std::string jakoString() const override;

private:

    [[nodiscard]] Guarana* kopia() const override;



};

