#pragma once
#include <vector>
#include <string>
#include "HashTable.h"
using namespace std;



class Bitacora {
    private:
        vector<string> ips;
        vector<vector<int>> fechas;
        vector<int> indices_ordenados;
        HashTable tabla_frecuencias;
        // Método ordenamiento
        bool comparar(int valor_1 , int valor_2);
        vector<int> merge(const vector<int>& izq,const vector<int>& der);
        vector<int> mergeSort(const vector<int>& indices);
        void mergeSort();
    public:
        Bitacora(vector<string> l);
        void crear_hashtable();
        void insertar_frecuencia(int indice);
        void imprimir_frecuencias(string ip_solicitada);
};