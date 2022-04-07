#pragma once

#include "symulacja.h"
#include "config.h"

#include <unistd.h>


class Gra {

public:

    Gra();

    void menu();

private:

    bool graj=true;

    Swiat* swiat;

    void start();

    void opcjeGracza();

    void swiatBazowy();

    static char getch();

};


