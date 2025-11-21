#pragma once
#include <string>
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