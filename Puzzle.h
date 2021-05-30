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

void mainPuzzle(tPuzzle& jpm); /*funci�n que resuelve un puzzle. Corresponde a
								la antigua funci�n mainJuegoPM*/

bool cargar(tPuzzle& jpm, string tipo);	/*abre el fichero que corresponda y
										llama a la funci�n cargar del m�dulo Matriz.*/

void mostrar(const tPuzzle& jpm);  /*muestra el estado del puzzle utilizando las
									facilidades del m�dulo utilidadesSYS*/

bool jugar(tPuzzle& jpm);	/*permite realizar las acciones necesarias para jugar
								y controla si se ha llegado al l�mite de acciones permitidas*/

void accion(tPuzzle& jpm);		/*seg�n el comando de acci�n tecleado por el
							usuario, llama a la acci�n correspondiente definida en el m�dulo Matriz*/

#endif
