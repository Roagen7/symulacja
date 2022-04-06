#pragma once

#include "Zwierze.h"
#include "config.h"

class Owca : public Zwierze{

public:
    explicit Owca(Wektor2d polozenie);
    [[nodiscard]] std::string rysowanie() const override;

private:

    [[nodiscard]] Owca* kopia() const override;


};


