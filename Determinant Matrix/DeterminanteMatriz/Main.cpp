#include "Matriz.h"

int main() {
	int dimension;
	char opcion = NULL;
	cout << "Dimension de la matriz cuadrada: ";
	cin >> dimension;
	Matriz matriz(dimension);
	cout << "Rellenar manual o aleatorio (m/a): ";
	cin >> opcion;
	switch (opcion)
	{
	case 'm':
		matriz.rellenarMatriz();
		break;
	case 'a':
		matriz.rellenarMatrizAleatorio();
		matriz.imprimirMatriz();
		break;
	default:
		cout << "Seleccione una opcion!" << endl;
		break;
	}
	cout << "Determinante: " << matriz.calcularDeterminante();

	return 0;
}