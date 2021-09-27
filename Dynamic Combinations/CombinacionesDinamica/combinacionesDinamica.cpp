#include <iostream>
using namespace std;

void resolver(int **triangulo, int linea) {
    
    if (linea == 1) {
        triangulo[0][0] = 1;
        triangulo[1][0] = 1;
        triangulo[1][1] = 1;
    }
    else {
        resolver(triangulo, linea - 1);
        
    }

}

int main() {
    int n1, n2;
    int** triangulo = new int* [10];
	do {
		cin >> n1 >> n2;
		if (n1 < 0 || n2 < 0) {
			break;
		}
		else if (n2 > n1) {
			cout << "ERROR" << endl;
		}
        else {
            resolver(triangulo, n1);
        }
	} while (n1 >= 0 || n2 >= 0);


	return 0;
}