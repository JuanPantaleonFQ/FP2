//#pragma once
#ifndef JUEGOPM_H
#define JUEGOPM_H
#include "Matriz.h"

typedef struct {
	string tipo;	//tipo de juego, 2D o 1D
	int num;		//intentos de realizar el ejercicio
	tMatrizChar matIni, matFin;
} tJuegoPM;

string TiposJPM[]{ "1D","2D" };

void mainJuegoPM();

int menu();

void banner();

bool iniciar(tJuegoPM& jpm, string modo);

bool cargar(tJuegoPM& jpm);

bool juegoGanado(tJuegoPM jpm);

void mostrar(const tJuegoPM& jpm);

bool jugar(tJuegoPM& jpm);

bool accion(tJuegoPM& jpm);






#endif 


