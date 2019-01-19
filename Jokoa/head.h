#ifndef MAIN_H
#define MAIN_H

#include "ebentoak.h"

typedef enum { JOLASTEN, MENUA, MAILA_1, MAILA_2, MAILA_3, MAILA_4, IRABAZI, GALDU }EGOERA;

typedef struct
{
	POSIZIOA pos;
	int id;

}JOKO_ELEMENTUA;

typedef struct
{
	int x0;
	int x1;
	int y0;
	int y1;
}MAPA;


typedef struct
{
	POSIZIOA pos;
	ABIADURA v;
}BALAK;

#endif
