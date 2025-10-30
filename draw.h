#ifndef __cplusplus
    #error Ta biblioteka wymaga C++
#endif

#ifdef DRAW_BUILD
    #define DRAWAPI __declspec(dllexport)
#else
    #define DRAWAPI __declspec(dllimport)
#endif

namespace draw
{
    namespace dane
    {
        struct Wymiary
        {
            int x;
            int y;
            int xkoniec;
            int ykoniec;
        };
        const unsigned int MNOZNIK = 2;
    }

    namespace util
    {
        DRAWAPI void gotoxy(int x, int y);
        DRAWAPI void rysujRamke(dane::Wymiary* struktura, unsigned char znak);
    }

    namespace check
    {
        DRAWAPI bool czyRamkaSieMiesci(int x, int y, int szer, int wys);
    }

    DRAWAPI unsigned long rysujRamke(int x, int y, int szer, int wys, bool czyRamka, unsigned char znak);
}
