#pragma once

#include "../Roslina.h"

class WilczeJagody : public Roslina{

public:

    explicit WilczeJagody(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

    void dodajModyfikator(Organizm* organizm) const override;
    std::string jakoString() const override;
private:

    [[nodiscard]] WilczeJagody* kopia() const override;





};

