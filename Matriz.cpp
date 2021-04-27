#pragma once
//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.
#include "Matriz.h"

using namespace std;

bool cargar(tMatrizChar& mat, istream& ent) {
	bool cargado = false;
	ent >> mat.numFilas;
	ent >> mat.numCols;
	if (mat.numFilas * mat.numCols != 0) {
		cargado = true;
		for (int i = 0; i < mat.numFilas; i++) {
			for (int j = 0; j < mat.numCols; j++)
			{
				ent >> mat.datos[i][j];
			}
		}
	}
	else {
		cout << "Numero de filas y columnas incorrecto..." << endl;
		cargado = false;
	}

	return cargado;
}

void printMatriz(const tMatrizChar& mat) {	
	for (int i = 0; i < mat.numFilas; i++) {
		for (int j = 0; j < mat.numCols; j++) {

			colorCTA(15, int(mat.datos[i][j]) - int('0'));
			cout << ' ' << ' ';

		}
		colorCTA(15, 0);
		cout << endl;
	}
	
}

bool operator==(tMatrizChar const& mat1, tMatrizChar const& mat2) {
	bool igual = true;
	for (int i = 0; i < mat1.numFilas; i++) {
		for (int j = 0; j < mat1.numCols; j++) {
			if (mat1.datos[i][j] != mat2.datos[i][j]) {
				igual = false;
			}
		}
	}
	return igual;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {		//por ver
	uint8 aux = mat.datos[pos1.coordenadaX][pos1.coordenadaY];
	mat.datos[pos1.coordenadaX][pos1.coordenadaY] = mat.datos[pos2.coordenadaX][pos2.coordenadaY];
	mat.datos[pos2.coordenadaX][pos2.coordenadaY] = aux;
	return true;
}

bool swapF(tMatrizChar& mat, int f1, int f2) {		//funciona correctamente
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

bool swapC(tMatrizChar& mat, int c1, int c2) {
	uint8 aux;
	if (c1 > mat.numCols || c1<0 || c2>mat.numCols || c2 < 0) {
		return false;
	}
	else {
		for (int i = 0; i < mat.numFilas/2; i++) {
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
	uint8 aux;
	int numVeces = mat.numCols / 2;
	if (f > mat.numFilas || f < 0) { return false; }
	else {
		for (int i = 0; i < numVeces;i++) {
			aux = mat.datos[f][i];
			mat.datos[f][i] = mat.datos[f][mat.numCols - i];
			mat.datos[f][mat.numCols - i] = aux;
		}
		return true;
	}
}

bool voltearC(tMatrizChar& mat, int c) {
	uint8 aux;
	int numVeces = mat.numFilas/2;
	if (c > mat.numCols || c < 0) { return false; }
	else {
		for (int i = 0; i < numVeces; i++) {
			aux = mat.datos[i][c];
			mat.datos[i][c] = mat.datos[mat.numFilas - (i+1)][c];
			mat.datos[mat.numFilas- (i+1)][c] = aux;
		}
		return true;
	}
}

void rotarD(tMatrizChar& mat) {
	tMatrizChar matriz_aux;		//Creamos una matriz auxiliar para la funcion(matriz local)
	matriz_aux.numFilas = mat.numFilas;
	matriz_aux.numCols = mat.numCols;

	for (int i = 0; i < mat.numFilas; i++) {
		for (int j = 0; j < mat.numCols; j++) {
			matriz_aux.datos[i][j] = mat.datos[i][j];
		}
	}
	mat.numFilas = matriz_aux.numFilas;
	mat.numCols = matriz_aux.numCols;
	for (int x = 0; x < mat.numFilas; x++) {
		for (int z = 0; z < mat.numCols; z++) {
			mat.datos[x][z] = matriz_aux.datos[z][matriz_aux.numFilas - 1 - x];
		}
	}
}

bool swapAdy(tMatrizChar matriz, tCoor a, tCoor s){
	
	bool cambiado = false;
	uint8 aux;
	
	if((a.coordenadaX - s.coordenadaX < -1 && a.coordenadaX - s.coordenadaX > 1) || (a.coordenadaY - s.coordenadaY < -1 && a.coordenadaY - s.coordenadaY > 1)){

		if (a.coordenadaX > 0 && a.coordenadaX < matriz.numFilas - 1 && s.coordenadaX > 0 && s.coordenadaX < matriz.numFilas - 1 && a.coordenadaY > 0 && a.coordenadaY < matriz.numFilas - 1 && s.coordenadaY > 0 && s.coordenadaY < matriz.numFilas - 1)
			for (int i = -1;i < 2; i++) {
				for (int c = -1; c < 2; c++) {
					if (i != 0 || c!= 0) {
						aux = matriz.datos[i + s.coordenadaY][c + a.coordenadaX];
						matriz.datos[i + a.coordenadaY][c + a.coordenadaX] = matriz.datos[i + s.coordenadaX][c + s.coordenadaX];
						matriz.datos[i + s.coordenadaY][c + s.coordenadaX] = aux;
					}
				}
			}
		cambiado = true;
	}
	return cambiado;
}

bool voltearD(tMatrizChar& mat, int d){
	bool resultado = false;
	uint8 aux;
	if (mat.numCols == mat.numFilas) {
		if (d < mat.numCols && d >= mat.numCols) {
			int k = (mat.numCols + d) / 2;
			int b = 0;
			if (d < 0) {
				d = -d;
				for (int a = d; a < k; a++) {
					aux = mat.datos[a][b];
					mat.datos[a][b] = mat.datos[mat.numCols - b - 1][mat.numCols - a - 1];
					mat.datos[mat.numCols - b - 1][mat.numCols - a - 1] = aux;
					b++;
				}
			}
			else {
				for (int a = d; a < k; a++) {
					aux = mat.datos[b][a];
					mat.datos[b][a] = mat.datos[mat.numCols - a - 1][mat.numCols - b - 1];
					mat.datos[mat.numCols - a - 1][mat.numCols - b - 1] = aux;
					b++;
				}
			}
			resultado = true;
		}
	}
	return resultado;
	return false;
}

void voltearV(tMatrizChar& mat) {
	int numVeces = mat.numCols / 2;
	uint8 aux;
	for (int i = 0; i < numVeces; i++) {
		for (int j = 0; j < mat.numFilas; j++) {
			aux = mat.datos[i][j];
			mat.datos[i][j] = mat.datos[i][mat.numCols - j];
			mat.datos[i][mat.numCols - j] = aux;
		}
	}
}

void voltearH(tMatrizChar& mat) {
	int numVeces = mat.numFilas / 2;
	uint8 aux;
	for (int i = 0; i < numVeces; i++) {
		for (int j = 0; j < mat.numFilas; j++) {
			aux = mat.datos[i][j];
			mat.datos[i][j] = mat.datos[mat.numFilas-i][j];
			mat.datos[mat.numFilas - i][j] = aux;
		}
	}
}