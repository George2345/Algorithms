#include <iostream>
using namespace std;

void imprimir(int* numeros, int elementos) {
	for (int i = 0; i < elementos; i++) {
		cout << numeros[i] << " ";
	}
}

void intercambiar(int* numeros, int i, int j) {
	int aux = numeros[i];
	numeros[i] = numeros[j];
	numeros[j] = aux;
}

void ordenarSeleccion(int* numeros, int cantidad) {
	cout << endl;
	for (int i = 0; i < cantidad; i++) {
		for (int j = i + 1; j < cantidad; j++) {
			if (numeros[i] > numeros[j]) {
				intercambiar(numeros, i, j);
			}
		}
		imprimir(numeros, cantidad);
		cout << endl;
	}
}

int main() {
	int cantidadElementos, num;
	int* numeros;
	cout << "Cantidad de enteros a introducir: ";
	cin >> cantidadElementos;
	numeros = new int[cantidadElementos];
	cout << "Introduce los numeros de la lista: " << endl;
	for (int i = 0; i < cantidadElementos; i++) {
		cin >> num;
		numeros[i] = num;
	}
	ordenarSeleccion(numeros, cantidadElementos);

	return 0;
}