#include "ebentoak.h"
#include "funtzioak.h"

POSIZIOA etsaiUrdinaetaBerdeaMugitu(POSIZIOA etsaiaPos, POSIZIOA jokalariaPos, MAPA pareta[], int maila)
{
	int j;
	ABIADURA vetsaia;
	vetsaia = tiroEgin(etsaiaPos, jokalariaPos, 45);

	for (j = 1; j <= 32; j++) {
		if ((etsaiaPos.x + 24 <= pareta[j].x0 && etsaiaPos.x + 28 >= pareta[j].x0 && etsaiaPos.y <= pareta[j].y1 && etsaiaPos.y + 25 >= pareta[j].y0) || (etsaiaPos.x - 2 <= pareta[j].x1 && etsaiaPos.x + 5 >= pareta[j].x1 && etsaiaPos.y <= pareta[j].y1 && etsaiaPos.y + 25 >= pareta[j].y0))
		{
			if (jokalariaPos.y >= etsaiaPos.y)
			{
				vetsaia.dx = 0;
				vetsaia.dy = 0.2;
			}
			else
			{
				vetsaia.dx = 0;
				vetsaia.dy = -0.2;
			}
		}

		if ((etsaiaPos.y <= pareta[j].y1 && etsaiaPos.y + 10 >= pareta[j].y1 && etsaiaPos.x <= pareta[j].x1  && etsaiaPos.x + 25 >= pareta[j].x0) || (etsaiaPos.y + 20 <= pareta[j].y0 && etsaiaPos.y + 26 >= pareta[j].y0 && etsaiaPos.x + 15 <= pareta[j].x1  && etsaiaPos.x + 25 >= pareta[j].x0))
		{
				if (jokalariaPos.x >= etsaiaPos.x)
				{
					vetsaia.dx = 0.2;
					vetsaia.dy = 0;
				}
				else
				{
					vetsaia.dx = -0.2;
					vetsaia.dy = 0;
				}
		}
		if (maila == 1)
		{
			if(j == 27)j=33;
		}
		if (maila == 2)
		{
			if (j == 10)j = 27;
		}
	}
	etsaiaPos.x += vetsaia.dx;
	etsaiaPos.y += vetsaia.dy;

	return etsaiaPos;
}

//Etsai gorriak nora begiratzen duen kalkulatzen du
int etsaiGorriaIrudia(POSIZIOA etsaiaPos)
{
	int irudia;

	if (etsaiaPos.x < 405 && etsaiaPos.y == 30)
	{
		irudia = 6;
	}
	if (etsaiaPos.x >= 405 && etsaiaPos.y < 285)
	{
		irudia = 7;
	}
	if (etsaiaPos.y == 285 && etsaiaPos.x > 60)
	{
		irudia = 8;
	}
	if (etsaiaPos.x == 60 && etsaiaPos.y > 30)
	{
		irudia = 9;
	}
	
	return irudia;
}

POSIZIOA etsaiGorriaMugitu(POSIZIOA etsaiaPos)
{
	ABIADURA vetsaia;
	
	if (etsaiaPos.x < 405 && etsaiaPos.y == 30)
	{
		vetsaia.dx = 1;
		vetsaia.dy = 0;
	}
	if (etsaiaPos.x == 405 && etsaiaPos.y < 285)
	{
		vetsaia.dx = 0;
		vetsaia.dy = 1;
	}
	if (etsaiaPos.y == 285 && etsaiaPos.x > 60)
	{
		vetsaia.dx = -1;
		vetsaia.dy = 0;
	}
	if (etsaiaPos.x == 60 && etsaiaPos.y > 30)
	{
		vetsaia.dx = 0;
		vetsaia.dy = -1;
	}

	etsaiaPos.x += vetsaia.dx;
	etsaiaPos.y += vetsaia.dy;
	
	return etsaiaPos;
}