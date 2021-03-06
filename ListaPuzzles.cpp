#include "ListaPuzzles.h"


void inicializar(tPuzzlesReunidos& jr){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < MAX_PUZZLES; j++){
			jr[i].arrayPuzzles[j] = NULL;			
		}
	}
	
}

bool cargar(tPuzzlesReunidos& jr){

	string datos = "datosPuzzles.txt";
	bool cargado = false;
	int numRetos1D= 0, numRetos2D=0;

	ifstream archivo;
	archivo.open(datos);

	if (!archivo.is_open()) {
		cout << "Error en la apertura o carga del archivo..." << endl;

	}
	else {
		archivo >> numRetos1D;
		for (int i = 0; i < numRetos1D; i++){
			jr[0].arrayPuzzles[i]->tipoPuzzle = "1D";
			getline(archivo, jr[0].arrayPuzzles[i]->nombrePuzzle);
			getline(archivo, jr[0].arrayPuzzles[i]->nombreFichero);
			jr[0].contador++;
		}
		cin >> numRetos2D;
		for (int j = 0; j < numRetos2D; j++) {
			jr[0].arrayPuzzles[j]->tipoPuzzle = "2D";
			getline(archivo, jr[1].arrayPuzzles[j]->nombrePuzzle);
			getline(archivo, jr[1].arrayPuzzles[j]->nombreFichero);
			jr[1].contador++;
		}
		cargado = true;
		archivo.close();
	}
	
	return cargado;
}

void guardar(const tPuzzlesReunidos& listas){
	string datos = "datosPuzzles.txt";
	ofstream archivo;
	archivo.open(datos);
	archivo << listas[0].contador << endl;
	if (!archivo.is_open()) {
		cout << "Error en la apertura o carga del archivo..." << endl;
	}
	else {
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < listas[j].contador; i++) {
				archivo << listas[j].arrayPuzzles[i]->nombrePuzzle << endl;
				archivo << listas[j].arrayPuzzles[i]->nombreFichero << endl;
			}
		}
	}
}

int elegirPuzzle(tListaPuzzles& lp){	
	int puzzleElegido =mostrarListaPuzzles(lp);
	
	return puzzleElegido;
}

int mostrarListaPuzzles(tListaPuzzles& lp) {
	int numero;
	
	do {
		for (int i = 0; i < lp.contador; i++) {
			cout << i + 1 << ". " << lp.arrayPuzzles[i]->nombrePuzzle << " con un maximo de " << lp.arrayPuzzles[i]->numMaxMov << " movimientos." << endl;

		}
		cout << "0. Salir" << endl;
		cout << "-1. Ordenar la lista de mayor a menor" << endl;
		cout << "-2. Ordenar la lista de menor a mayor" << endl;
		cin >> numero;
	} while ((numero < -2) && (numero > lp.contador));

	

	
	return numero;
}

bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p){
	bool encontrado = false;
	for (int i = 0; i < MAX_PUZZLES; i++){
		if (p->numMaxMov<l.arrayPuzzles[i]->numMaxMov) {
			for (int j = MAX_PUZZLES; j > i; j--) {
				l.arrayPuzzles[j] = l.arrayPuzzles[j - 1];
				if (j == i + 1) {
					l.arrayPuzzles[i - 1] = p;
					}
			}
			encontrado = true;
		}
	}
	return encontrado;
}

bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos){
	bool encontrado = false;
	for (int i = 0; i < MAX_PUZZLES; i++){
		if (lista.arrayPuzzles[i] == puzzle) {
			pos = i;
			encontrado = true;
		}
	}
	return encontrado;
}
