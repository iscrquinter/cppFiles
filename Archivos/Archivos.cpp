// Archivos.cpp: define el punto de entrada de la aplicación de consola.
// http://courses.cs.vt.edu/~cs2604/fall00/binio.html

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Empleado
{
	char codigo[5];
	char nombre[21];
	int  edad;
};

Empleado e;

void menu();
void grabarUnEmpleado();
void leerUnEmpleado();

int main()
{
	menu();
	
	system("PAUSE");

    return 0;
}

void menu()
{
	char opc;
	do
	{
		system("CLS");
		cout << "MENU" << endl;
		cout << "====" << endl;
		cout << "1. Capturar empleados (memoria)" << endl;
		cout << "2. Grabar archivo de empleados (disco)" << endl;
		cout << "3. Leer archivo de empleados (disco)" << endl;
		cout << "4. Salir" << endl << endl;
		cout << "Opcion->";
		cin >> opc;
		getchar();

		switch (opc)
		{
			case '1':break;
			case '2':break;
			case '3':break;
		}

	} while (opc != '4');
}

void grabarUnEmpleado()
{
	ofstream myFile("empleados.dat", ios::out | ios::binary);

	cout << "Abriendo archivo..." << endl;

	if (myFile.is_open()) {
		cout << "Codigo:";
		cin.getline(e.codigo, 4);

		cout << "Nombre:";
		cin.getline(e.nombre, 20);

		cout << "Edad:";
		cin >> e.edad;

		cout << "Grabando información de empleado..." << endl;

		cout << "Apuntador antes de grabar: " << myFile.tellp() << endl;
		myFile.write((char *)&e, sizeof(e));
		cout << "Apuntador despues de grabar: " << myFile.tellp() << endl;
		getchar();

		myFile.close();
	}
	else
		cout << "Error de apertura del archivo ..." << endl;
}

void leerUnEmpleado()
{
	ifstream myFile("empleados.dat", ios::in | ios::binary);

	cout << "Abriendo archivo..." << endl;

	if (myFile.is_open()) {
		myFile.read((char*)&e, sizeof(e));

		cout << "Codigo:" << e.codigo << endl;
		cout << "Nombre:" << e.nombre << endl;
		cout << "Edad:" << e.edad << endl;

		myFile.close();
	}
	else
		cout << "Error de apertura del archivo ..." << endl;
}
