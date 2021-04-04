#pragma once
#include <iostream>
#include "Matriz.h"

using namespace std;

bool cargar(tMatrizChar& mat, istream& ent){
	bool cargado = false;
	ent >> mat.numFilas;
	ent >> mat.numCols;
	if (mat.numFilas*mat.numCols != 0){
		cargado = true;
		for (int i = 0; i < mat.numFilas; i++) {
			for (int j = 0; j < mat.numCols; j++)
			{
				ent >> mat.datos[i][j];
			}
		}
	}else{
		cout << "Numero de filas y columnas incorrecto..." << endl;
		cargado = false;
	}

	return cargado;
}

void printMatriz(const tMatrizChar& mat) {	//NO CAMBIAR
	cout << endl;
	for (int i = 0; i < mat.numFilas; i++){
		for (int j = 0; i < mat.numCols; j++){
			
			colorCTA(15, int(mat.datos[i][j]) - int('0'));
			cout << ' ' << ' ';

		}
		cout << endl;
	}
	colorCTA(15, 0);	//devuelve la consola el color de fondo y texto original
	cout << endl;
}

bool operator==(tMatrizChar const& mat1, tMatrizChar const& mat2){

	return false;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2){

	return false;
}

bool swapF(tMatrizChar& mat, int f1, int f2){

	return false;
}

bool swapC(tMatrizChar& mat, int c1, int c2){

	return false;
}

bool swapD(tMatrizChar& mat, int d){

	return false;
}

bool voltearF(tMatrizChar& mat, int f){

	return false;
}

bool voltearC(tMatrizChar& mat, int c){

	return false;
}

bool voltearD(tMatrizChar& mat, int c){
	return false;
}
