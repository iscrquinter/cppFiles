// Archivos.cpp: define el punto de entrada de la aplicación de consola.
//

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

void grabarUnEmpleado();
void leerUnEmpleado();

int main()
{
	grabarUnEmpleado();
	leerUnEmpleado();
	
	system("PAUSE");

    return 0;
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
