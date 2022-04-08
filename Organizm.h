#pragma once

#include "Wektor2d.h"

#include <string>

class Swiat;

class Organizm {

public:

    [[nodiscard]] Wektor2d getPolozenie() const;
    [[nodiscard]] uint getInicjatywa() const;

    void starzejSie();

    void setSila(uint sila);
    uint getSila() const;

    void setSwiat(Swiat* swiat);
    void setPolozenie(Wektor2d polozenie);
    Swiat* getSwiat();

    bool isZywy() const;
    void zabij();

    virtual ~Organizm() = default;

    uint getWiek() const;

    virtual void dodajModyfikator(Organizm* organizm) const;

    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    virtual void nowaTura() = 0;

    [[nodiscard]] virtual std::string rysowanie() const = 0;
    virtual std::string jakoString() const = 0;

    [[nodiscard]] virtual bool czyOdbilAtak(const Organizm *org) const;
    [[nodiscard]] virtual bool czyUciekl() const;

    bool ucieczka();


    void setWiek(uint wiek);

    [[nodiscard]] virtual Organizm* kopia() const = 0;

protected:

    uint sila;
    uint inicjatywa;
    uint wiek = 0;
    bool zywy = true;
    Swiat* swiat;

    Wektor2d polozenie;

    Organizm(Wektor2d polozenie, uint sila, uint inicjatywa);


    [[nodiscard]] virtual bool czyMaDobryWech() const;


    friend bool operator<(const Organizm& o1, const Organizm& o2);
    friend bool operator>(const Organizm& o1, const Organizm& o2);



};

