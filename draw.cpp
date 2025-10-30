#define DRAW_BUILD
#include "draw.h"
#include "assety.h"

namespace draw
{
    unsigned long rysujRamke(int x, int y, int szer, int wys, bool czyRamka, unsigned char znak)
    {
        // Sprawdzenie poprawności wymiarów
        if(!check::czyRamkaSieMiesci(x*dane::MNOZNIK, y, szer, wys))
        {
            return 0x00000002;
        }

        dane::Wymiary wymiary = {};
        wymiary.x = x;
        wymiary.y = y;
        wymiary.xkoniec = x + szer - 1;
        wymiary.ykoniec = y + wys - 1;

        if(!czyRamka)
        {
            util::rysujRamke(&wymiary, znak);
        }

        return 0;
    }

    namespace check
    {
        bool czyRamkaSieMiesci(int x, int y, int szer, int wys)
        {
            if(x < 0 || y < 0 || x + szer > MAXCHARX || y + wys > MAXCHARY)
            {
                return false;
            }
            return true;
        }
    }

    namespace util
    {
        void rysujRamke(dane::Wymiary* struktura, unsigned char znak)
        {
            for(int i = struktura->y; i <= struktura->ykoniec; i++)
            {
                for(int j = struktura->x; j <= struktura->xkoniec; j++)
                {
                    if(i == struktura->y || i == struktura->ykoniec || j == struktura->x || j == struktura->xkoniec)
                    {
                        util::gotoxy(j*dane::MNOZNIK, i);
                        for(int k = 0; k < dane::MNOZNIK; k++)
                        {
                            std::cout << znak;
                        }
                    }
                }
            }
        }

        void gotoxy(int x, int y)
        {
            HANDLE hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
            SetConsoleCursorPosition(hKonsola, pos);
        }
    }
}
