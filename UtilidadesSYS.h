#pragma once
//Realizado por Juan Pantaleon Femenia Quevedo y Carlos Garcia Tovar.

#ifndef UTILIDADESYS_H
#define UTILIDADESYS_H
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

typedef unsigned char uint8;  // Byte
//typedef unsigned short int usint; // entero pequeño sin signo

void chcp1252();
void borrar();
void pausa();

void colorCTA(uint8 color, uint8 fondo);

#endif

