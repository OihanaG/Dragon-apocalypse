#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include "funtzioak.h"

#include <stdio.h>
#include <windows.h>

#define JOKALARIAGORA ".\\img\\MG.bmp"
#define JOKALARIABEHERA ".\\img\\MB.bmp"
#define JOKALARIAEZKERRERA ".\\img\\MEzk.bmp"
#define JOKALARIAESKUMARA ".\\img\\MEsk.bmp"

#define ETSAIA1 ".\\img\\duB.bmp"
#define ETSAIA2 ".\\img\\dbB.bmp"
#define ETSAIA3Ezk ".\\img\\dgEzk.bmp"
#define ETSAIA3Esk ".\\img\\dgEsk.bmp"
#define ETSAIA3G ".\\img\\dgG.bmp"
#define ETSAIA3B ".\\img\\dgB.bmp"
#define ETSAIA4Ezk ".\\img\\finalboss_Ezk.bmp"
#define ETSAIA4Esk ".\\img\\finalboss_Esk.bmp"

#define MAPA1 ".\\img\\mapa1.bmp"
#define MAPA2 ".\\img\\mapa2.bmp"
#define MAPA34 ".\\img\\mapa3.bmp"

#define MAIN_THEME ".\\sound\\main_theme.wav"

#define BALEN_LISTA 20

/*______________________________________________1 MAILA_______________________________________________________________________________________________________*/

