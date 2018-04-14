// Archivos.cpp: define el punto de entrada de la aplicación de consola.
// http://courses.cs.vt.edu/~cs2604/fall00/binio.html

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Empleado
{
	char codigo[5];
	char nombre[21];
	int  edad;
};

struct Tabla
{
	Empleado e[10];
	int indx = 0;
};


Tabla t;

void menu();
void capturaEmpleados();
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
			case '1':capturaEmpleados();
					 break;
			case '2':break;
			case '3':break;
		}

	} while (opc != '4');
}

void capturaEmpleados()
{
	char opc='n';

	if (t.indx < 5)
	{

		do {
			system("CLS");
			cout << "CAPTURA DE EMPLEADOS (MEMORIA)" << endl;
			cout << "==============================" << endl;
			cout << "Empleado-" << t.indx+1 << endl;
			cout << "Codigo:";
			cin.getline(t.e[t.indx].codigo, 4);

			cout << "Nombre:";
			cin.getline(t.e[t.indx].nombre, 20);

			cout << "Edad:";
			cin >> t.e[t.indx].edad;

			cout << endl << "CATALOGO ACTUAL=>" << endl;

			for (int i = 0; i <= t.indx; i++)
			{
				cout << setw(5) << t.e[i].codigo << setw(21) << t.e[i].nombre << setw(10) << t.e[i].edad << endl;
			}

			t.indx++;

			if (t.indx == 5)
			{
				cout << "Tabla llena, no es posible capturar más empleados..." << endl;
				system("PAUSE");
			}
			else
			{
				cout << "Capturar otro empleado(S/N)? ";
				cin >> opc;
				getchar();
			}

		} while ((opc == 'S' or opc == 's') and (t.indx <5));
	}
	else
	{
		cout << "Tabla llena, no es posible capturar más empleados ..." << endl;
		system("PAUSE");
	}
}

/*
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

*/