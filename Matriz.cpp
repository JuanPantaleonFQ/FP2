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

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {		//funciona
	uint8 aux = mat.datos[pos1.coordenadaX][pos1.coordenadaY];
	mat.datos[pos1.coordenadaX][pos1.coordenadaY] = mat.datos[pos2.coordenadaX][pos2.coordenadaY];
	mat.datos[pos2.coordenadaX][pos2.coordenadaY] = aux;
	return true;
}


//funcion de prueba para probar swap
void firstswap(tMatrizChar& mat, int n1, int n2, int m1, int m2) {
	tCoor coordenada1, coordenada2;
	coordenada1.coordenadaX = n1;
	coordenada1.coordenadaY = n2;
	coordenada2.coordenadaX = m1;
	coordenada2.coordenadaY = m2;
	swap(mat, coordenada1, coordenada2);


}

bool voltearV(tMatrizChar& mat){//del txt
	bool bolteado = false;
	int aux;
	for (int i = 0; i <mat.numFilas ; i++){
		for (int j = 0; j < (mat.numCols/2) ; j++){
			aux = mat.datos[i][j];
			mat.datos[i][j] = mat.datos[i][(mat.numCols - 1) - j];
			mat.datos[i][(mat.numCols - 1) - j] = aux;

		}

	}

	

	return bolteado;
}

bool voltearH(tMatrizChar& mat) {//del txt
	int filasAux = mat.numFilas - 1, cont = 0;
	bool bolteado = false;
	while (cont < (mat.numFilas / 2)) {

		if (swapF(mat, cont, filasAux)) {

			bolteado = true;

		}
		cont++;
		filasAux--;

	}
	return bolteado;
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

bool swapC(tMatrizChar& mat, int c1, int c2) {	//funciona
	uint8 aux;
	if (c1 > mat.numCols || c1<0 || c2>mat.numCols || c2 < 0) {
		return false;
	}
	else {
		for (int i = 0; i < mat.numFilas; i++) {
			
			firstswap(mat,i,c1,i,c2);
		}
		return true;
	}
	
}

bool swapD(tMatrizChar& mat, int diagonal) { //parcialmente correcto.
	if (diagonal > mat.numCols || diagonal > mat.numFilas || diagonal == 0) {
		return false;
	}else{

		for (int i = 0; i < mat.numCols; i++){
			
			if (i == mat.numCols-1){
				
				
				firstswap(mat, i, diagonal, diagonal , i);
			}
			else{
				firstswap(mat, i, diagonal, diagonal, i);
			}
			
		}

		return true;
	}
}

bool voltearF(tMatrizChar& mat, int f){//funciona
	
	uint8 aux;	
	int numVeces = mat.numCols / 2;
	if (f > mat.numFilas || f < 0) { return false; }
	else {
		for (int i = 0; i < numVeces; i++) {
			aux = mat.datos[f][i];
			mat.datos[f][i] = mat.datos[f][mat.numCols - (i + 1)];
			mat.datos[f][mat.numCols - (i + 1)] = aux;
		}
		return true;
	}
}

bool voltearC(tMatrizChar& mat, int c) {	//funciona
	
	uint8 aux;	// funcion arreglada de Xarli
	int numVeces = mat.numFilas / 2;
	if (c > mat.numCols || c < 0) { return false; }
	else {
		for (int i = 0; i < numVeces; i++) {
			aux = mat.datos[i][c];
			mat.datos[i][c] = mat.datos[mat.numFilas - (i + 1)][c];
			mat.datos[mat.numFilas - (i + 1)][c] = aux;
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
	tCoor posi1, posi2;
	int i, j,l, m;
	if (d <= mat.numCols && d >= -mat.numCols) {
		if (mat.numCols == mat.numFilas) {
			resultado = true;
			if (d < 0) {
				d = -d;	//d es absoluto
				 i = d;
				 j = mat.numFilas - 1 - d;
				 l = 0;
				 m = mat.numFilas - 1;
				for (int a = 0; a < mat.numCols; a++) {
					posi1.coordenadaX = i;
					posi1.coordenadaY = l;
					posi2.coordenadaX = m;
					posi2.coordenadaY = j;
					swap(mat, posi1, posi2);
					i++;	
					j--;
					l++;
					m--;

				}
			}else{
				i = d;
				j = mat.numFilas - 1 - d;
				l = 0;
				m = mat.numFilas - 1;
				for (int k = 0; k < mat.numCols; k++)
				{
					posi1.coordenadaX = l;
					posi1.coordenadaY = i;
					posi2.coordenadaX = j;
					posi2.coordenadaY = m;
					swap(mat, posi1, posi2);
					i++;
					j--;
					l++;
					m--;	
				}
			}

		}
		else
		{

		}

			
		resultado = true;
	}
	
	return resultado;



	return false;
}






/*bool VoltearID(tMatrizChar matrizIni){
	bool volteado = false;


	return volteado;
}*/
