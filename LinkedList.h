//Actividad Integradora 5.2
//Diego Israel Dominguez Najera A01782831
//Andrea Marlene Ramos Tiscareño A01646342
//Samuel Rodriguez Torres A01637408
//21 de Noviembre del 2025

#pragma once
#include <vector>
#include <string>
using namespace std;

struct NodoLL {
    string ip;
    vector<string> visitas;
    NodoLL* next;

    NodoLL(string ip, vector<string> visitas, NodoLL* next) {
        this->ip = ip;
        this->next = next;
        this->visitas = visitas;
    }
    NodoLL(string ip, vector<string> visitas) : NodoLL(ip, visitas, nullptr) {}
};;

class LinkedList {
    public:
        int size;
        NodoLL* head;
        NodoLL* tail;
        
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        vector<string> getAt(string key);
        void insertLast(string key, string value);
        void insertLast(string key, vector<string> visitas);
        void removeAt(string key);
        void flush();
};