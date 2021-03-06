#include "funtzioak.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

void botoiaKoordenatuak(MAPA botoia[])
{
	botoia[0].x0 = 0;
	botoia[0].x1 = 65;
	botoia[0].y0 = 0;
	botoia[0].y1 = 65;
	botoia[1].x0 = 183;
	botoia[1].x1 = 455;
	botoia[1].y0 = 190;
	botoia[1].y1 = 223;
	botoia[2].x0 = 183;
	botoia[2].x1 = 455;
	botoia[2].y0 = 250;
	botoia[2].y1 = 283;
	botoia[3].x0 = 183;
	botoia[3].x1 = 455;
	botoia[3].y0 = 307;
	botoia[3].y1 = 340;
	botoia[4].x0 = 183;
	botoia[4].x1 = 455;
	botoia[4].y0 = 190;
	botoia[4].y1 = 223;
	botoia[5].x0 = 183;
	botoia[5].x1 = 455;
	botoia[5].y0 = 307;
	botoia[5].y1 = 340;
	botoia[6].x0 = 183;
	botoia[6].x1 = 455;
	botoia[6].y0 = 365;
	botoia[6].y1 = 398;
	botoia[7].x0 = 183;
	botoia[7].x1 = 455;
	botoia[7].y0 = 250;
	botoia[7].y1 = 293;
}

void mapakoKoordenatuak(MAPA karratua[])
{
	karratua[0].x0 = 10;
	karratua[0].y0 = 470;
	karratua[0].x1 = 640;
	karratua[0].y1 = 480;
	karratua[1].x0 = 0;
	karratua[1].y0 = 0;
	karratua[1].x1 = 680;
	karratua[1].y1 = 10;
	karratua[2].x0 = 0;
	karratua[2].y0 = 10;
	karratua[2].x1 = 10;
	karratua[2].y1 = 160;//
	karratua[3].x0 = 10;
	karratua[3].y0 = 150;
	karratua[3].x1 = 50;
	karratua[3].y1 = 160;
	karratua[4].x0 = 50;
	karratua[4].y0 = 150;
	karratua[4].x1 = 60;
	karratua[4].y1 = 195;
	karratua[5].x0 = 0;
	karratua[5].y0 = 185;
	karratua[5].x1 = 50;
	karratua[5].y1 = 195;
	karratua[6].x0 = 0;
	karratua[6].y0 = 255;
	karratua[6].x1 = 60;
	karratua[6].y1 = 265;
	karratua[7].x0 = 50;
	karratua[7].y0 = 255;
	karratua[7].x1 = 60;
	karratua[7].y1 = 300;
	karratua[8].x0 = 0;
	karratua[8].y0 = 290;
	karratua[8].x1 = 50;
	karratua[8].y1 = 300;
	karratua[9].x0 = 0;
	karratua[9].y0 = 300;
	karratua[9].x1 = 10;
	karratua[9].y1 = 480;
	karratua[15].x0 = 10;
	karratua[15].y0 = 470;
	karratua[15].x1 = 310;
	karratua[15].y1 = 480;
	karratua[11].x0 = 300;
	karratua[11].y0 = 410;
	karratua[11].x1 = 310;
	karratua[11].y1 = 470;
	karratua[12].x0 = 310;
	karratua[12].y0 = 410;
	karratua[12].x1 = 340;
	karratua[12].y1 = 420;
	karratua[13].x0 = 330;
	karratua[13].y0 = 420;
	karratua[13].x1 = 340;
	karratua[13].y1 = 480;
	karratua[14].x0 = 340;
	karratua[14].y0 = 470;
	karratua[14].x1 = 680;
	karratua[14].y1 = 480;
	karratua[10].x0 = 630;
	karratua[10].y0 = 10;
	karratua[10].x1 = 640;
	karratua[10].y1 = 480;
	karratua[16].x0 = 80;
	karratua[16].y0 = 70;
	karratua[16].x1 = 130;
	karratua[16].y1 = 80;
	karratua[17].x0 = 200;
	karratua[17].y0 = 70;
	karratua[17].x1 = 440;
	karratua[17].y1 = 80;
	karratua[18].x0 = 510;
	karratua[18].y0 = 70;
	karratua[18].x1 = 560;
	karratua[18].y1 = 80;
	karratua[19].x0 = 130;
	karratua[19].y0 = 160;
	karratua[19].x1 = 195;
	karratua[19].y1 = 170;
	karratua[20].x0 = 310;
	karratua[20].y0 = 160;
	karratua[20].x1 = 330;
	karratua[20].y1 = 170;
	karratua[21].x0 = 440;
	karratua[21].y0 = 160;
	karratua[21].x1 = 510;
	karratua[21].y1 = 170;
	karratua[22].x0 = 240;
	karratua[22].y0 = 170;
	karratua[22].x1 = 250;
	karratua[22].y1 = 300;
	karratua[23].x0 = 250;
	karratua[23].y0 = 290;
	karratua[23].x1 = 290;
	karratua[23].y1 = 300;
	karratua[25].x0 = 350;
	karratua[25].y0 = 290;
	karratua[25].x1 = 390;
	karratua[25].y1 = 300;
	karratua[24].x0 = 390;
	karratua[24].y0 = 170;
	karratua[24].x1 = 400;
	karratua[24].y1 = 290;
	karratua[26].x0 = 120;
	karratua[26].y0 = 300;
	karratua[26].x1 = 170;
	karratua[26].y1 = 390;
	karratua[27].x0 = 470;
	karratua[27].y0 = 300;
	karratua[27].x1 = 520;
	karratua[27].y1 = 390;
	karratua[28].x0 = 10;
	karratua[28].y0 = 470;
	karratua[28].x1 = 640;
	karratua[28].y1 = 480;
	karratua[29].x0 = 120;
	karratua[29].y0 = 90;
	karratua[29].x1 = 270;
	karratua[29].y1 = 300;
	karratua[30].x0 = 350;
	karratua[30].y0 = 90;
	karratua[30].x1 = 500;
	karratua[30].y1 = 300;
	karratua[31].x0 = 70;
	karratua[31].y0 = 380;
	karratua[31].x1 = 270;
	karratua[31].y1 = 390;
	karratua[32].x0 = 350;
	karratua[32].y0 = 380;
	karratua[32].x1 = 550;
	karratua[32].y1 = 390;
}