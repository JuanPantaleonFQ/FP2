#include <iostream>
#include "JuegoPM.h"
using namespace std;

void banner(){		//done
	cout << "$$$$$$$\                                $$\                                                             " << endl;
	cout << "$$  __$$\                               $$ |                                                            " << endl;
	cout << "$$ |  $$ |$$\   $$\ $$$$$$$$\ $$$$$$$$\ $$ | $$$$$$\         $$$$$$\   $$$$$$\  $$$$$$\$$$$\   $$$$$$\  " << endl;
	cout << "$$$$$$$  |$$ |  $$ |\____$$  |\____$$  |$$ |$$  __$$\       $$  __$$\  \____$$\ $$  _$$  _$$\ $$  __$$\ " << endl;
	cout << "$$  ____/ $$ |  $$ |  $$$$ _/   $$$$ _/ $$ |$$$$$$$$ |      $$ /  $$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |" << endl;
	cout << "$$ |      $$ |  $$ | $$  _/    $$  _/   $$ |$$   ____|      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|" << endl;
	cout << "$$ |      \$$$$$$  |$$$$$$$$\ $$$$$$$$\ $$ |\$$$$$$$\       \$$$$$$$ |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\ " << endl;
	cout << "\__|       \______/ \________|\________|\__| \_______|       \____$$ | \_______|\__| \__| \__| \_______|" << endl;
	cout << "                                                            $$\   $$ |                                  " << endl;
	cout << "                                                            \$$$$$$  |                                  " << endl;
	cout << "                                                             \______/                                   " << endl;

}



int menu() {		//done
	banner();
	int opcion;
	do {
		cout << "Elija una opcion." << endl << endl;
		cout << "1. Version de juego - 1D" << endl;
		cout << "2. version de juego - 2D" << endl;
		cout << "0. Salir " << endl;
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
			juegoCorrecto =iniciar(juego, "1D");
			if (!juegoCorrecto){
				cout << "Error al iniciar el juego..." << endl;
			}
			if (!jugar(juego)) {
				cout << "Error al jugar" << endl;
			}

			break;
		case 2:
			juegoCorrecto =iniciar(juego, "2D");
			if (!juegoCorrecto) {
				cout << "Error al iniciar el juego..." << endl;
			}
			if (!jugar(juego)) {
				cout << "Error al jugar" << endl;
			}
			
		}			 

	} while (!exit);
	
	
	
}

bool iniciar(tJuegoPM& jpm, string modo){		//done
	bool iniciado = false;
	jpm.tipo = modo;
	if (cargar(jpm))
	{
		iniciado = true;
	}
	else
	{
		cout << "No se ha cargado el juego..." << endl;
	}
	

	return iniciado;
}

bool cargar(tJuegoPM& jpm){	//done
	string nombre;
	ifstream archivo;
	bool cargado = false, matrizIniCharge= false,matrizFinCharge = false;

	tMatrizChar matrizInicial;
	tMatrizChar matrizfinal;
	cout << "Nombre del archivo:" << endl;//(aqui es donde se pide el nombre de archivo y se abre el correspondiente).
	cin >> nombre;
	archivo.open(nombre);		//con el .txt(obligatorio)
	if (!archivo.is_open()){
		cout << "Error en la apertura&carga del archivo..." << endl;

	}else{
		matrizIniCharge = cargar(matrizInicial, archivo);
		matrizFinCharge = cargar(matrizfinal, archivo);
		archivo >> jpm.num;	//para leer los numeros de intentos
		archivo.close();
		if (matrizIniCharge && matrizFinCharge){
			cargado = true;
		}else{
			cargado = false;
		}
		
		
		

	}
	return cargado;
}

void mostrar(const tJuegoPM& jpm){		//done
	cout << "Numero de intentos: " << jpm.num << endl;
	cout << "Imagen original:" << endl;
	printMatriz(jpm.matIni);
	cout << "Imagen final: " << endl;
	printMatriz(jpm.matFin);
	


}

bool jugar(tJuegoPM& jpm){
	int contadorJuegos = 0;
	bool jugado = false, ganado = false;
	mostrar(jpm);
	while(contadorJuegos != jpm.num && ganado ) {	//una vez empieza el juego,hasta que no haya utilizado todos
		if (accion(jpm)){							//los intentos, o no haya ganado, se recogera una accion a realizar.
			jugado = true;
		}
		mostrar(jpm);
		ganado = juegoGanado(jpm);
		contadorJuegos++;
	}

	return jugado;
}

bool juegoGanado(tJuegoPM jpm){		//funcion de logica especial propia para comprobar si ha ganado el juego
	bool ganado = false;
	if (jpm.matIni == jpm.matFin)		//utiliza el operador == definido en el modulo matriz para comparar las matrices y ver si son iguales.
	{
		ganado = true;
	}
	return ganado;
}

bool accion(tJuegoPM& jpm){		//¡Ojo! Esta funcion es de tipo void originalmente! Preguntar profesor si problema con retorno.
	bool accionado = false;
	string ac;
	int f1, f2, c1, c2;
	if (jpm.tipo == TiposJPM[0]){
		cin >> ac;
		if (ac == "SF") {
			cin >> f1 >> f2;
			swapF(jpm.matIni, f1, f2);
		}
		else if (ac == "SC"){
			cin >> c1 >> c2;
			swapC(jpm.matIni, c1, c2);
		}else if (ac == "VF"){
			cin >> f1;
			voltearF(jpm.matIni, f1);
		}else if (ac == "SD"){
			cin >> f1;
			swapD(jpm.matIni, f1);
		}else if (ac == "VC"){
			cin >> f1;
			voltearC(jpm.matIni, f1);
		}else if (ac == "VD"){
			cin >> f1;
			voltearD(jpm.matIni, f1);
		}
	}else if (jpm.tipo == TiposJPM[1]){
		cin >> ac;
		if (ac == "VV") {
			cout << "Que columna quieres voltear: ";
			cin >> c1;
			voltearC(jpm.matIni, c1);
		}
		else if (ac == "VH") {
			cout << "Que fila quieres voltear: ";
			cin >> f1;
			voltearF(jpm.matIni, f1);
		}
		else if (ac == "RD"){

		}
		else if (ac == "SA") {

		}
	}
}



