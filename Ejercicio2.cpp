#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define PI 3.14159265

void circlePoints(int x, int y);
void midPointCircle(int radio, int angulo);

int main()
{
	int gd=DETECT, gm;
	int radio, angulo;

	printf("Entre el radio: ");
	std::cin >> radio;

	printf("Entre el ángulo: ");
	std::cin >> angulo;

	initgraph(&gd, &gm, NULL);

	midPointCircle(radio, angulo);

	getch();
	closegraph();

	return 0;
}

/* Dibuja por simetría en todos los octantes */
void circlePoints(int x, int y, int angulo)
{
	int maxx = getmaxx()/2;
	int maxy = getmaxy()/2;

	int oct = (angulo - (angulo % 45)) / 45;
	double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
	double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

	if (oct > 0 || oct == 0 && y > limit1)
		putpixel(maxx+x,maxy-y,WHITE);
	if (oct > 1 || oct == 1 && y <= limit2)
		putpixel(maxx+y,maxy-x,WHITE);
	if (oct > 2 || oct == 2 && y > limit1)
		putpixel(maxx+y,maxy+x,WHITE);
	if (oct > 3 || oct == 3 && y <= limit2)
		putpixel(maxx+x,maxy+y,WHITE);
	if (oct > 4 || oct == 4 && y > limit1)
		putpixel(maxx-x,maxy+y,WHITE);
	if (oct > 5 || oct == 5 && y <= limit2)
		putpixel(maxx-y,maxy+x,WHITE);
	if (oct > 6 || oct == 6 && y > limit1)
		putpixel(maxx-y,maxy-x,WHITE);
	if (oct > 7 || oct == 7 && y <= limit2)
		putpixel(maxx-x,maxy-y,WHITE);
}

/* Algoritmo MidPointCircle */
void midPointCircle(int radio, int angulo)
{
	int x = 0, y = radio;
	double p = 5.0/4.0-radio;

	circlePoints(x, y, angulo);

	while(y > x) //tan((90.0 - angulo) * PI / 180.0) * x)
	{
		if(p < 0)
			p += 2.0 * x + 3.0;
		else
		{
			p += 2.0 * (x - y) + 5.0;
			y--;
		}

		x++;

		circlePoints(x, y, angulo);
	}
}
