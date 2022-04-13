#pragma once

#include <unistd.h>
#include <iostream>
#include <termios.h>

#include "symulacja.h"
#include "config.h"
#include "pomocnicze/MenedzerPlikow.h"


class Gra {

public:

    void menu();

private:

    bool czyNastepnaTura = true;

    bool graj=true;

    Swiat* swiat = nullptr;
    MenedzerPlikow menedzerPlikow;

    void start();

    void zapisDialog();

    void wczytajDialog();

    void dziennikDialog();

    void opcjeGracza();

    void opcjePoruszanie();

    void rysujInterfejs();

    void swiatBazowy();

    static char getch();

};


