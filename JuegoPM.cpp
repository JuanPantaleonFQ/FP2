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
		
		if (juegoGanado(jpm)){
			ganado = true;
			cout << "Enorabuena has ganado la partida!!" << endl;
			exit(1);
		}
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
	bool accionado = false;
	string ac;
	int f1, f2, c1, c2;
	cout << endl << "   Introduzca un comando a realizar:   " << endl << endl;
	
	
	if (jpm.tipo == "1D") {
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
	else if (jpm.tipo == "2D") {
		cin >> ac;
		if (ac == "VV"){			
					
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
			tCoor a,b;
			cout << "   Casilla 1: " << endl;
			cin >> a.coordenadaX;
			cin >> a.coordenadaY;
			cout << endl << "   Casilla 2: ";
			cin >> b.coordenadaX;
			cin >> b.coordenadaY;
			accionado = swapAdy(jpm.matIni, a, b);		//esta funcion la cree yo,de alguna forma aqui no funciona revisar.
			
		}
		else if (ac =="VD"){	
			//accionado = VoltearID(jpm.matIni);  


		}
		

		
	}
	return accionado;
}
