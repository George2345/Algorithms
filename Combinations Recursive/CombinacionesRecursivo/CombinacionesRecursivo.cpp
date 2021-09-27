#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 1) {
		return n;
	}
	else {
		return n * factorial(n - 1);
	}
}

int combinaciones(int n, int r) {
	return (factorial(n) / (factorial(r) * factorial(n - r)));
}

int main() {
	int n, r;
	cout << "Introduzca dos numeros: " << endl;
	do {
		cin >> n >> r;
		if (n < 0 || r < 0) {
			break;
		}
		else if (n < r) {
			cout << "ERROR" << endl;
		}
		else {
			cout << combinaciones(n, r) << endl;
		}
	} while (n >= 0 && r >= 0);
}