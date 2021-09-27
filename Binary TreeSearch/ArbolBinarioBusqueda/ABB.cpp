#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

ABB::ABB() {
    this->n = 0;
    this->raiz = NULL;
}

void ABB::insertar(int nuevoElemento) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->contenido = nuevoElemento;
    nuevoNodo->padre = NULL;
    nuevoNodo->hijoIzquierdo = NULL;
    nuevoNodo->hijoDerecho = NULL;

    if (n == 0) {
        raiz = nuevoNodo;
    }
    else {
        Nodo* padreDelHueco = buscarHueco(raiz, nuevoElemento);
        
        if (nuevoElemento <= padreDelHueco->contenido) padreDelHueco->hijoIzquierdo = nuevoNodo;
        else padreDelHueco->hijoDerecho = nuevoNodo;

        nuevoNodo->padre = padreDelHueco;
    }
    n++;
}

Nodo* ABB::buscar(int elementoABuscar) {
    return buscarRecursivo(raiz, elementoABuscar);
}

void ABB::eliminar(int elementoAEliminar) {
    Nodo* nodoParaEliminar = buscar(elementoAEliminar);
    eliminarNodo(nodoParaEliminar);
    n--;
}

void ABB::imprimir()
{
    if (raiz == NULL)
        cout << "VACIO" << endl;
    else
        imprimirRecorrido(raiz);
}

ABB::~ABB() {
    if (raiz != NULL) eliminarSubarbol(raiz);
}

bool ABB::esABB() {
    return esSubABB(raiz);
}

bool ABB::esAVL() {
    return esSubAVL(raiz);
}


void ABB::eliminarSubarbol(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);

    if (raizSubarbol->hijoIzquierdo != NULL) eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    if (raizSubarbol->hijoDerecho != NULL) eliminarSubarbol(raizSubarbol->hijoDerecho);

    Nodo* padre = raizSubarbol->padre;
    if (padre != NULL) {
        if (padre->hijoIzquierdo == raizSubarbol) padre->hijoIzquierdo = NULL;
        if (padre->hijoDerecho == raizSubarbol) padre->hijoDerecho = NULL;
    }

    delete raizSubarbol;
}

Nodo* ABB::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar) {
    assertdomjudge(raizSubarbol != NULL);

    if (elementoAInsertar <= raizSubarbol->contenido) {
        if (raizSubarbol->hijoIzquierdo != NULL) {
            return (buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar));
        }
        else {
            return raizSubarbol;
        }
    }
    else {
        if (raizSubarbol->hijoDerecho != NULL) {
            return (buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar));
        }
        else {
            return raizSubarbol;
        }
    }
}

Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
    if (raizSubarbol == NULL) {
        return NULL;
    }
    else {
        if (elementoABuscar == raizSubarbol->contenido) {
            return raizSubarbol;
        }
        else if (elementoABuscar < raizSubarbol->contenido) {
            return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
        }
        else {
            return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
        }
    }
}

Nodo* ABB::buscarMaximo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);

    if (raizSubarbol->hijoDerecho != NULL) {
        return buscarMaximo(raizSubarbol->hijoDerecho);
    }
    else {
        return raizSubarbol;
    }
}

Nodo* ABB::buscarMinimo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);

    if (raizSubarbol->hijoIzquierdo != NULL) {
        return buscarMaximo(raizSubarbol->hijoIzquierdo);
    }
    else {
        return raizSubarbol;
    }
}

void ABB::eliminarNodo(Nodo* nodoAEliminar) {

    Nodo* nodoAux = NULL;
    
    if (nodoAEliminar != NULL) {
        //No tenemos hijos
        if (nodoAEliminar->hijoIzquierdo == NULL && nodoAEliminar->hijoDerecho == NULL) {
            Nodo* padre = nodoAEliminar->padre;
            if (padre != NULL) {
                if (padre->hijoIzquierdo == nodoAEliminar) padre->hijoIzquierdo = NULL;
                if (padre->hijoDerecho == nodoAEliminar) padre->hijoDerecho = NULL;
            }

            delete nodoAEliminar;
        }
        else {
            //Tenemos dos hijos
            if (nodoAEliminar->hijoIzquierdo != NULL && nodoAEliminar->hijoDerecho != NULL) {
                int alturaHijoI = alturaNodo(nodoAEliminar->hijoIzquierdo);
                int alturaHijoD = alturaNodo(nodoAEliminar->hijoDerecho);

                if (alturaHijoD > alturaHijoI) {
                    nodoAux = buscarMinimo(nodoAEliminar->hijoDerecho);
                }
                else {
                    nodoAux = buscarMaximo(nodoAEliminar->hijoIzquierdo);
                }
            }
            //Tenemos el hijo derecho
            else if (nodoAEliminar->hijoIzquierdo == NULL && nodoAEliminar->hijoDerecho != NULL) {
                nodoAux = buscarMinimo(nodoAEliminar->hijoDerecho);
            }
            //Tenemos el hijo izquierdo
            else if (nodoAEliminar->hijoIzquierdo != NULL && nodoAEliminar->hijoDerecho == NULL) {
                nodoAux = buscarMaximo(nodoAEliminar->hijoIzquierdo);
            }

            nodoAEliminar->contenido = nodoAux->contenido;
            eliminarNodo(nodoAux);
        }
    }
}

int ABB::alturaNodo(Nodo* raizSubarbol) {;

    if (raizSubarbol == NULL) {
        return 0;
    }
    else {
        int alturaHijoI = alturaNodo(raizSubarbol->hijoIzquierdo);
        int alturaHijoD = alturaNodo(raizSubarbol->hijoDerecho);
        int max = 0;
        if (alturaHijoD > alturaHijoI) max = alturaHijoD;
        else max = alturaHijoD;

        return max + 1;
    }
}

//No he sabido hacer estos dos metodos
bool ABB::esSubABB(Nodo* raizSubarbol) {
    return true;
}

bool ABB::esSubAVL(Nodo* raizSubArbol) {
    return false;
}

void ABB::imprimirRecorrido(Nodo* raizSubarbol)
{
    cout << raizSubarbol->contenido << endl;
    if (raizSubarbol->hijoIzquierdo != NULL)
    {
        cout << "I";
        imprimirRecorrido(raizSubarbol->hijoIzquierdo);
        cout << endl;
    }
    if (raizSubarbol->hijoDerecho != NULL)
    {
        cout << "D";
        imprimirRecorrido(raizSubarbol->hijoDerecho);
        cout << endl;
    }
}

void ABB::leerArbol()
{
    raiz = leerSubarbol(NULL);
}

Nodo* ABB::leerSubarbol(Nodo* padre)
{
    int contenido;
    cin >> contenido;
    if (contenido >= 0)
    {
        Nodo* arbol = new Nodo;
        arbol->contenido = contenido;
        arbol->hijoIzquierdo = leerSubarbol(arbol);
        arbol->hijoDerecho = leerSubarbol(arbol);
        arbol->padre = padre;
        return arbol;
    }
    else
    {
        return NULL;
    }
}
