#include <iostream>
#include <cstring>
#include "ListaEnlazada.h"
using namespace std;

ListaEnlazada::ListaEnlazada() {
	this->lista = NULL;
	this->n = 0;
}

ListaEnlazada::~ListaEnlazada() {
	while (n > 0) eliminar(0);
}

Nodo* ListaEnlazada::getNodo(int pos) {
	Nodo* resultado;
	resultado = this->lista;

	for (int i = 0; i < pos; i++) {
		resultado = resultado->siguienteNodo;
	}
	return resultado;
}

int ListaEnlazada::getValor(int pos) {
	Nodo* resultado = getNodo(pos);
	return resultado->elemento;
}

void ListaEnlazada::setValor(int pos, int val) {
	getNodo(pos)->elemento = val;
}

int ListaEnlazada::getN() {
	return this->n;
}

void ListaEnlazada::insertar(int pos, int val) {
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->elemento = val;

	if (pos == 0) {
		nuevoNodo->siguienteNodo = lista;
		lista = nuevoNodo;
	}
	else {
		Nodo* anterior = getNodo(pos - 1);
		nuevoNodo->siguienteNodo = anterior->siguienteNodo; 
		anterior->siguienteNodo = nuevoNodo;
	}
	n++;
}

void ListaEnlazada::eliminar(int pos) {
	Nodo* nodoAEliminar = NULL;

	if (pos == 0) {
		nodoAEliminar = lista;
		Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
		lista = nodoSiguiente;
	}
	else {
		Nodo* nodoAnterior = getNodo(pos - 1);
		nodoAEliminar = nodoAnterior->siguienteNodo;
		Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
		nodoAnterior->siguienteNodo = nodoSiguiente;
	}

	delete(nodoAEliminar);
	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada* listaAConcatenar) {
	for (int i = 0; i < listaAConcatenar->getN(); i++) {
		insertar(getN(), listaAConcatenar->getValor(i));
	}
}

int ListaEnlazada::buscar(int num) {
	for (int i = 0; i < getN(); i++) {
		if (getValor(i) == num) {
			return i;
		}
	}
	return -1;
}