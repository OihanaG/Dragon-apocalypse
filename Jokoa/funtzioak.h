#pragma once
#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#include "head.h"


EGOERA maila1(void);
EGOERA maila2(void);
EGOERA maila3(void);
EGOERA maila4(void);
POSIZIOA tiroaPosizioa(POSIZIOA jokalariapos, int posizioa);
ABIADURA tiroEgin(POSIZIOA pertsonaiaPos, POSIZIOA helburuaPos, int vastirotu);
POSIZIOA etsaiUrdinaetaBerdeaMugitu(POSIZIOA etsaiaPos, POSIZIOA jokalariaPos, MAPA pareta[], int maila);
POSIZIOA etsaiGorriaMugitu(POSIZIOA etsaiaPos);
int etsaiGorriaIrudia(POSIZIOA etsaiaPos);

#endif // !FUNTZIOAK_H
