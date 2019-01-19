#include "ebentoak.h"

ABIADURA tiroEgin(POSIZIOA pertsonaiaPos, POSIZIOA helburuaPos, int vastirotu)
{
	int h;
	POSIZIOA kateto;
	ABIADURA aux;

	aux.dx = 1;
	aux.dy = 1;

	kateto.x = (helburuaPos.x - pertsonaiaPos.x);
	kateto.y = (helburuaPos.y - pertsonaiaPos.y);

	h = sqrt(kateto.x*kateto.x + kateto.y*kateto.y) / 10;

	aux.dx = (kateto.x / h) / vastirotu;
	aux.dy = (kateto.y / h) / vastirotu;


	return aux;
}
//Hemen tiroaren hasierako posizioa kalkulatzen da, aztiaren kasuan beti bere baritatik hastea eta dragoien kasuan beraien ahotik
POSIZIOA tiroaPosizioa(POSIZIOA jokalariapos, int posizioa)
{
	POSIZIOA tiropos;
	switch (posizioa)
	{
	case 1:
		tiropos.x = jokalariapos.x + 10;
		tiropos.y = jokalariapos.y + 15;
		break;
	case 2:
		tiropos.x = jokalariapos.x + 43;
		tiropos.y = jokalariapos.y + 13;
		break;
	case 3:
		tiropos.x = jokalariapos.x + 32;
		tiropos.y = jokalariapos.y + 12;
		break;
	case 4:
		tiropos.x = jokalariapos.x + 15;
		tiropos.y = jokalariapos.y + 15;
		break;
		//Dragoi berdea eta urdina
	case 5:
		tiropos.x = jokalariapos.x + 10;
		tiropos.y = jokalariapos.y + 15;
		break;
		//Dragoi gorria
	case 8:
		//Ezkerrera
		tiropos.x = jokalariapos.x + 20;
		tiropos.y = jokalariapos.y + 80;
		break;
	case 6:
		//Eskumara
		tiropos.x = jokalariapos.x + 150;
		tiropos.y = jokalariapos.y + 75;
		break;
	case 9:
		//Gora
		tiropos.x = jokalariapos.x + 95;
		tiropos.y = jokalariapos.y + 15;
		break;
	case 7:
		//Behera
		tiropos.x = jokalariapos.x + 90;
		tiropos.y = jokalariapos.y + 95;
		break;
		//Final boss
	case 10://Eskumara
		tiropos.x = jokalariapos.x + 185;
		tiropos.y = jokalariapos.y + 75;
		break;
	case 11://Ezkerrera
		tiropos.x = jokalariapos.x + 10;
		tiropos.y = jokalariapos.y + 70;
		break;
	default:
		break;
	}
	return tiropos;
}