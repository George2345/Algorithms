#include "Matriz.h"

Matriz::Matriz() {
	this->dimension = 0;
	this->matriz = NULL;
}

Matriz::Matriz(int dimension) {
	this->dimension = dimension;
	this->matriz = new double* [this->dimension];
	for (int i = 0; i < this->dimension; i++) {
		this->matriz[i] = new double[this->dimension];
	}
}

Matriz::~Matriz() {
	for (int i = 0; i < this->dimension; i++) {
		delete[] this->matriz[i];
	}
	delete[] this->matriz;
}

void Matriz::rellenarMatriz() {
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < this->dimension; j++) {
			cin >> this->matriz[i][j];
		}
	}
}

void Matriz::rellenarMatrizAleatorio() {
	srand(time(NULL));
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < this->dimension; j++) {
			this->matriz[i][j] = rand() % 10;
		}
	}
}

void Matriz::imprimirMatriz() {
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < this->dimension; j++) {
			cout << this->matriz[i][j] << " ";
		}
		cout << endl;
	}
}

double Matriz::calcularDeterminante() {
	double determinante = 0.0;
	int m_j;
	if (this->dimension == 2) {
		return matriz[0][0]*matriz[1][1] - matriz[1][0]*matriz[0][1];
	}
	else {
		for (int i = 0; i < this->dimension; i++) {
			Matriz menor(this->dimension - 1);
			for (int m_i = 0; m_i < this->dimension - 1; m_i++) {
				m_j = 0;
				for (int j = 0; j < this->dimension; j++) {
					if (j != i) {
						menor.matriz[m_i][m_j] = matriz[m_i + 1][j];
						m_j++;
					}
				}
			}
			determinante += pow(-1, 2 + i) * matriz[0][i] * menor.calcularDeterminante();
		}
	}
	return determinante;
}