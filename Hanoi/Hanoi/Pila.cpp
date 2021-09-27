#include"Pila.h"

Pila::Pila(string name) {
    this->cima = NULL;
    this->name = name;
}

string Pila::nombrePila()
{
    return this->name;
}

void Pila::apilar(int num)
{
    Nodo* nuevoNodo = new Nodo(num, NULL);
    if (estaVacia() == true) {
        cima = nuevoNodo;
    }
    else {
        Nodo* nodoAnterior = cima;
        nuevoNodo->siguiente = nodoAnterior;
        cima = nuevoNodo;
    }
    cout << "Apilando disco " << num << " en poste " << name << endl;
}

int Pila::desapilar()
{
    Nodo* nodoAEliminar = cima;
    int aux = nodoAEliminar->valor;
    if (cima == NULL) {
        cout << "No hay elementos para desapilar" << endl;
        return NULL;
    }
    else if (nodoAEliminar->siguiente != NULL) {
        cima = nodoAEliminar->siguiente;
    }
    cout << "Desapilando disco " << aux << " del poste " << name << endl;
    delete nodoAEliminar;
    return aux;
}

bool Pila::estaVacia()
{
    if (cima != NULL) {
        return false;
    }
    return true;
}
