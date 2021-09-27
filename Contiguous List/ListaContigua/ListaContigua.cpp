#include "ListaContigua.h"
#include <cstdlib>
#include <cstring>

ListaContigua::ListaContigua(int incremento) {
	this->n = 0;
	this->capacidad = incremento;
	this->incremento = incremento;
	this->vector = new int[capacidad];
}

ListaContigua::~ListaContigua() {
	delete[] this->vector;
}

int ListaContigua::getValor(int pos) {
	return this->vector[pos];
}

void ListaContigua::setValor(int pos, int val) {
	this->vector[pos] = val;
}

int ListaContigua::getN() {
	return n;
}

int ListaContigua::getCapacidad() {
	return capacidad;
}

void ListaContigua::insertar(int pos, int val) {
	if (getN() == getCapacidad()) {
		vector = (int*)realloc(vector, sizeof(int) * (capacidad + incremento));
		capacidad += incremento;
	}

	memmove(&vector[pos + 1], &vector[pos], sizeof(int) * (n - pos));
	n++;
	setValor(pos, val);
}

void ListaContigua::eliminar(int pos) {
	memmove(&vector[pos], &vector[pos + 1], sizeof(int) * (n - pos - 1));
	n--;

	if (capacidad - n == 2 * incremento) {
		vector = (int*)realloc(vector, sizeof(int) * (capacidad - incremento));
		capacidad -= incremento;
	}
}

int ListaContigua::buscar(int elementoABuscar) {
	for (int i = 0; i < n; i++) {
		if (elementoABuscar == vector[i]) {
			return i;
		}
	}
	return -1;
}

void ListaContigua::concatenar(ListaContigua* listaAConcatenar) {
	int m = listaAConcatenar->getN();
	vector = (int*)realloc(vector, sizeof(int) * (capacidad + m));
	capacidad += m;
	for (int i = 0; i < m; i++) {
		insertar(getN(), listaAConcatenar->getValor(i));
	}
}