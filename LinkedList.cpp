#include "LinkedList.h"

LinkedList::LinkedList(){
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
}

LinkedList::~LinkedList(){
    NodoLL* current = this -> head;
    while(current != nullptr){
        NodoLL* nvo = current;
        current = current -> next;
        delete nvo;
    }
}

bool LinkedList::isEmpty(){
    return this -> size == 0;
}

int LinkedList::getAt(string ip){
    NodoLL* current = this -> head;
    while(current != nullptr){
        if (current -> ip == ip){
            return current -> visitas.size();
        }
        current = current -> next;
    }
    throw invalid_argument("No se encontro la clave");
}

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