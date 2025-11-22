//Actividad Integradora 5.2
//Diego Israel Dominguez Najera A01782831
//Andrea Marlene Ramos Tiscareño A01646342
//Samuel Rodriguez Torres A01637408
//21 de Noviembre del 2025

#pragma once
#include <string>
#include <stdexcept>
#include "LinkedList.h" 
using namespace std;

class HashTable {
    private:
        LinkedList* tabla;
        int size;
        int sizeA;
        void rehashing();
        int getPos(string key);
    public:
        HashTable(); 
        ~HashTable();
        bool isEmpty();
        void put(string key, string value);
        vector<string> get(string key);
        void remove(string key);
};