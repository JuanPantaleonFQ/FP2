#include <iostream>
#include "Coordenada.h"

bool operator==(tCoor c1, tCoor c2) {
	if (c1.coordenadaX == c2.coordenadaX && c1.coordenadaX == c2.coordenadaY) { return true; }
	else { return false; }
}

bool operator!=(tCoor c1, tCoor c2) {
	if (c1 == c2) {
		return false;
	}
	else
	{
		return true;
	}
}

tCoor operator+(tCoor c1, tCoor c2) {
	tCoor exit;
	exit.coordenadaX = c1.coordenadaX + c2.coordenadaX;
	exit.coordenadaY = c1.coordenadaY + c2.coordenadaY;
	return exit;
}

tCoor operator-(tCoor c1, tCoor c2) {
	tCoor exit;
	exit.coordenadaX = c1.coordenadaX - c2.coordenadaX;
	exit.coordenadaY = c1.coordenadaY - c2.coordenadaY;
	return exit;
}