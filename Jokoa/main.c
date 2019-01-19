#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <windows.h>
#include <stdio.h>
#include "funtzioak.h"
#include "head.h"

#define MENUA_ ".\\img\\menua.bmp"
#define ARGIBIDEA ".\\img\\argibidea.bmp"
#define MAILAK ".\\img\\maila.bmp"
#define MAILA1 ".\\img\\maila1.bmp"
#define MAILA2 ".\\img\\maila2.bmp"
#define MAILA3 ".\\img\\maila3.bmp"
#define MAILA4 ".\\img\\maila4.bmp"
#define SARRERA ".\\img\\sarrera.bmp"
#define AMAIERA ".\\img\\amaiera.bmp"
#define GALDUPANT ".\\img\\galdu.bmp"
#define IRABAZIPANT ".\\img\\jokoapasa.bmp"

int main(int argc, char * str[])
{
	int tecla = 0, irten = 0, pantaila=0, x;
	EGOERA egoera;
	POSIZIOA saguaPos;
	JOKO_ELEMENTUA irudia;
	MAPA botoia[8];

	egoera = MENUA;

	if (sgHasieratu() == -1)
	{
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 0;
	}
	textuaGaitu();
	botoiaKoordenatuak(botoia);
	irudia.id = irudiaKargatu(MENUA_);
	while (!irten)
	{
		pantailaGarbitu();
		tecla = ebentuaJasoGertatuBada();
		switch (egoera)
		{
		case MENUA:
			switch (pantaila)
			{
			case 0://Pantaila hau hasierakoa da, hau da, jokoa hasi, maila hautatu eta argibidea aukeratzeko pantaila
				irudia.id = irudiaKargatu(MENUA_);
				irudiakMarraztu();
				pantailaBerriztu();
				while (pantaila == 0 && irten == 0)
				{
					tecla = ebentuaJasoGertatuBada();
					saguaPos = saguarenPosizioa();
					//Atea, jokotik ateratzeko balio du
					if (saguaPos.x > botoia[0].x0 && saguaPos.x<botoia[0].x1 && saguaPos.y>botoia[0].y0 && saguaPos.y < botoia[0].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
						sgItxi();
						irten = 1;
					}
					//Hasteko botoia
					if (saguaPos.x > botoia[1].x0 && saguaPos.x<botoia[1].x1 && saguaPos.y>botoia[1].y0 && saguaPos.y < botoia[1].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
						pantaila = 1;
					}
					if (saguaPos.x > botoia[2].x0 && saguaPos.x<botoia[2].x1 && saguaPos.y>botoia[2].y0 && saguaPos.y < botoia[2].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
						pantaila = 2;
					}
					//Argibidea erakusten duen botoia
					if (saguaPos.x > botoia[3].x0 && saguaPos.x<botoia[3].x1 && saguaPos.y>botoia[3].y0 && saguaPos.y < botoia[3].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
						pantaila = 3;
					}
				}
				break;
			case 1://"Jokoa hasi" botoiari emandakoan agertuko dena
				irudiaKendu(irudia.id);
				irudia.id = irudiaKargatu(SARRERA);//Istorioa azaltzen duen pantaila
				irudiakMarraztu();
				pantailaBerriztu();
				while (tecla != TECLA_RETURN)
				{
					tecla = ebentuaJasoGertatuBada();
				}
				irudiaKendu(irudia.id);
				pantaila = 0;
				pantailaGarbitu();
				egoera = MAILA_1;
				break;
			case 2://"Maila hautatu" botoiari ematean agertzen den beste pantaila
				irudiaKendu(irudia.id);
				irudia.id = irudiaKargatu(MAILAK);

				saguaPos = saguarenPosizioa();
				//1. mailara eramaten duen botoia
				if (saguaPos.x > botoia[4].x0 && saguaPos.x<botoia[4].x1 && saguaPos.y>botoia[4].y0 && saguaPos.y < botoia[4].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
					irudiaKendu(irudia.id);
					egoera = MAILA_1;
				}
				//3. mailara eramaten duen botoia
				if (saguaPos.x > botoia[5].x0 && saguaPos.x<botoia[5].x1 && saguaPos.y>botoia[5].y0 && saguaPos.y < botoia[5].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
					irudiaKendu(irudia.id);
					egoera = MAILA_3;
				}
				//4. mailara eramaten duen botoia
				if (saguaPos.x > botoia[6].x0 && saguaPos.x<botoia[6].x1 && saguaPos.y>botoia[6].y0 && saguaPos.y < botoia[6].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
					irudiaKendu(irudia.id);
					egoera = MAILA_4;
				}
				//2. mailara eramaten duen botoia
				if (saguaPos.x > botoia[7].x0 && saguaPos.x<botoia[7].x1  &&  saguaPos.y> botoia[7].y0 && saguaPos.y < botoia[7].y1 && tecla == SAGU_BOTOIA_EZKERRA) {
					irudiaKendu(irudia.id);
					egoera = MAILA_2;
				}
				//Berriro hasierako menura joateko aukera
				if (tecla == TECLA_RETURN)
				{
					irudiaKendu(irudia.id);
					pantaila = 0;
				}
				break;
			case 3://Argibideak agertzen diren pantaila
				irudiaKendu(irudia.id);
				irudia.id = irudiaKargatu(ARGIBIDEA);
				if (tecla == TECLA_RETURN) {
					irudiaKendu(irudia.id);
					irudia.id = irudiaKargatu(MENUA_);
					pantaila = 0;
				}
				break;
			default:
				break;
			}
			break;
		case MAILA_1://1.mailara joatean agertzen den hasierako titulua eta mailan jolasten hastea ahalbidetzen du
			pantailaGarbitu();
			irudia.id = irudiaKargatu(MAILA1);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(400);
			irudiaKendu(irudia.id);
			egoera = maila1();
			break;
		case MAILA_2://2.mailara joatean agertzen den hasierako titulua eta mailan jolasten hastea ahalbidetzen du
			pantailaGarbitu();
			irudia.id = irudiaKargatu(MAILA2);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(400);
			irudiaKendu(irudia.id);
			egoera = maila2();
			break;
		case MAILA_3://3.mailara joatean agertzen den hasierako titulua eta mailan jolasten hastea ahalbidetzen du
			pantailaGarbitu();
			irudia.id = irudiaKargatu(MAILA3);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(400);
			irudiaKendu(irudia.id);
			egoera = maila3();
			break;
		case MAILA_4://4.mailara joatean agertzen den hasierako titulua eta mailan jolasten hastea ahalbidetzen du
			pantailaGarbitu();
			irudia.id = irudiaKargatu(MAILA4);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(400);
			irudiaKendu(irudia.id);
			egoera = maila4();
			break;
		case IRABAZI://Irabaztean agertzen den pantaila
			pantailaGarbitu();
			irudia.id = irudiaKargatu(IRABAZIPANT);
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(1500);
			egoera = MENUA;
			pantaila = 0;
			break;
		case GALDU://Galtzean agertzen den pantaila, hemendik irtetzeko return-eri eman behar zaio
			pantailaGarbitu();
			irudia.id = irudiaKargatu(GALDUPANT);
			irudiakMarraztu();
			pantailaBerriztu();
			while (tecla != TECLA_RETURN)
			{
				tecla = ebentuaJasoGertatuBada();
			}
			egoera = MENUA;
			pantaila = 0;
			break;
		default:
			break;
		}
		irudiakMarraztu(irudia.id, 0, 0);
		pantailaBerriztu();
	}
	sgItxi();
	return 0;
}