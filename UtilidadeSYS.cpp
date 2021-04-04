#include "UtilidadesSYS.h"
#include <iostream>
#include <Windows.h>
using namespace std;


void chcp1252()
{
	system("chcp 1252");
}

void borrar()
{
	system("cls");
}

void pausa()
{
	system("pause");
}

 
uint8 colores[10] = { 0, 12, 10, 9, 14, 13, 3, 15, 8, 11 };
// negro(0), rojo(12), verde(10), azul(9), amarillo(14), magenta(13), cian2(3), blanco(15), gris(8), cian1(11) 

void colorCTA(uint8 color, uint8 fondo)  // fondo es un dígito
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (colores[fondo] << 4));
}



