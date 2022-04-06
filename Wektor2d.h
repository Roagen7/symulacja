#pragma once

typedef unsigned int uint;

struct Wektor2d {

    int y, x;

    Wektor2d(int y, int x): y(y), x(x) {};

    bool operator==(Wektor2d o) const {

        return x == o.x && y == o.y;

    }

    Wektor2d operator+(Wektor2d o) const {

        return {y + o.y, x + o.x};

    }

    void operator+=(Wektor2d o)  {

        y += o.y;
        x += o.x;

    }

    [[nodiscard]] bool pozaGranicami(uint wysokosc, uint szerokosc) const {

        return y < 0 || x < 0 || y >= wysokosc || x >= szerokosc;

    }

};


