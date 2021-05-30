#include "Puzzle.h"


void mainPuzzle(tPuzzle& juego){
	bool gana = false;
	while (!gana){		
		if (cargar(juego,juego.tipoPuzzle)){		//hacemos la carga del puzzle
			gana = jugar(juego);		

		}
		else{
			cout << endl << "ERROR: Matriz inicial y Matriz final no cargada correctamente" << endl;
			//gana = true;
		}

	}
	
}

bool cargar(tPuzzle& jpm, string tipo){	//done
	bool  cargado = false, matIcargada = false, matFincargada = false;
	ifstream archivo;
	jpm.nombreFichero += ".txt";
	archivo.open(jpm.nombreFichero);
	if (!archivo.is_open()){
		cout << "Error en la apertura o carga del archivo..." << endl;
	}else if(archivo.is_open()){

		matIcargada = cargar(jpm.matIni, archivo);
		matFincargada = cargar(jpm.matFin, archivo);
		archivo >> jpm.numMaxMov;	//para leer los numeros de intentos
		archivo.close();
		if (matIcargada && matFincargada) {
			cargado = true;

		}
		else {
			cargado = false;
		}
	}
	return cargado;
}

void mostrar(const tPuzzle& jpm){	//done
	cout << endl <<endl << "   Numero de intentos: " << jpm.numMaxMov << endl << endl;
	cout << "    Imagen original: " << endl;
	printMatriz(jpm.matIni);
	cout << "   Imagen final: " << endl;
	printMatriz(jpm.matFin);
}

bool jugar(tPuzzle& jpm){	//done
	bool jugado = false, ganar = false;
	mostrar(jpm);
	while ((jpm.numMaxMov > 0) && (jugado == false)){
		accion(jpm);
		jpm.numMaxMov--;
		mostrar(jpm);
		if (juegoGanado(jpm)) {//esto esta nice
			ganar = true;
			cout << endl << " ¡¡ Enorabuena has ganado la partida !!" << endl;
			exit(1);
		}
		if ((jpm.numMaxMov == 0)){
			jugado = true;

		}

	}
	return jugado;
}

bool juegoGanado(const tPuzzle& jpm) {		//funcion de logica especial propia para comprobar si ha ganado el juego
	bool ganado = false;
	if (jpm.matIni == jpm.matFin)		//utiliza el operador == definido en el modulo matriz para comparar las matrices y ver si son iguales.
	{
		ganado = true;
	}
	return ganado;
}

void accion(tPuzzle& jpm){
	bool accionado = false;
	string ac;
	int f1, f2, c1, c2;
	cout << endl << "   Introduzca un comando a realizar:   " << endl << endl;
	while (!accionado){
		if (jpm.tipoPuzzle == "1D") {
			cin >> ac;
			if (ac == "SF") {		//funciona 
				cout << "   Que fila desea voltear: " << endl;
				cin >> f1 >> f2;
				accionado = swapF(jpm.matIni, f1, f2);
			}
			else if (ac == "SC") {		//funciona
				cout << "   Que columnas desea intercambiar: " << endl;
				cin >> c1 >> c2;
				accionado = swapC(jpm.matIni, c1, c2);
			}
			else if (ac == "VF") {		//funciona
				cout << "   Que fila desea voltear: " << endl;
				cin >> f1;
				accionado = voltearF(jpm.matIni, f1);
			}
			else if (ac == "SD") {		//funciona Parcialmente
				cout << "   Que diagonales desea intercambiar: " << endl;
				cin >> f1;
				accionado = swapD(jpm.matIni, f1);
			}
			else if (ac == "VC") {	    //funciona
				cout << "   Que columna desea voltear: " << endl;
				cin >> f1;
				accionado = voltearC(jpm.matIni, f1);
			}
			else if (ac == "VD") {		// deberia funcionar(juan embid) 
				cout << "   Que diagonal desea voltear: " << endl;
				cin >> f1;
				accionado = voltearD(jpm.matIni, f1);

			}//funcion de prueba de swap(para hacer test)
			else if (ac == "swap") {
				cin >> f1 >> f2 >> c1 >> c2;
				firstswap(jpm.matIni, f1, f2, c1, c2);
			}

		}
		else if (jpm.tipoPuzzle == "2D"){
			cin >> ac;
			if (ac == "VV") {

				voltearV(jpm.matIni);
				accionado = true;

			}
			else if (ac == "VH") {

				voltearH(jpm.matIni);
				accionado = true;

			}
			else if (ac == "RD") {		//funciona correctamente
				rotarD(jpm.matIni);
				accionado = true;

			}
			else if (ac == "SA") {		//no funciona correctamente(revisar)
				tCoor a, b;
				cout << "   Casilla 1: " << endl;
				cin >> a.coordenadaX;
				cin >> a.coordenadaY;
				cout << endl << "   Casilla 2: ";
				cin >> b.coordenadaX;
				cin >> b.coordenadaY;
				accionado = swapAdy(jpm.matIni, a, b);		//esta funcion la cree yo,de alguna forma aqui no funciona revisar.

			}
			else if (ac == "VD") {
				//accionado = VoltearID(jpm.matIni);  


			}
		}
	}
}

