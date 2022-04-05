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

    void starzejSie();


    void setSwiat(Swiat* swiat);
    Swiat* getSwiat();

    bool isZywy() const;
    void zabij();

    virtual ~Organizm() = default;

    uint getWiek() const;

protected:

    Organizm(Wektor2d polozenie, uint sila, uint inicjatywa);
    uint sila;
    uint inicjatywa;
    uint wiek = 0;
    bool zywy = true;

    Wektor2d polozenie;

    void setWiek(uint wiek);

    virtual void info(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    friend bool operator<(const Organizm& o1, const Organizm& o2);
    friend bool operator>(const Organizm& o1, const Organizm& o2);

    Swiat* swiat;


};

