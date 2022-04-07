
#include <iostream>
#include <termios.h>


#include "Gra.h"


Gra::Gra() {

    menu();

}

void Gra::menu() {

    char opcja;
    bool menu = true;

    while(menu){
        system("clear");
        std::cout << "z) bazowy swiat \nx) swiat z pliku \nq) wyjdz" << std::endl;

        std::cin >> opcja;

        switch(opcja){

            case 'z':
                menu = false;
                swiatBazowy();
                break;

            case 'x':

                break;

            case 'q':
                menu = false;
                graj = false;
        }
    }
    start();

}

void Gra::start() {

    system("clear");

    while(graj){


        swiat->wykonajTure();
        opcjeGracza();

    }

}

void Gra::swiatBazowy() {

    swiat = new Swiat(DOMYSLNA_WYSOKOSC,DOMYSLNA_SZEROKOSC,{

            new Trawa({5,5}),
            new Wilk({3,4}),
            new Owca(Wektor2d{9, 9}),
            new Mlecz({1,7}),
            new Guarana({2,8}),
            new Guarana({2,9}),
            new Owca({4,4}),
            new Owca(Wektor2d{9, 8}),
            new WilczeJagody(Wektor2d{10, 10}),
            new WilczeJagody(Wektor2d{10, 9}),
            new BarszczSosnowskiego(Wektor2d{9, 10}),
            new Owca(Wektor2d{19, 19}),
            new Owca(Wektor2d{19, 18}),
            new Zolw(Wektor2d{15, 16}),
            new Zolw(Wektor2d{14, 15}),
            new Lis({10,14}),
            new Lis({11,15}),
            new Antylopa({10,0}),
            new Antylopa({12,0}),
            new Czlowiek({0,19})

    });

}

void Gra::opcjeGracza() {

    std::cout << "sterowanie: enter) nastepna tura strzalki) czlowiek z)szybkosc antylopy w)zapis i wyjście q) wyjscie bez zapisu" << std::endl;

    switch(getch()){

        case 'q':
            graj=false;
            break;

        case '\033':
            getch();
            switch(getch()){
                case 'A':
                    swiat->setRuch(Swiat::Ruch::GORA);
                    break;

                case 'B':
                    swiat->setRuch(Swiat::Ruch::DOL);
                    break;

                case 'C':
                    swiat->setRuch(Swiat::Ruch::PRAWO);
                    break;

                case 'D':
                    swiat->setRuch(Swiat::Ruch::LEWO);
                    break;
            }
            break;

        case 'z':
            swiat->setRuch(Swiat::Ruch::SPECJALNY);

            break;

        case 'w':
            menedzerPlikow.zapisz(swiat,"../stany_gry/zapis.state");
            graj=false;
            break;

    }

}

char Gra::getch()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}