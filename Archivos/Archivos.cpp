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

int main()
{
	fstream myFile("empleados.dat", ios::in | ios::out | ios::binary);

	cout << "Codigo:";
	cin.getline(e.codigo, 4);

	cout << "Nombre:";
	cin.getline(e.nombre, 20);

	cout << "Edad:";
	cin >> e.edad;

	cout << "Grabando información de empleado..." << endl;
	myFile.write((char *)&e, sizeof(e));

	myFile.close();

	system("PAUSE");

    return 0;
}

