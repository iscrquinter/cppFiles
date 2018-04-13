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

		myFile.close();
	}
	else
		cout << "Error de apertura del archivo ..." << endl;
	
	system("PAUSE");

    return 0;
}

