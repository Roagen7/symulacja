#pragma once

#include "symulacja.h"
#include "config.h"
#include "MenedzerPlikow.h"

#include <unistd.h>


class Gra {

public:

    Gra();

    void menu();

private:

    bool graj=true;

    Swiat* swiat;
    MenedzerPlikow menedzerPlikow;

    void start();

    void opcjeGracza();

    void swiatBazowy();

    static char getch();

};


