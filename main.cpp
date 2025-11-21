#include "Bitacora.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> lineas;
    string linea;
    ifstream archivoEntrada("bitacora3.txt");
    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo bitacora.txt" << endl;
        return 1;
    }

    while (getline(archivoEntrada, linea)) {
        lineas.push_back(linea);
    }
    archivoEntrada.close();

    Bitacora prueba(lineas);
    prueba.crear_hashtable();

    cout << "------------------------------------------------" << endl;
    cout << "PROGRAMA DE CONSULTA DE FRECUENCIAS DE IPs" << endl;
    cout << "------------------------------------------------" << endl;
    bool continuar = true;
    while (continuar){
        string ip_solicitada;
        cout << "\nIngrese la IP que desea consultar: " << endl;
        cin >> ip_solicitada;
        prueba.imprimir_frecuencias(ip_solicitada);
        cout << "\n¿Desea consultar otra IP? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 's' && respuesta != 'S') {
            continuar = false;
        }
    }
}