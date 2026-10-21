// EJERCICIOS-CLASE4-FELIX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


	struct Nodo {
		int dato;
		Nodo* siguiente;
			
	};
	
	void insertarInicio(Nodo* &lista, int Valor) {
			Nodo* nuevo = new Nodo();
			nuevo->dato = Valor;
			nuevo->siguiente = lista;
			lista = nuevo;
	}

	void insertarFinal(Nodo*& lista, int Valor) {
		Nodo* nuevo = new Nodo();
		nuevo->dato = Valor;
		nuevo->siguiente = NULL;
		if (lista == NULL) {
			lista = nuevo;
		}
		else {
			Nodo* auxiliar = lista;
			while (auxiliar->siguiente != NULL) {
				auxiliar = auxiliar->siguiente;
			}
			auxiliar->siguiente = nuevo;
		}
	}

	void mostrarlista(Nodo* lista) {
		cout<< "La lista es: ";
		while (lista!= NULL) {
			cout << lista->dato << "->"; 
			lista = lista->siguiente;
		}
		cout << "NULL" << endl;
	}

	void eliminarNodo(Nodo*& lista, int valor) {
		if (lista == NULL) {
			return;
		}
		Nodo* auxiliar = lista; 
		Nodo* anterior = NULL; 

		while (auxiliar != NULL && auxiliar->dato != valor) {
			anterior = auxiliar;
			auxiliar = auxiliar->siguiente;
		}
		if (auxiliar == NULL){
			cout << "Valor no encontrado" << endl;
		return;
		}
		if (anterior == NULL) {
			lista = lista->siguiente;
		}
		else {
			anterior->siguiente = auxiliar->siguiente;
		}
		delete auxiliar;
		cout<< "Elemento eliminado" << endl;
	}


	bool buscar(Nodo* lista, int valor) {
		Nodo* actual = lista;
		while (actual != NULL) {
			if (actual->dato == valor) {
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

int main ()
{
	Nodo* lista = NULL;

	insertarInicio(lista, 5);
	insertarInicio(lista, 7);
	insertarInicio(lista, 6);
	insertarInicio(lista, 4);
	insertarInicio(lista, 3);
	insertarInicio(lista, 1);

	insertarFinal(lista, 8);

	mostrarlista(lista);

	cout << "Buscar el dato 5"
		<< (buscar(lista, 5) ? "Encontrado" : "No Encontrado")
		<< endl;

	eliminarNodo(lista, 5);
	insertarFinal(lista, 9);
	mostrarlista(lista);

	return 0;
}
	