EGOERA maila1(void)
{
	int tiroa = 0, jokalariapos=4, vpertsonaia=5, balakendu=0, rbala = 5, jokalariabizitza = 125;
	int tecla, i, j, k;
	int temporizador = 1, sua = 0, suakendu = 0, etsaiabizitza=75;
	EGOERA egoera=JOLASTEN;
	POSIZIOA sagua;
	BALAK bala[BALEN_LISTA], suadragoia[BALEN_LISTA];
	JOKO_ELEMENTUA jokalaria, etsaia, mapa;
	MAPA kaja[50];

	audioInit();
	loadTheMusic(MAIN_THEME);
	playMusic();

	mapakoKoordenatuak(kaja);

	mapa.id = irudiaKargatu(MAPA1);
	mapa.pos.x = 0;
	mapa.pos.y = 0;

	jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
	jokalaria.pos.x = 20;
	jokalaria.pos.y = 195;

	etsaia.id = irudiaKargatu(ETSAIA1);
	etsaia.pos.x = 500;
	etsaia.pos.y = 250;

	do
	{
		Sleep(2);
		pantailaGarbitu();
		//Irudi denak marraztu
		irudiaMugitu(mapa.id, mapa.pos.x, mapa.pos.y);
		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiakMarraztu();
		
		//Tekla bakoitzak egiten duen funtzioa
		tecla = ebentuaJasoGertatuBada();
		switch (tecla)
		{
		case SAGU_BOTOIA_EZKERRA:
			sagua = saguarenPosizioa();
			bala[tiroa].pos = tiroaPosizioa(jokalaria.pos, jokalariapos);
			bala[tiroa].v = tiroEgin(jokalaria.pos, sagua, 5);
			tiroa++;
			break;
		case TECLA_ESCAPE: egoera = MENUA;//Jokoa martxan dagoela menura joateko aukera
			break;
		case TECLA_a:
			jokalaria.pos.x -= vpertsonaia;
			if (jokalariapos != 1)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAEZKERRERA);
				jokalariapos = 1;
			}
			for (j = 1; j <= 27; j++) {
				if (jokalaria.pos.x + 10 <= kaja[j].x1 && jokalaria.pos.x + 25 >= kaja[j].x1 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x += vpertsonaia;
				}
			}
			break;
		case TECLA_d:
			jokalaria.pos.x += vpertsonaia;
			if (jokalariapos != 2)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAESKUMARA);
				jokalariapos = 2;
			}
			for (j = 1; j <= 27; j++) {
				if (jokalaria.pos.x + 45 == kaja[j].x0 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x -= vpertsonaia;
				}
			}
			break;
		case TECLA_w:
			jokalaria.pos.y -= vpertsonaia;
			if (jokalariapos != 3)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAGORA);
				jokalariapos = 3;
			}
			for (j = 1; j <= 27; j++) {
				if (jokalaria.pos.y + 5 <= kaja[j].y1 && jokalaria.pos.y + 10 >= kaja[j].y1 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y += vpertsonaia;
				}
			}
			break;
		case TECLA_s:
			jokalaria.pos.y += vpertsonaia;
			if (jokalariapos != 4)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
				jokalariapos = 4;
			}
			for (j = 1; j <= 27; j++)
			{
				if (jokalaria.pos.y + 48 <= kaja[j].y0 && jokalaria.pos.y + 58 >= kaja[j].y0 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y -= vpertsonaia;
				}
			}
			break;
		default:
			break;
		}
		//Aztiaren tiroak
		if (balakendu != tiroa)
		{
			arkatzKoloreaEzarri(0, 255, 255);
			i = balakendu;
			if (tiroa == BALEN_LISTA)tiroa = 0;
			while (i != tiroa)
			{
				zirkuluaMarraztu(bala[i].pos.x, bala[i].pos.y, rbala);
				bala[i].pos.x = bala[i].pos.x + bala[i].v.dx;
				bala[i].pos.y = bala[i].pos.y + bala[i].v.dy;
				//Balak pareta ikutzen duenean, bala kentzea
				for (j = 1; j <= 27; j++) {
					if (bala[i].pos.x >= kaja[j].x0 && bala[i].pos.x <= kaja[j].x1 && bala[i].pos.y >= kaja[j].y0 && bala[i].pos.y <= kaja[j].y1) {
						balakendu++;
					}
				}
				if (bala[i].pos.x <= etsaia.pos.x + 24 && bala[i].pos.x >= etsaia.pos.x && etsaia.pos.y <= bala[i].pos.y + 24 && etsaia.pos.y >= bala[i].pos.y)
				{
					etsaiabizitza -= 5;
				}
				if (i == BALEN_LISTA - 1)
				{
					i = -1;
				}
				i++;
			}
			if (balakendu == BALEN_LISTA)balakendu = 0;
		}
		
		etsaia.pos = etsaiUrdinaetaBerdeaMugitu(etsaia.pos, jokalaria.pos, kaja, 1);
		arkatzKoloreaEzarri(255, 0, 0);

		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);
		if (temporizador == 1)
		{
				suadragoia[sua].pos = tiroaPosizioa(etsaia.pos, 5);
				suadragoia[sua].v = tiroEgin(etsaia.pos, jokalaria.pos, 7);
				sua++;
		}
		//Etsaien balen funtzionamendua
		if (suakendu != sua)
		{
			j = suakendu;
			if (sua == BALEN_LISTA)sua = 0;
			arkatzKoloreaEzarri(255, 0, 0);
			while (j != sua)
			{
				zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, 5);
				suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
				suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;

				if (suadragoia[j].pos.x <= jokalaria.pos.x + 25 && suadragoia[j].pos.x >= jokalaria.pos.x && jokalaria.pos.y  <= suadragoia[j].pos.y + 55  && jokalaria.pos.y >= suadragoia[j].pos.y)
				{
					jokalariabizitza -= 1;
				}
				for (k = 1; k <= 27; k++) {
					if ((suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) || suadragoia[j].pos.x < 0) {
						suakendu++;
					}
				}
				if (j == BALEN_LISTA - 1)
				{
					j = -1;
				}
				j++;
			}
			if (suakendu == BALEN_LISTA)suakendu = 0;
		}
		temporizador++;
		if (temporizador == 100)temporizador = 1;
		//Etsaien eta aztiaren bizitza barrak
		arkatzKoloreaEzarri(0, 200, 0);
		karratuaMarraztu(etsaia.pos.x-15, etsaia.pos.y - 8, etsaia.pos.x + etsaiabizitza-15, etsaia.pos.y - 3);
		arkatzKoloreaEzarri(0, 0, 150);
		karratuaMarraztu(512, 467, 512 + jokalariabizitza, 477);
		//Etsaiak aztia ikutzen badu, galdu egiten da
		if (etsaia.pos.x <= jokalaria.pos.x + 20 && etsaia.pos.x >= jokalaria.pos.x - 10 && etsaia.pos.y <= jokalaria.pos.y + 20 && etsaia.pos.y >= jokalaria.pos.y - 10)
		{
			egoera = GALDU;
		}
		if (jokalariabizitza <= 0)egoera = GALDU;
		if (etsaiabizitza <= 0)egoera = MAILA_2;

		pantailaBerriztu();
	} while (egoera == JOLASTEN);

	audioTerminate();
	irudiaKendu(jokalaria.id);
	irudiaKendu(etsaia.id);
	irudiaKendu(mapa.id);

	return egoera;
}

/*______________________________________________2 MAILA_______________________________________________________________________________________________________*/

