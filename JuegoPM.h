//#pragma once
#ifndef JUEGOPM_H
#define JUEGOPM_H
#include "Matriz.h"
typedef struct {
	string tipo;
	int num;
	tMatrizChar matIni, matFin;
} tJuegoPM;

void mainJuegoPM();

int menu();

void banner();

bool iniciar(tJuegoPM& jpm, string modo, int num);

bool cargar(tJuegoPM& jpm);

void mostrar(const tJuegoPM& jpm);

bool jugar(tJuegoPM& jpm);

void accion(tJuegoPM& jpm);






#endif 


