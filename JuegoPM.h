#pragma once
//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.
#ifndef JUEGOPM_H
#define JUEGOPM_H
#include "ListaPuzzles.h"


/*typedef struct {
	string tipo;	//tipo de juego, 2D o 1D
	int num;		//intentos de realizar el ejercicio
	tMatrizChar matIni, matFin;
} tJuegoPM;*/

//string TiposJPM[]{ "1D","2D" };

int mainPuzzlesReunidos();

int menu();

//void printMatriz(const tMatrizChar& mat); //Funcion añadida exclusiva @juanfemeniaquevedo, enseña la matriz que se le pase por parametro

//void banner();

//bool iniciar(tJuegoPM& jpm, string modo);

//bool cargar(tJuegoPM& jpm);

//bool juegoGanado(const tJuegoPM& jpm);

//void mostrar(const tJuegoPM& jpm);

//bool jugar(tJuegoPM& jpm);

//bool accion(tJuegoPM& jpm);






#endif 