EGOERA maila2(void)
{
	int tiroa = 0, jokalariapos = 4, vpertsonaia = 5, balakendu = 0, rbala = 5, jokalariabizitza = 125;
	int tecla, i, j, k;
	int temporizador = 1, sua=0, suakendu=0, etsaiabizitza[5], etsaiakbizirik[5];
	EGOERA egoera = JOLASTEN;
	POSIZIOA sagua;
	BALAK bala[BALEN_LISTA], suadragoia[BALEN_LISTA];
	JOKO_ELEMENTUA jokalaria, etsaia[5], mapa;
	MAPA kaja[50];

	audioInit();
	loadTheMusic(MAIN_THEME);
	playMusic();

	mapakoKoordenatuak(kaja);

	mapa.id = irudiaKargatu(MAPA2);
	mapa.pos.x = 0;
	mapa.pos.y = 0;

	jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
	jokalaria.pos.x = 20;
	jokalaria.pos.y = 195;
	
	for (j = 0; j < 4; j++)
	{
		etsaia[j].id = irudiaKargatu(ETSAIA2);
		etsaiakbizirik[j] == 1;
	}
	etsaia[0].pos.x = 540;
	etsaia[0].pos.y = 300;
	etsaia[1].pos.x = 480;
	etsaia[1].pos.y = 50;
	etsaia[2].pos.x = 320;
	etsaia[2].pos.y = 430;
	etsaia[3].pos.x = 300;
	etsaia[3].pos.y = 100;
	for (j = 0; j < 5; j++)
	{
		etsaiabizitza[j] = 75;
	}
	do
	{
		Sleep(2);
		pantailaGarbitu();
		//Tekla bakoitzak egiten duen funtzioa
		tecla = ebentuaJasoGertatuBada();
		switch (tecla)
		{
		case SAGU_BOTOIA_EZKERRA:
			sagua = saguarenPosizioa();
			bala[tiroa].pos = tiroaPosizioa(jokalaria.pos, jokalariapos);
			bala[tiroa].v = tiroEgin(jokalaria.pos, sagua, 5);
			tiroa++;
			break;
		case TECLA_ESCAPE: egoera = MENUA;
			break;
		case TECLA_a:
			jokalaria.pos.x -= vpertsonaia;
			if (jokalariapos != 1)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAEZKERRERA);
				jokalariapos = 1;
			}
			for (j = 1; j <= 32; j++)
			{
				if (jokalaria.pos.x + 10 <= kaja[j].x1 && jokalaria.pos.x + 25 >= kaja[j].x1 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x += vpertsonaia;
				}
				if (j == 10)j = 27;
			}
			break;
		case TECLA_d:
			jokalaria.pos.x += vpertsonaia;
			if (jokalariapos != 2)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAESKUMARA);
				jokalariapos = 2;
			}
			for (j = 1; j <= 32; j++)
			{
				if (jokalaria.pos.x + 45 == kaja[j].x0 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x -= vpertsonaia;
				}
				if (j == 10)j = 27;
			}
			break;
		case TECLA_w:
			jokalaria.pos.y -= vpertsonaia;
			if (jokalariapos != 3)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAGORA);
				jokalariapos = 3;
			}
			for (j = 1; j <= 32; j++)
			{
				if (jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 10 >= kaja[j].y1 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y += vpertsonaia;
				}
				if (j == 10)j = 27;
			}
			break;
		case TECLA_s:
			jokalaria.pos.y += vpertsonaia;
			if (jokalariapos != 4)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
				jokalariapos = 4;
			}
			for (j = 1; j <= 32; j++)
			{
				if (jokalaria.pos.y + 48 <= kaja[j].y0 && jokalaria.pos.y + 58 >= kaja[j].y0 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y -= vpertsonaia;
				}
				if (j == 10)j = 27;
			}
			break;
		default:
			break;
		}
		//Irudi denak marraztu
		irudiaMugitu(mapa.id, mapa.pos.x, mapa.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		for (k = 0; k < 4; k++)
		{
			if (etsaiabizitza[k] > 0)
			{
				etsaia[k].pos = etsaiUrdinaetaBerdeaMugitu(etsaia[k].pos, jokalaria.pos, kaja, 2);
				irudiaMugitu(etsaia[k].id, etsaia[k].pos.x, etsaia[k].pos.y);
			}
			else if (etsaiakbizirik[k])
			{
				irudiaKendu(etsaia[k].id);
				etsaiakbizirik[k] = 0;
			}
		}
		irudiakMarraztu();
		//Aztiaren tiroak
		if (balakendu != tiroa)
		{
			arkatzKoloreaEzarri(0, 255, 255);
			i = balakendu;
			if (tiroa == BALEN_LISTA)tiroa = 0;
			while (i != tiroa)
			{
				zirkuluaMarraztu(bala[i].pos.x, bala[i].pos.y, rbala);
				bala[i].pos.x = bala[i].pos.x + bala[i].v.dx;
				bala[i].pos.y = bala[i].pos.y + bala[i].v.dy;
				
				for (j = 1; j <= 32; j++)
				{
					if (bala[i].pos.x >= kaja[j].x0 && bala[i].pos.x <= kaja[j].x1 && bala[i].pos.y >= kaja[j].y0 && bala[i].pos.y <= kaja[j].y1) {
						balakendu++;
					}
					if (j == 10)j = 27;
				}

				for (k = 0; k < 4; k++)
				{
					if (bala[i].pos.x < etsaia[k].pos.x + 50 && bala[i].pos.x > etsaia[k].pos.x && etsaia[k].pos.y < bala[i].pos.y + 50 && etsaia[k].pos.y > bala[i].pos.y)
					{
						etsaiabizitza[k] -= 1;
					}
				}

				if (i == BALEN_LISTA - 1)
				{
					i = -1;
				}
				i++;
			}
			if (balakendu == BALEN_LISTA)balakendu = 0;
		}

		if (temporizador == 1)
		{
			for (k = 0; k < 4; k++)
			{
				if (etsaiabizitza[k] > 0)
				{
					suadragoia[sua].pos = tiroaPosizioa(etsaia[k].pos, 5);
					suadragoia[sua].v = tiroEgin(etsaia[k].pos, jokalaria.pos, 7);
					sua++;
				}
			}
		}
		if (suakendu != sua)
		{
			j = suakendu;
			if (sua == BALEN_LISTA)sua = 0;
			arkatzKoloreaEzarri(255, 0, 0);
			while (j != sua)
			{
				zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, 3);
				suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
				suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;
			
				for (k = 1; k <= 32; k++) {
					if (suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) {
						suakendu++;
					}
					if (k == 10)k = 27;
				}

				if (suadragoia[j].pos.x <= jokalaria.pos.x + 25 && suadragoia[j].pos.x >= jokalaria.pos.x && jokalaria.pos.y <= suadragoia[j].pos.y + 55 && jokalaria.pos.y >= suadragoia[j].pos.y)
				{
					jokalariabizitza -= 1;
				}

				if (j == BALEN_LISTA - 1)
				{
					j = -1;
				}
				j++;
			}
			if (suakendu == BALEN_LISTA)suakendu = 0;
		}
		temporizador++;
		if (temporizador == 600)temporizador = 1;

		arkatzKoloreaEzarri(0, 200, 0);
		for (k = 0; k < 4; k++)
		{
			karratuaMarraztu(etsaia[k].pos.x - 15, etsaia[k].pos.y - 8, etsaia[k].pos.x + etsaiabizitza[k] - 15, etsaia[k].pos.y - 3);
		}
		arkatzKoloreaEzarri(0, 0, 150);
		karratuaMarraztu(512, 467, 512 + jokalariabizitza, 477);
		for (k = 0; k<4 ;k++)
		{
			if (etsaia[k].pos.x <= jokalaria.pos.x + 20 && etsaia[k].pos.x >= jokalaria.pos.x - 10 && etsaia[k].pos.y <= jokalaria.pos.y + 20 && etsaia[k].pos.y >= jokalaria.pos.y - 10)
			{
				egoera = GALDU;
			}
		}
		if (jokalariabizitza <= 0)egoera = GALDU;
		if (etsaiabizitza[0] <= 0 && etsaiabizitza[1] <= 0 && etsaiabizitza[2] <= 0 && etsaiabizitza[3] <= 0)egoera = MAILA_3;

		pantailaBerriztu();
	} while (egoera == JOLASTEN);

	audioTerminate();
	for (k = 0; k < 4; k++)
	{
		if (etsaiakbizirik[k])
		{
			irudiaKendu(etsaia[k].id);
			etsaiakbizirik[k] = 0;
		}
	}
	irudiaKendu(mapa.id);
	irudiaKendu(jokalaria.id);

	return egoera;
}

