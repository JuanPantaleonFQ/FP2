#pragma once


#ifndef LISTAPUZZLES_H
#define LISTAPUZZLES_H
#include "Puzzle.h"

const int MAX_PUZZLES = 100;

typedef tPuzzle* tPuzzlePtr; // definimos un tipo de variable denominada tPuzzlePtr
							// que sera siempre un puntero a una variable de tipo tPuzzle

typedef tPuzzlePtr tArrayPuzzlesPtr[MAX_PUZZLES];	//una lista de punteros que apuntan a un tPuzzle

typedef struct {
	tArrayPuzzlesPtr arrayPuzzles;		//metemos la lista en nuestra estructura de lista de puzzles, donde tendremos, la lista.
	int contador = 0;

}tListaPuzzles;

typedef tListaPuzzles tPuzzlesReunidos[2];	//tendremos un array de dos posiciones, con una lista de puzzles 1D y otra lista 2D.


//FUNCIONES:

void inicializar(tPuzzlesReunidos& jr);

bool cargar(tPuzzlesReunidos& jr);

void guardar(const tPuzzlesReunidos& listas);

int elegirPuzzle(tListaPuzzles& lp);

bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p);

bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos);// busca en una lista ordenada de puzzles un puzzle.

int mostrarListaPuzzles(tListaPuzzles& lp);	//funcion que muestra la lista de puzzles.

#endif
