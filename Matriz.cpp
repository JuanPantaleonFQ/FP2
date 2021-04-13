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
	bool igual = true;
	for (int i = 0; i < mat1.numFilas; i++) {
		for (int j = 0; j < mat1.numCols; j++) {
			if (mat1.datos[i][j]!= mat2.datos[i][j]){igual =false}
		}
	}
	return igual;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2){
	uint8 aux = mat.datos[pos1.coordenadaX][pos1.coordenadaY];
	mat.datos[pos1.coordenadaX][pos1.coordenadaY] = mat[pos2.coordenadaX][pos2.coordenadaY];
	mat.datos[pos2.coordenadaX][pos2.coordenadaY] = aux;
	return true;
}

bool swapF(tMatrizChar& mat, int f1, int f2){
	uint8 aux;
	if (f1 > mat.numFilas || f1<0 || f2>mat.numFilas || f2 < 0) {
		return false;
	}
	else {
		for (int i = 0; i < mat.numCols; i++) {
			aux = mat.datos[f1][i];
			mat.datos[f1][i] = mat.datos[f2][i];
			mat.datos[f2][i] = aux;
		}
		return true;
	}

}

bool swapC(tMatrizChar& mat, int c1, int c2){
	uint8 aux;
	if (c1 > mat.numCols || c1<0 || c2>mat.numCols || c2 < 0) {
		return false;
	}
	else {
		for (int i = 0; i < mat.numFilas; i++) {
			aux = mat.datos[i][c2];
			mat.datos[i][c1] = mat.datos[i][c2];
			mat.datos[i][c2] = aux;
		}
		return true;
	}

}

bool swapD(tMatrizChar& mat, int d) {
	if (d > mat.numCols || d > mat.numFilas) {

		return false;
	}
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
