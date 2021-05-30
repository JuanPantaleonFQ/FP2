#pragma once


#ifndef PUZZLE_H
#define PUZZLE_H
#include "Matriz.h"

typedef struct {
	string nombrePuzzle;
	string nombreFichero;
	string tipoPuzzle;
	int numMaxMov;	//intentos de realizar el ejercicio
	tMatrizChar matIni, matFin;

}tPuzzle;

void mainPuzzle(tPuzzle& jpm); /*función que resuelve un puzzle. Corresponde a
								la antigua función mainJuegoPM*/

bool cargar(tPuzzle& jpm, string tipo);	/*abre el fichero que corresponda y
										llama a la función cargar del módulo Matriz.*/

void mostrar(const tPuzzle& jpm);  /*muestra el estado del puzzle utilizando las
									facilidades del módulo utilidadesSYS*/

bool jugar(tPuzzle& jpm);	/*permite realizar las acciones necesarias para jugar
								y controla si se ha llegado al límite de acciones permitidas*/

void accion(tPuzzle& jpm);		/*según el comando de acción tecleado por el
							usuario, llama a la acción correspondiente definida en el módulo Matriz*/

#endif