/*______________________________________________3 MAILA_______________________________________________________________________________________________________*/

EGOERA maila3(void)
{
	int tiroa = 0, jokalariapos = 4, vpertsonaia = 5, balakendu = 0, rbala = 5, jokalariabizitza = 125;
	int tecla, i, j, k;
	int temporizador = 50, sua = 0, suakendu = 0, etsaiabizitza = 175, etsaiaIrudia;
	EGOERA egoera = JOLASTEN;
	POSIZIOA sagua, helmuga;
	BALAK bala[BALEN_LISTA], suadragoia[BALEN_LISTA];
	JOKO_ELEMENTUA jokalaria, etsaia, mapa;
	MAPA kaja[50];

	audioInit();
	loadTheMusic(MAIN_THEME);
	playMusic();

	mapakoKoordenatuak(kaja);

	mapa.id = irudiaKargatu(MAPA34);
	mapa.pos.x = 0;
	mapa.pos.y = 0;

	jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
	jokalaria.pos.x = 20;
	jokalaria.pos.y = 195;

	etsaia.id = irudiaKargatu(ETSAIA3Esk);
	etsaia.pos.x = 60;
	etsaia.pos.y = 30;

	do
	{
		Sleep(2);
		pantailaGarbitu();
		//Tekla bakoitzak egiten duen funtzioa
		tecla = ebentuaJasoGertatuBada();
		switch (tecla)
		{
		case SAGU_BOTOIA_EZKERRA:
			sagua = saguarenPosizioa();
			bala[tiroa].pos = tiroaPosizioa(jokalaria.pos, jokalariapos);
			bala[tiroa].v = tiroEgin(jokalaria.pos, sagua, 5);
			tiroa++;
			break;
		case TECLA_ESCAPE: egoera = MENUA;
			break;
		case TECLA_a:
			jokalaria.pos.x -= vpertsonaia;
			if (jokalariapos != 1)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAEZKERRERA);
				jokalariapos = 1;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.x + 10 <= kaja[j].x1 && jokalaria.pos.x + 25 >= kaja[j].x1 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x += vpertsonaia;
				}
			}
			break;
		case TECLA_d:
			jokalaria.pos.x += vpertsonaia;
			if (jokalariapos != 2)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAESKUMARA);
				jokalariapos = 2;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.x + 45 == kaja[j].x0 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x -= vpertsonaia;
				}
			}
			break;
		case TECLA_w:
			jokalaria.pos.y -= vpertsonaia;
			if (jokalariapos != 3)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAGORA);
				jokalariapos = 3;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 10 >= kaja[j].y1 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y += vpertsonaia;
				}
			}
			break;
		case TECLA_s:
			jokalaria.pos.y += vpertsonaia;
			if (jokalariapos != 4)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
				jokalariapos = 4;
			}
			for (j = 0; j <= 10; j++)
			{
				if (jokalaria.pos.y + 48 <= kaja[j].y0 && jokalaria.pos.y + 58 >= kaja[j].y0 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y -= vpertsonaia;
				}
			}
			break;
		default:
			break;
		}
		//Irudi denak marraztu
		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiakMarraztu();
		//Aztiaren tiroak
		if (balakendu != tiroa)
		{
			arkatzKoloreaEzarri(0, 255, 255);
			i = balakendu;
			if (tiroa == BALEN_LISTA)tiroa = 0;
			while (i != tiroa)
			{
				zirkuluaMarraztu(bala[i].pos.x, bala[i].pos.y, rbala);
				bala[i].pos.x = bala[i].pos.x + bala[i].v.dx;
				bala[i].pos.y = bala[i].pos.y + bala[i].v.dy;
				for (j = 0; j <= 10; j++) {
					if (bala[i].pos.x >= kaja[j].x0 && bala[i].pos.x <= kaja[j].x1 && bala[i].pos.y >= kaja[j].y0 && bala[i].pos.y <= kaja[j].y1) {
						balakendu++;
					}
				}
				if (bala[i].pos.x <= etsaia.pos.x + 180 && bala[i].pos.x >= etsaia.pos.x + 80 && etsaia.pos.y <= bala[i].pos.y + 180 && etsaia.pos.y >= bala[i].pos.y + 80)
				{
					etsaiabizitza -= 1;
				}
				if (i == BALEN_LISTA - 1)
				{
					i = -1;
				}
				i++;
			}
			if (balakendu == BALEN_LISTA)balakendu = 0;
		}
		etsaia.pos = etsaiGorriaMugitu(etsaia.pos);
		etsaiaIrudia = etsaiGorriaIrudia(etsaia.pos);

		switch (etsaiaIrudia)
		{
		case 6:
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA3Esk);
			break;
		case 7:
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA3B);
			break;
		case 8:
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA3Ezk);
			break;
		case 9:
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA3G);
			break;
		default:
			break;
		}
		arkatzKoloreaEzarri(255, 0, 0);
		
		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);
		
		if (temporizador == 1)
		{
			for (k = -2; k < 2; k++)
			{
				helmuga.x = jokalaria.pos.x + k * 10;
				helmuga.y = jokalaria.pos.y - k * 20;
				suadragoia[sua].pos = tiroaPosizioa(etsaia.pos, etsaiaIrudia);
				suadragoia[sua].v = tiroEgin(suadragoia[sua].pos, helmuga, 9);
				sua++;
			}
		}
		if (suakendu != sua)
		{
			j = suakendu;
			if (sua == BALEN_LISTA)sua = 0;
			arkatzKoloreaEzarri(255, 0, 0);
			while (j != sua)
			{
				zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, 3);
				suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
				suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;

				for (k = 0; k <= 10; k++) {
					if (suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) {
						suakendu++;
					}
				}
				if (suadragoia[j].pos.x <= jokalaria.pos.x + 25 && suadragoia[j].pos.x >= jokalaria.pos.x && jokalaria.pos.y <= suadragoia[j].pos.y + 55 && jokalaria.pos.y >= suadragoia[j].pos.y)
				{
					jokalariabizitza -= 1;
				}
				if (j == BALEN_LISTA - 1)
				{
					j = -1;
				}
				j++;
			}
			if (suakendu == BALEN_LISTA)suakendu = 0;
		}
		temporizador++;
		if (temporizador == 200)temporizador = 1;

		arkatzKoloreaEzarri(0, 200, 0);
		karratuaMarraztu(etsaia.pos.x , etsaia.pos.y+20 , etsaia.pos.x + etsaiabizitza, etsaia.pos.y + 25);
		arkatzKoloreaEzarri(0, 0, 150);
		karratuaMarraztu(512, 467, 512 + jokalariabizitza, 477);

		if (etsaia.pos.x <= jokalaria.pos.x + 20 && etsaia.pos.x >= jokalaria.pos.x - 10 && etsaia.pos.y <= jokalaria.pos.y + 20 && etsaia.pos.y >= jokalaria.pos.y - 10)
		{
			egoera = GALDU;
		}
		if (jokalariabizitza <= 0)egoera = GALDU;
		if (etsaiabizitza <= 0)egoera = MAILA_4;

		pantailaBerriztu();
	} while (egoera == JOLASTEN);

	audioTerminate();
	irudiaKendu(jokalaria.id);
	irudiaKendu(etsaia.id);
	irudiaKendu(mapa.id);

	return egoera;
}

