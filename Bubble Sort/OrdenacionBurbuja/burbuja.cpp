#include <iostream>
using namespace std;

void imprimir(int* numeros, int elementos) {
	for (int i = 0; i < elementos; i++) {
		cout << numeros[i] << " ";
	}
}

void ordenarBurbuja(int* numeros, int cantidad) {
	int aux;
	cout << endl;
	for (int i = 1; i < cantidad; i++) {
		for (int j = 0; j < cantidad - 1; j++) {
			if (numeros[j] > numeros[j+1]) {
				aux = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = aux;
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
	ordenarBurbuja(numeros, cantidadElementos);

	return 0;
}