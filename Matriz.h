#pragma once
//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.
#ifndef MATRIZ_H
#define MATRIZ_H

#include "Coordenada.h"


const int DIM_MAX = 64;


typedef struct {
	int numFilas, numCols;
	uint8 datos[DIM_MAX][DIM_MAX];
} tMatrizChar;

bool cargar(tMatrizChar& mat, istream& ent);

bool swapAdy(tMatrizChar matriz, tCoor a, tCoor s);


bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2); //compara si las dos matrices son iguales.

void printMatriz(const tMatrizChar& mat);

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2); // intercambia las coordenadas pos1 y pos2 de la matriz.Devuelve falso si las posiciones no pertenecen al rango de la matriz.

bool swapF(tMatrizChar& mat, int f1, int f2); /*: intercambia las filas f1 y f2 de
		la matriz.Devuelve falso si las filas no pertenecen al rango de la matriz.*/

void rotarD(tMatrizChar& mat);

bool swapC(tMatrizChar& mat, int c1, int c2); /*: intercambia las columnas c1 y c2.
												 Devuelve falso si las columnas no pertenecen al rango de la matriz.*/

bool swapD(tMatrizChar& mat, int d); /*: intercambia las diagonales d y - d.
	Devuelve falso si las diagonales no pertenecen al rango de la matriz, o si la matriz no es
	cuadrada.*/
bool voltearF(tMatrizChar& mat, int f);/* dar la vuelta a la fila f con respecto al
	eje vertical central de la imagen.Devuelve falso si la fila no pertenece al rango de la
	matriz.*/

bool voltearC(tMatrizChar& mat, int c); /*dar la vuelta a la columna c con
	respecto al eje horizontal central de la imagen.Devuelve falso si la columna no pertenece
	al rango de la matriz.*/

bool voltearD(tMatrizChar& mat, int c);	


#endif 




