//Actividad Integradora 5.2
//Diego Israel Dominguez Najera A01782831
//Andrea Marlene Ramos Tiscareño A01646342
//Samuel Rodriguez Torres A01637408
//21 de Noviembre del 2025

#include "Bitacora.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <ctype.h>
using namespace std;

//Complejidad: O(n log n)
Bitacora::Bitacora(vector<string> l){
    const string meses[] = {"jan","feb","mar","apr","may","jun", "jul","aug","sep","oct","nov","dec"};

    for (string line : l) {

        string mes_str, ip_puerto;
        int dia, hora, minuto, segundo;
        char c1, c2;

        stringstream ss(line);

        ss >> mes_str >> dia >> hora >> c1 >> minuto >> c2 >> segundo >> ip_puerto;

        if (ss.fail()) {
            continue;
        }

        for (char &c : mes_str) c = tolower(c);

        int mes = 0;
        for (int i = 0; i < 12; i++) {
            if (mes_str == meses[i]) {
                mes = i + 1;
                break;
            }
        }

        if (mes == 0) {
            continue;
        }

        string ip = ip_puerto.substr(0, ip_puerto.find(":"));

        vector<int> datos = {mes, dia, hora, minuto, segundo};

        fechas.push_back(datos);
        ips.push_back(ip);
    }
}

//Complejidad: O(1)
bool Bitacora::comparar(int valor_1 , int valor_2 ){
    for (int i = 0; i < 5; i++) {
        if (fechas[valor_1][i] != fechas[valor_2][i]) {
            return fechas[valor_1][i] < fechas[valor_2][i];
        }
    }
    return false;
}

//Complejidad: O(n)
vector<int> Bitacora::merge(const vector<int>& izq,const vector<int>& der) {
    vector<int> resultado;
    int i = 0;
    int j = 0;

    while (i < izq.size() && j < der.size()) {
        if (comparar(izq[i], der[j])) {
            resultado.push_back(izq[i]);
            i++;
        }
        else {
            resultado.push_back(der[j]);
            j++;
        }
    }

    while (i < izq.size()) {
        resultado.push_back(izq[i]);
        i++;
    }
    while (j < der.size()) {
        resultado.push_back(der[j]);
        j++;
    }

    return resultado;
}

//Complejidad: O(n log n)
vector<int> Bitacora::mergeSort(const vector<int>& indices) {
    if (indices.size() <= 1) {
        return indices;
    }

    int mitad = indices.size() / 2;
    vector<int> izq(indices.begin(), indices.begin() + mitad);
    vector<int> der(indices.begin() + mitad, indices.end());

    izq = mergeSort(izq);
    der = mergeSort(der);

    return merge(izq, der);
}

void Bitacora::mergeSort() {
    vector<int> indices(fechas.size());

    for (int i = 0; i < fechas.size(); i++) {
        indices[i] = i;
    }

    indices_ordenados = mergeSort(indices);
}

//Complejidad: O(1)
void Bitacora::insertar_frecuencia(int indice) {
    string ip = ips[indice];

    const string meses[] = {"Jan","Feb","Mar","Apr","May","Jun", "Jul","Aug","Sep","Oct","Nov","Dec"};

    int mes = fechas[indice][0];
    int dia = fechas[indice][1];
    int hora = fechas[indice][2];
    int minuto = fechas[indice][3];
    int segundo = fechas[indice][4];

    string h = to_string(hora);
    string m = to_string(minuto);
    string s = to_string(segundo);

    if (hora < 10) h = "0" + h;
    if (minuto < 10) m = "0" + m;
    if (segundo < 10) s = "0" + s;

    string fecha = meses[mes - 1] + " " + to_string(dia) + " " +h + ":" + m + ":" + s;

    tabla_frecuencias.put(ip, fecha);
}

//Complejidad: O(n log n)
void Bitacora::crear_hashtable() {
    if (indices_ordenados.empty()) {
        mergeSort();
    }

    for (int i = 0; i < indices_ordenados.size(); i++) {
        int indice_real = indices_ordenados[i];
        insertar_frecuencia(indice_real);
    }
}

//Complejidad: O(k), donde k es el número de visitas para la IP solicitada
void Bitacora::imprimir_frecuencias(string ip_solicitada) {
    vector <string> fechas_solicitadas = tabla_frecuencias.get(ip_solicitada);
    if (fechas_solicitadas.size() == 0) {
        cout << ip_solicitada << endl;
        cout << "No se encontraron visitas para la IP solicitada." << endl;
    } 
    else {
        cout << "\n" << ip_solicitada << "\n" << endl;
        for (string fecha : fechas_solicitadas) {
            cout << fecha << endl;
        }
    }
}