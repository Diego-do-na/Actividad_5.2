//Actividad Integradora 5.2
//Diego Israel Dominguez Najera A01782831
//Andrea Marlene Ramos Tiscareño A01646342
//Samuel Rodriguez Torres A01637408
//21 de Noviembre del 2025

#include "LinkedList.h"
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;

//Complejidad: O(1)
LinkedList::LinkedList(){
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
}

//Complejidad: O(n)
LinkedList::~LinkedList(){
    NodoLL* current = this -> head;
    while(current != nullptr){
        NodoLL* nvo = current;
        current = current -> next;
        delete nvo;
    }
}

//Complejidad: O(1)
bool LinkedList::isEmpty(){
    return this -> size == 0;
}

//Complejidad: O(n)
vector<string> LinkedList::getAt(string ip){
    NodoLL* current = this -> head;
    while(current != nullptr){
        if (current -> ip == ip){
            return current -> visitas;
        }
        current = current -> next;
    }
    throw invalid_argument("No se encontro la clave");
}

//Complejidad: O(1)
void LinkedList::insertLast(string ip, string value){
    vector<string> visitas;
    visitas.push_back(value);
    NodoLL* nvo = new NodoLL(ip, visitas);
    if (this -> size == 0){
        this -> head = nvo;
        this -> tail = nvo;
    }
    else {
        this -> tail -> next = nvo;
        this -> tail = nvo;
    }
    this -> size++;
}

//Complejidad: O(1)
void LinkedList::insertLast(string ip, vector<string> visitas){
    NodoLL* nvo = new NodoLL(ip, visitas);
    if (this -> size == 0){
        this -> head = nvo;
        this -> tail = nvo;
    }
    else {
        this -> tail -> next = nvo;
        this -> tail = nvo;
    }
    this -> size++;
}

//Complejidad: O(n)
void LinkedList::removeAt(string ip){
    if(this -> size == 0){
        throw invalid_argument("No se ha podido eliminar la clave porque la lista está vacía");
    }

    if(this -> head -> ip == ip){
        NodoLL* nvo = this -> head;
        this -> head = this -> head -> next;
        delete nvo;
        this -> size--;
        if(this -> head == nullptr){
            this -> tail = nullptr;
        }
        return;
    }

    NodoLL* current = this -> head;
    while(current -> next != nullptr && current -> next -> ip != ip){
        current = current -> next;
    }

    if(current -> next == nullptr){
        throw invalid_argument("No se encontró la clave para eliminar");
    }

    NodoLL* nvo = current -> next;
    current -> next = nvo -> next;

    if(nvo == this -> tail){
        this -> tail = current;
    }

    delete nvo;
    this -> size--;
}

//Complejidad: O(n)
void LinkedList::flush(){
    NodoLL* current = this -> head;
    while(current != nullptr){
        NodoLL* nvo = current;
        current = current -> next;
        delete nvo;
    }
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
}