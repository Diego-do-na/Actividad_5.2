//Actividad Integradora 5.2
//Diego Israel Dominguez Najera A01782831
//Andrea Marlene Ramos Tiscareño A01646342
//Samuel Rodriguez Torres A01637408
//21 de Noviembre del 2025

#include "HashTable.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

//Complejidad: O(1)
HashTable::HashTable(){
    this->size = 0;
    this->sizeA = 601;
    this->tabla = new LinkedList[this->sizeA];
}

//Complejidad: O(1)
HashTable::~HashTable(){
    delete[] this->tabla;
}

//Complejidad: O(n)
void HashTable::rehashing(){
    int oldSizeA = this -> sizeA;
    this -> sizeA = this -> sizeA * 2 + 1;
    LinkedList* oldTabla = this -> tabla;
    this -> tabla = new LinkedList[this -> sizeA];
    this -> size = 0;

    for(int i = 0; i < oldSizeA; i++){
        NodoLL* current = oldTabla[i].head;
        while(current != nullptr){
            int newPos = getPos(current -> ip);
            this -> tabla[newPos].insertLast(current -> ip, current -> visitas);
            this -> size++;
            current = current -> next;
        }
    }

    delete[] oldTabla;
}

//Complejidad: O(1)
int HashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

// Para el mejor entendimiento de las hash tables, recurri a los siguientes videos:
// Chio Code. (2025, February 10). Entiende por fin el Hashing y las Tablas Hash | Estructuras de Datos [Video]. YouTube. https://www.youtube.com/watch?v=CrXDTPE4DQI
// Coding Jesus (getcracked.io). (2019, October 14). C++ Hash Table Implementation [Video]. YouTube. https://www.youtube.com/watch?v=2_3fR-k-LzI

bool HashTable::isEmpty(){
    return this -> size == 0;
}

//Complejidad: O(1)
void HashTable::put(string key, string value){
    int position = getPos(key);
    NodoLL* current = this -> tabla[position].head;
    while (current != nullptr) {
        if (current->ip == key) {
            current->visitas.push_back(value);
            return;
        }
        current = current->next;
    }
    this -> tabla[position].insertLast(key, value);
    this -> size++;

    if ((this -> size * 1.0) / this -> sizeA > 0.75) {
        rehashing();
    }
}

//Complejidad: O(1)
vector<string> HashTable::get(string key){
    int position = getPos(key);
    return this -> tabla[position].getAt(key);
}

// Complejidad: O(1)
void HashTable::remove(string key){
    int pos = getPos(key);
    try {
        tabla[pos].removeAt(key);
        this->size--;
    } 
    catch (invalid_argument&) {
        throw invalid_argument("La clave no existe en la tabla."); 
    }
}