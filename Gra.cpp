#include "Gra.h"

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

                wczytajDialog();
                czyNastepnaTura = true;
                menu= false;
                break;

            case 'q':
                menu = false;
                graj = false;
        }
    }
    start();

}

void Gra::start() {


    while(graj){

        if(czyNastepnaTura){

            swiat->wykonajTure();

        }

        rysujInterfejs();

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


    czyNastepnaTura = true;

    switch(getch()){

        case 'q':
            graj=false;
            break;

        case '\033':
            getch();

            opcjePoruszanie();
            break;

        case 'z':
            swiat->setRuch(Swiat::Ruch::SPECJALNY);

            break;

        case 'w':
            zapisDialog();

            break;

        case 'd':
            dziennikDialog();
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

void Gra::opcjePoruszanie() {

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


}

void Gra::rysujInterfejs() {

    system("clear");

    std::cout << "DOMINIK LAU 188697" << std::endl;

    swiat->rysujSwiat();

    std::cout << "sterowanie: " <<
    "enter) nastepna tura " <<
    "strzalki) czlowiek " <<
    "z) szybkosc antylopy "  <<
    "w) zapis " <<
    "q) wyjscie " <<
    "d) dziennik " << std::endl;

}

void Gra::zapisDialog() {

            system("clear");

            std::string nazwaPliku;
            std::cout << "podaj nazwe pliku: ";
            std::cin >> nazwaPliku;

            menedzerPlikow.zapisz(swiat,"../stany_gry/" + nazwaPliku + ".state");
            czyNastepnaTura=false;

}

void Gra::dziennikDialog() {

    system("clear");

    swiat->getDziennik().wypisz();
    std::cout << "dowolny przycisk by kontynuować..." << std::endl;
    getch();
    czyNastepnaTura=false;

}

void Gra::wczytajDialog() {

    std::cout << "podaj nazwe pliku: ";

    std::string nazwa;
    std::cin >> nazwa;

    if(menedzerPlikow.wczytaj(swiat,"../stany_gry/" + nazwa + ".state")){

        std::cout << "dowolny przycisk by kontynuować..." << std::endl;
        getch();
        graj = false;

    }
    czyNastepnaTura=false;

}
