#include <iostream>
using namespace std;

const int TAM_LISTA = 24;
const int TAM_PALABRA = 25;

void agregarPalabra(char** lista, int longitud);

int main() {
    // Crear la lista de palabras vacía
    char** lista = new char*[TAM_LISTA];
    for (int i = 0; i < TAM_LISTA; i++) {
        lista[i] = new char[TAM_PALABRA];
        lista[i][0] = '\0';
    }

    // Pedir el número de palabras que se van a ingresar
    int numPalabras = 0;
    while (numPalabras <= 0 || numPalabras > TAM_LISTA) {
        cout << "Ingrese el número de palabras a ingresar (entre 1 y " << TAM_LISTA << "): ";
        cin >> numPalabras;
    }

    // Pedir las palabras al usuario y agregarlas a la lista
    for (int i = 0; i < numPalabras; i++) {
        agregarPalabra(lista, TAM_LISTA);
    }

    // Imprimir la lista de palabras
    cout << endl << "Lista de palabras:" << endl;
    for (int i = 0; i < TAM_LISTA; i++) {
        cout << "Posición " << i << ": ";
        if (lista[i][0] == '\0') {
            cout << "(vacío)";
        } else {
            cout << lista[i];
        }
        cout << endl;
    }

    // Liberar la memoria reservada para la lista
    for (int i = 0; i < TAM_LISTA; i++) {
        delete[] lista[i];
    }
    delete[] lista;

    return 0;
}

void agregarPalabra(char** lista, int longitud) {
    // Pedir la posición donde se guardará la palabra
    int posicion = -1;
    while (posicion < 0 || posicion >= longitud || lista[posicion][0] != '\0') {
        cout << "Ingrese la posición donde se guardará la palabra (entre 0 y " << longitud-1 << "): ";
        cin >> posicion;
        cin.ignore();

        if (lista[posicion][0] != '\0') {
            cout << "Esa posición ya está ocupada. Por favor ingrese otra." << endl;
        }
    }

    // Pedir la palabra al usuario
    char palabra[TAM_PALABRA];
    cout << "Ingrese la palabra: ";
    cin.getline(palabra, TAM_PALABRA);

    // Copiar la palabra en la lista
    int i = 0;
    while (i < TAM_PALABRA && palabra[i] != '\0') {
        lista[posicion][i] = palabra[i];
        i++;
    }
    lista[posicion][i] = '\0';
}
