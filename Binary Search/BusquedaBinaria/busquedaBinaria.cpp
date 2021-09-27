#include <iostream>
using namespace std;

int busquedaBinaria(int* numeros, int elementos, int dato) {
	int sup = elementos, inf = 0, mitad, i = 0;
	mitad = (sup + inf) / 2;
	while ((inf <= sup) && (i < elementos)) {
		if (numeros[mitad] == dato) {
			return mitad;
		}
		else if (numeros[mitad] < dato) {
			inf = mitad;
			mitad = (sup + inf) / 2;
		}
		else if (numeros[mitad] > dato) {
			sup = mitad;
			mitad = (sup + inf) / 2;
		}
		i++;
	}
	return -1;
}

int main() {
	int numeroElementos, buscar, posicion, *numeros;
	cout << "Introduce el numero de elementos de la lista: ";
	cin >> numeroElementos;
	numeros = new int[numeroElementos];
	cout << "Introduce los numeros de la lista ordenados: " << endl;
	for (int i = 0; i < numeroElementos; i++) {
		cin >> numeros[i];
	}
	do {
		cout << "Numero a buscar: ";
		cin >> buscar;
		if (buscar == -1) {
			break;
		}
		posicion = busquedaBinaria(numeros, numeroElementos, buscar);
		cout << posicion << endl;
	} while (buscar != -1);

	return 0;
}