/*______________________________________________4 MAILA_______________________________________________________________________________________________________*/

EGOERA maila4(void)
{
	int tiroa = 0, jokalariapos = 4, vpertsonaia = 5, balakendu = 0, rbala = 5, jokalariabizitza = 125;
	int tecla, i, j, k;
	int temporizador = 1, sua = 0, suakendu = 0, etsaiabizitza = 300, etsaiaIrudia, dx = 1, dy = 1;
	EGOERA egoera = JOLASTEN;
	POSIZIOA sagua, zirkulua;
	BALAK bala[BALEN_LISTA], suadragoia[BALEN_LISTA];
	JOKO_ELEMENTUA jokalaria, etsaia, mapa;
	MAPA kaja[50];

	audioInit();
	loadTheMusic(MAIN_THEME);
	playMusic();

	mapakoKoordenatuak(kaja);

	mapa.id = irudiaKargatu(MAPA34);
	mapa.pos.x = 0;
	mapa.pos.y = 0;

	jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
	jokalaria.pos.x = 20;
	jokalaria.pos.y = 195;

	etsaia.id = irudiaKargatu(ETSAIA4Ezk);
	etsaia.pos.x = 220;
	etsaia.pos.y = 150;

	zirkulua.x = 30;
	zirkulua.y = 240;

	do
	{
		Sleep(2);
		pantailaGarbitu();
		//Tekla bakoitzak egiten duen funtzioa
		tecla = ebentuaJasoGertatuBada();
		switch (tecla)
		{
		case SAGU_BOTOIA_EZKERRA:
			sagua = saguarenPosizioa();
			bala[tiroa].pos = tiroaPosizioa(jokalaria.pos, jokalariapos);
			bala[tiroa].v = tiroEgin(jokalaria.pos, sagua, 5);
			tiroa++;
			break;
		case TECLA_ESCAPE: egoera = MENUA;
			break;
		case TECLA_a:
			jokalaria.pos.x -= vpertsonaia;
			if (jokalariapos != 1)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAEZKERRERA);
				jokalariapos = 1;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.x + 10 <= kaja[j].x1 && jokalaria.pos.x + 25 >= kaja[j].x1 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x += vpertsonaia;
				}
			}
			break;
		case TECLA_d:
			jokalaria.pos.x += vpertsonaia;
			if (jokalariapos != 2)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAESKUMARA);
				jokalariapos = 2;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.x + 45 == kaja[j].x0 && jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 55 >= kaja[j].y0)
				{
					jokalaria.pos.x -= vpertsonaia;
				}
			}
			break;
		case TECLA_w:
			jokalaria.pos.y -= vpertsonaia;
			if (jokalariapos != 3)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIAGORA);
				jokalariapos = 3;
			}
			for (j = 0; j <= 10; j++) {
				if (jokalaria.pos.y <= kaja[j].y1 && jokalaria.pos.y + 10 >= kaja[j].y1 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y += vpertsonaia;
				}
			}
			break;
		case TECLA_s:
			jokalaria.pos.y += vpertsonaia;
			if (jokalariapos != 4)
			{
				irudiaKendu(jokalaria.id);
				jokalaria.id = irudiaKargatu(JOKALARIABEHERA);
				jokalariapos = 4;
			}
			for (j = 0; j <= 10; j++)
			{
				if (jokalaria.pos.y + 48 <= kaja[j].y0 && jokalaria.pos.y + 58 >= kaja[j].y0 && jokalaria.pos.x + 15 <= kaja[j].x1  && jokalaria.pos.x + 40 >= kaja[j].x0)
				{
					jokalaria.pos.y -= vpertsonaia;
				}
			}
			break;
		default:
			break;
		}

		if (jokalaria.pos.x < 320)
		{
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA4Ezk);
			etsaiaIrudia = 11;
		}
		else
		{
			irudiaKendu(etsaia.id);
			etsaia.id = irudiaKargatu(ETSAIA4Esk);
			etsaiaIrudia = 10;
		}
		//Irudi denak marraztu
		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiakMarraztu();
		//Aztiaren tiroak
		if (balakendu != tiroa)
		{
			arkatzKoloreaEzarri(0, 255, 255);
			i = balakendu;
			if (tiroa == BALEN_LISTA)tiroa = 0;
			while (i != tiroa)
			{
				zirkuluaMarraztu(bala[i].pos.x, bala[i].pos.y, rbala);
				bala[i].pos.x = bala[i].pos.x + bala[i].v.dx;
				bala[i].pos.y = bala[i].pos.y + bala[i].v.dy;
				if (bala[i].pos.x > 640 || bala[i].pos.x < 0 || bala[i].pos.y < 0 || bala[i].pos.y > 480)
				{
					balakendu++;
				}
				if (bala[i].pos.x <= etsaia.pos.x + 180 && bala[i].pos.x >= etsaia.pos.x + 45 && etsaia.pos.y <= bala[i].pos.y + 180 && etsaia.pos.y >= bala[i].pos.y + 45)
				{
					etsaiabizitza -= 1;
				}
				if (i == BALEN_LISTA - 1)
				{
					i = -1;
				}
				i++;
			}
			if (balakendu == BALEN_LISTA)balakendu = 0;
		}

		arkatzKoloreaEzarri(255, 0, 0);
		irudiaMugitu(etsaia.id, etsaia.pos.x, etsaia.pos.y);

		if (etsaiabizitza > 250)
		{
			if (temporizador == 1)
			{
				suadragoia[sua].pos = tiroaPosizioa(etsaia.pos, etsaiaIrudia);
				suadragoia[sua].v = tiroEgin(suadragoia[sua].pos, jokalaria.pos, 5);
				sua++;
			}

			if (suakendu != sua)
			{
				j = suakendu;
				if (sua == BALEN_LISTA)sua = 0;
				arkatzKoloreaEzarri(255, 0, 0);
				while (j != sua)
				{
					zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, 5);
					suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
					suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;

					if (suadragoia[j].pos.x <= jokalaria.pos.x + 25 && suadragoia[j].pos.x >= jokalaria.pos.x && jokalaria.pos.y <= suadragoia[j].pos.y + 55 && jokalaria.pos.y >= suadragoia[j].pos.y)
					{
						jokalariabizitza -= 5;
					}

					for (k = 0; k <= 10; k++) {
						if (suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) {
							suakendu++;
						}
					}
					if (j == BALEN_LISTA - 1)
					{
						j = -1;
					}
					j++;
				}
				if (suakendu == BALEN_LISTA)suakendu = 0;
			}
			temporizador++;
			if (temporizador == 200)temporizador = 1;
		}
		if (etsaiabizitza >= 150 && etsaiabizitza <= 250)
		{
			if (temporizador == 1)
			{
				suadragoia[sua].pos = tiroaPosizioa(etsaia.pos, etsaiaIrudia);
				suadragoia[sua].v = tiroEgin(suadragoia[sua].pos, zirkulua, 4);
				zirkulua.x = zirkulua.x + dx * 100;
				zirkulua.y = zirkulua.y + dy * 80;
				if (zirkulua.x > 670)
				{
					dx = -1;
				}
				if (zirkulua.x < -40)
				{
					dx = 1;
				}
				if (zirkulua.y < -10)
				{
					dy = 1;
				}
				if (zirkulua.y > 500)
				{
					dy = -1;
				}
				sua++;
			}

			j = suakendu;
			if (sua == BALEN_LISTA)sua = 0;
			while (j != sua)
			{
				arkatzKoloreaEzarri(255, 0, 0);
				zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, rbala);
				suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
				suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;

				for (k = 0; k <= 10; k++) {
					if (suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) {
						suakendu++;
					}
				}
				if (j == BALEN_LISTA - 1)
				{
					j = -1;
				}
				j++;
			}
			if (suakendu == BALEN_LISTA)suakendu = 0;
			temporizador++;
			if (temporizador >= 100)temporizador = 1;
		}
		else if (etsaiabizitza <= 150)
		{
			if (temporizador == 1)
			{
				suadragoia[sua].pos = tiroaPosizioa(etsaia.pos, etsaiaIrudia);
				suadragoia[sua].v = tiroEgin(suadragoia[sua].pos, jokalaria.pos, 5);
				sua++;
			}

			if (suakendu != sua)
			{
				j = suakendu;
				if (sua == BALEN_LISTA)sua = 0;
				arkatzKoloreaEzarri(255, 0, 0);
				while (j != sua)
				{
					zirkuluaMarraztu(suadragoia[j].pos.x, suadragoia[j].pos.y, 5);
					suadragoia[j].pos.x = suadragoia[j].pos.x + suadragoia[j].v.dx;
					suadragoia[j].pos.y = suadragoia[j].pos.y + suadragoia[j].v.dy;

					if (suadragoia[j].pos.x <= jokalaria.pos.x + 30 && suadragoia[j].pos.x >= jokalaria.pos.x && jokalaria.pos.y <= suadragoia[j].pos.y + 55 && jokalaria.pos.y >= suadragoia[j].pos.y)
					{
						jokalariabizitza -= 5;
					}

					for (k = 0; k <= 10; k++) {
						if (suadragoia[j].pos.x >= kaja[k].x0 && suadragoia[j].pos.x <= kaja[k].x1 && suadragoia[j].pos.y >= kaja[k].y0 && suadragoia[j].pos.y <= kaja[k].y1) {
							suakendu++;
						}
					}
					if (j == BALEN_LISTA - 1)
					{
						j = -1;
					}
					j++;
				}
				if (suakendu == BALEN_LISTA)suakendu = 0;
			}
			temporizador++;
			if (temporizador >= 100)temporizador = 1;
		}
		arkatzKoloreaEzarri(0, 200, 0);
		karratuaMarraztu(etsaia.pos.x - 40, etsaia.pos.y + 130, etsaia.pos.x + etsaiabizitza - 40, etsaia.pos.y +133);
		arkatzKoloreaEzarri(0, 0, 150);
		karratuaMarraztu(512, 467, 512 + jokalariabizitza, 477);

		if (etsaia.pos.x <= jokalaria.pos.x + 20 && etsaia.pos.x >= jokalaria.pos.x - 10 && etsaia.pos.y <= jokalaria.pos.y + 20 && etsaia.pos.y >= jokalaria.pos.y - 10)
		{
			egoera = GALDU;
		}
		if (jokalariabizitza <= 0)egoera = GALDU;
		if (etsaiabizitza <= 0)egoera = IRABAZI;

		pantailaBerriztu();
	} while (egoera == JOLASTEN);

	audioTerminate();
	irudiaKendu(mapa.id);
	irudiaKendu(jokalaria.id);
	irudiaKendu(etsaia.id);

	return egoera;
}