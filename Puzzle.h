#pragma once
//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.
#ifndef PUZZLE_H
#define PUZZLE_H
#include "Matriz.h"


typedef struct {
	string tipo;	//tipo de juego, 2D o 1D
	int num;		//intentos de realizar el ejercicio
	tMatrizChar matIni, matFin;
	string file;
} tPuzzle;

//string TiposJPM[]{ "1D","2D" };

void mainJuegoPM();

int menu();

int menu1D(int orden);

int menu2D(int orden);

void printMatriz(const tMatrizChar& mat); //Funcion a�adida exclusiva @juanfemeniaquevedo, ense�a la matriz que se le pase por parametro

//void banner();

bool iniciar(tJuegoPM& jpm, string modo);

bool cargar(tJuegoPM& jpm);

bool juegoGanado(const tJuegoPM& jpm);

void mostrar(const tJuegoPM& jpm);

bool jugar(tJuegoPM& jpm);

bool accion(tJuegoPM& jpm);






#endif 