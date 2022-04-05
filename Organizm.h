#pragma once

#include <string>

#include "Wektor2d.h"


class Swiat;

class Organizm {

public:

    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    [[nodiscard]] virtual std::string rysowanie() const = 0;

    [[nodiscard]] Wektor2d getPolozenie() const;
    [[nodiscard]] uint getInicjatywa() const;


    void setSwiat(Swiat* swiat);
    Swiat* getSwiat();




    virtual ~Organizm() = default;

protected:

    Organizm(Wektor2d polozenie, uint sila, uint inicjatywa);
    uint sila;
    uint inicjatywa;
    Wektor2d polozenie;


    virtual void info(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    Swiat* swiat;






};

