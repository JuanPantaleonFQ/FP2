#pragma once
#ifndef COORDENADA_H
#define COORDENADA_H
#include "UtilidadesSYS.h"

typedef struct {
	int coordenadaX;
	int coordenadaY;


}tCoor;

bool operator == (tCoor c1, tCoor c2);  /*compara si dos coordenadas son iguales.*/

bool operator != (tCoor c1, tCoor c2); /*compara si dos coordenadas son distintas.*/

tCoor operator + (tCoor c1, tCoor c2); /*devuelve la coordenada resultante de sumar las dos
coordenadas dadas por parámetros.*/





#endif
