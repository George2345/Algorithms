#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Matriz {
private:
	int dimension;
	double** matriz;
public:
	Matriz();
	Matriz(int dimension);
	~Matriz();
	void rellenarMatriz();
	void rellenarMatrizAleatorio();
	void imprimirMatriz();
	double calcularDeterminante();
};