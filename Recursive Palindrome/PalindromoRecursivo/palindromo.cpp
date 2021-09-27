#include <iostream>
using namespace std;

int esPalindromo(char* palabra, int indiceInicio, int indiceFin) {
	if (indiceInicio >= indiceFin) {
		return 1;
	}
	if (palabra[indiceInicio] == palabra[indiceFin]) {
		return esPalindromo(palabra, indiceInicio + 1, indiceFin - 1);
	}
	else {
		return 0;
	}
}

int main() {
	char *palabra = new char[100];
	cout << "Escriba una palabra: ";
	cin >> palabra;
	int longitudCadena = strlen(palabra);
	while (longitudCadena > 20) {
		cout << "Error. La cadena no puede tener mas de 20 caracteres";
		cout << "Escriba una palabra: ";
		cin >> palabra;
		longitudCadena = strlen(palabra);
	}
	cout << esPalindromo(palabra, 0, longitudCadena - 1);
	return 0;
}