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
void grabarEmpleados();
void leerEmpleados();
void limpiarEmpleados();
int  totEmpleadosDisk();

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

		cout << "*" << t.indx << " empleado(s) en memoria ..." << endl;
		cout << "*" << totEmpleadosDisk() << " empleado(s) en disco ..." << endl << endl;
		cout << "MENU" << endl;
		cout << "====" << endl;
		cout << "1. Capturar empleados (MEMORIA)" << endl;
		cout << "2. Guardar archivo de empleados (MEMORIA->DISCO)" << endl;
		cout << "3. Cargar archivo de empleados (DISCO->MEMORIA)" << endl;
		cout << "4. Limpiar tabla de empleados (MEMORIA)" << endl << endl;
		cout << "5. Salir" << endl << endl;
		
		cout << "Opcion->";
		cin >> opc;
		getchar();

		switch (opc)
		{
			case '1':capturaEmpleados();
				     break;
			case '2':grabarEmpleados();
					 break;
			case '3':leerEmpleados();
					 break;
			case '4':limpiarEmpleados();
					 break;
		}

	} while (opc != '5');
}

void capturaEmpleados()
{
	char opc='n';

	if (t.indx < 5)
	{

		do {
			system("CLS");
			cout << "CAPTURA DE EMPLEADOS (EN MEMORIA)" << endl;
			cout << "=================================" << endl;
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


void grabarEmpleados()
{
	ofstream myFile("empleados.dat", ios::out | ios::binary);

	system("CLS");

	cout << "GUARDADO DE EMPLEADOS (MEMORIA->DISCO)" << endl;
	cout << "======================================" << endl << endl;

	if (myFile.is_open()) {

		cout << "Guardando empleados al disco ..." << endl;
		myFile.write((char *)&t, sizeof(t));
		cout << "Se han guardado " << myFile.tellp() << " bytes de informacion de empleados al disco..." << endl;

		myFile.close();
		cout << "Listo!" << endl;
	}
	else
		cout << "Error de apertura del archivo ..." << endl;
	system("PAUSE");
}

void leerEmpleados()
{
	ifstream myFile("empleados.dat", ios::in | ios::binary);

	system("CLS");

	cout << "Cargando empleados del disco a memoria..." << endl;

	if (myFile.is_open()) {
		myFile.read((char*)&t, sizeof(t));
		cout << "Listo!" << endl;

		cout << "CATALOGO DE EMPLEADOS (DISCO->MEMORIA)" << endl;
		cout << "======================================" << endl;

		for (int i = 0; i < t.indx; i++)
		{
			cout << setw(5) << t.e[i].codigo << setw(21) << t.e[i].nombre << setw(10) << t.e[i].edad << endl;
		}

		myFile.close();
	}
	else
		cout << "Error de apertura del archivo ..." << endl;

	system("PAUSE");
}

void limpiarEmpleados()
{
	system("CLS");

	cout << "Limpiando tabla de empleados en memoria ..." << endl;

	t.indx = 0;

	cout << "Listo!" << endl;
	system("PAUSE");
}

int totEmpleadosDisk()
{
	Tabla t;
	ifstream myFile("empleados.dat", ios::in | ios::binary);

	if (myFile.is_open()) {
		myFile.read((char*)&t, sizeof(t));
		myFile.close();
		return t.indx;
	}
	else
		return 0;
}
