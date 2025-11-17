#include "HashTable.h"

HashTable::HashTable(){
    this->size=0;
    this->sizeA=11;
    this->tabla = new LinkedList[this->sizeA];
}

HashTable::~HashTable(){
    delete[] this->tabla;
}

void HashTable::rehashing(){
    int oldSizeA = this -> sizeA;
    this -> sizeA = this -> sizeA * 2 + 1;
    LinkedList* oldTabla = this -> tabla;
    this -> tabla = new LinkedList[this -> sizeA];
    this -> size = 0;

    for(int i = 0; i < oldSizeA; i++){
        MyNodoLL* current = oldTabla[i].head;
        while(current != nullptr){
            int newPos = getPos(current -> key);
            this -> tabla[newPos].insertLast(current -> key, current -> value);
            this -> size++;
            current = current -> next;
        }
    }

    delete[] oldTabla;
}

int HashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

bool HashTable::isEmpty(){
    return this -> size == 0;
}

void HashTable::put(string key, int value){
    int position = getPos(key);
    MyNodoLL* current = this -> tabla[position].head;
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
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

int HashTable::get(string key){
    int position = getPos(key);
    return this -> tabla[position].getAt(key);
}

void HashTable::remove(string key){
    int pos = getPos(key);
    try {
        tabla[pos].removeAt(key);
        this->size--;
    } 
    catch (invalid_argument&) {
        throw; 
    }
}