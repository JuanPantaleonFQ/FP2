//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.
#include "JuegoPM.h"


const string msgerror = "Numero de intentos excedido";


void banner(){		//done
	cout << endl << endl;
	cout << "$$$$$$$\                                 $$\              " << endl;
	cout << "$$  __$$\                                $$ |             " << endl;
	cout << "$$ |  $$ |$$\    $$  \$$$$$$$$\  $$$$$$$$\  $$ |   $$$$$$\  " << endl;
	cout << "$$$$$$$  |$$ |  $$ | \____$$  | \____$$  |$$ | $$   __$$\  " << endl;
	cout << "$$  ____/ $$ |  $$ |   $$$$ _/   $$$$ _/$$ |$$$$$$$$| " << endl;
	cout << "$$ |      $$ |  $$ |  $$  _/    $$  _/  $$ |$$   ____| " << endl;
	cout << "$$ |      \$$$$$$  | $$$$$$$$\ $$$$$$$$\   $$ | \$$$$$$$\  " << endl;
	cout << "\__|       \______/  \________|\________|\__|     \_______| " << endl;
	cout << "                                                         " << endl;
	cout << "                                                         " << endl;
	cout << "                                                         " << endl;

}



int menu() {		//done
	banner();
	int opcion;
	do {
		cout << "     Elija una opcion." << endl << endl;
		cout << "     1. Version de juego - 1D" << endl;
		cout << "     2. version de juego - 2D" << endl;
		cout << "     0. Salir " << endl;
		cin >> opcion;

	} while (opcion > 2 || opcion < 0);

	return opcion;
}

void mainJuegoPM() {		//done
	tJuegoPM juego;		//creamos una instancia juego unica para nuestro programa
	bool exit = false, juegoCorrecto;
	do
	{
		switch (menu())
		{
		case 0:
			exit = true;
			break;
		case 1:
			juegoCorrecto = iniciar(juego, "1D");
			if (!juegoCorrecto) {
				cout << "   Error al iniciar el juego..." << endl;
			}
			if (!jugar(juego)) {
				cout << msgerror << endl;
			}

			break;
		case 2:
			juegoCorrecto = iniciar(juego, "2D");
			if (!juegoCorrecto) {
				cout << "   Error al iniciar el juego..." << endl;
			}
			if (!jugar(juego)) {
				cout << msgerror << endl;
			}

		}

	} while (!exit);



}

bool iniciar(tJuegoPM& jpm, string modo) {		//done
	bool iniciado = false;
	jpm.tipo = modo;
	if (cargar(jpm))
	{
		iniciado = true;
	}
	else
	{
		cout << "  No se ha cargado el juego..." << endl;
	}


	return iniciado;
}

bool cargar(tJuegoPM& jpm) {	//done revisada
	string nombre;
	ifstream archivo;
	bool cargado = false, matrizIniCharge = false, matrizFinCharge = false;
	
	

	cout << "   Nombre del archivo:" << endl;//(aqui es donde se pide el nombre de archivo y se abre el correspondiente).
	cin >> nombre;
	archivo.open(nombre);		//con el .txt(obligatorio)
	if (!archivo.is_open()) {
		cout << "Error en la apertura&carga del archivo..." << endl;

	}
	else {
		
		matrizIniCharge = cargar(jpm.matIni, archivo);
		matrizFinCharge = cargar(jpm.matFin, archivo);
		archivo >> jpm.num;	//para leer los numeros de intentos
		archivo.close();
		if (matrizIniCharge && matrizFinCharge) {
			cargado = true;

		}
		else {
			cargado = false;
		}




	}
	return cargado;
}

void mostrar(const tJuegoPM& jpm) {		//done
	cout << endl << "   Numero de intentos: " << jpm.num << endl << endl;
	cout << "    Imagen original:" << endl;
	printMatriz(jpm.matIni);
	cout << "   Imagen final: " << endl;
	printMatriz(jpm.matFin);
}

bool jugar(tJuegoPM& jpm) {
	
	bool jugado = false, ganado = false;
	mostrar(jpm);
	while (jpm.num != 0 || ganado) {	//una vez empieza el juego,hasta que no haya utilizado todos
		jugado = accion(jpm);
		jpm.num--;
		mostrar(jpm);
		ganado = juegoGanado(jpm);
		
	}

	return jugado;
}

bool juegoGanado(const tJuegoPM& jpm) {		//funcion de logica especial propia para comprobar si ha ganado el juego
	bool ganado = false;
	if (jpm.matIni == jpm.matFin)		//utiliza el operador == definido en el modulo matriz para comparar las matrices y ver si son iguales.
	{
		ganado = true;
	}
	return ganado;
}

bool accion(tJuegoPM& jpm) {
	cout << endl << "   Introduzca un comando a realizar:   " << endl << endl;
	
	bool accionado = false;
	string ac;
	int f1, f2, c1, c2;
	if (jpm.tipo == "1D") {
		cin >> ac;
		if (ac == "SF") {		//funciona correctamente el comando
			cout << "   Que columna quieres voltear: " << endl;
			cin >> f1 >> f2;
			swapF(jpm.matIni, f1, f2);
		}
		else if (ac == "SC") {		//no funciona correctamente(revisar)
			cout << "   Que columna quieres voltear: " << endl;
			cin >> c1 >> c2;
			swapC(jpm.matIni, c1, c2);
		}
		else if (ac == "VF") {		//no funciona correctamente(revisar)
			cout << "   Que columna quieres voltear: " << endl;
			cin >> f1;
			voltearF(jpm.matIni, f1);
		}
		else if (ac == "SD") {		//no funciona correctamente(revisar)
			cout << "   Que columna quieres voltear: " << endl;
			cin >> f1;
			swapD(jpm.matIni, f1);
		}
		else if (ac == "VC") {	    //no funciona correctamente(revisar)
			cout << "   Que columna quieres voltear: " << endl;
			cin >> f1;
			voltearC(jpm.matIni, f1);
		}
		else if (ac == "VD") {		//no funciona correctamente(revisar)
			cout << "   Que diagnolal desea voltear: " << endl;
			cin >> f1;
			voltearD(jpm.matIni, f1);

		}
	}
	else if (jpm.tipo == "2D") {
		cin >> ac;
		if (ac == "VV") {			//no funciona correctamente(revisar)
			//esta funcion VV no requiere de parametros revisar pdf practica		
			//voltearV(jpm.matIni);		//falta por hacer(no se ha hecho ni creado)
		}
		else if (ac == "VH") {		//no funciona correctamente(revisar)
			//esta funcion VH no requiere de parametros revisar pdf practica		
			//void voltearH(jpm.matIni):	//falta por hacer(no se ha hecho ni creado)
			
		}
		else if (ac == "RD") {		//funciona correctamente
			rotarD(jpm.matIni);

		}
		else if (ac == "SA") {		//no funciona correctamente(revisar)
			tCoor a,b;
			cout << "   Casilla 1: " << endl;
			cin >> a.coordenadaX;
			cin >> a.coordenadaY;
			cout << endl << "   Casilla 2: ";
			cin >> b.coordenadaX;
			cin >> b.coordenadaY;
			swapAdy(jpm.matIni, a, b);		//esta funcion la cree yo,de alguna forma aqui no funciona revisar.
			
		}
		else if (ac =="VD"){	
			// VoltearID(jpm.matIni);  //falta por hacer(no se ha hecho ni creado)


		}
		

		
	}
	return accionado;
}
