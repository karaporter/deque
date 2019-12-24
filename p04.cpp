#include <iostream>
#include "p04.h"

void destroyDeque(Node* &head, int &length) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0; 
}


Deque::Deque() {
    length = 0;
    head = nullptr;
    tail = head;
    }

Deque::~Deque() { clear();}

Deque::Deque(const Deque& orig) {
    head = nullptr;
    tail = head;
    length = orig.length;
    if (length > 0) {
        head = new Node(orig.head->data);
        tail = head;
        Node* otemp = orig.head->next;
        Node* temp = head;
        while (otemp != nullptr) {
            tail->next = new Node(otemp->data);
            tail = tail->next;
            tail->prev = temp;
            temp->next = tail;
            temp = temp->next;
            otemp = otemp->next;
        }
    } 
}

Deque& Deque::operator=(const Deque& rhs) {
        if (this != &rhs) {
        clear();
        head = nullptr;
        tail = head;
        length = rhs.length;
        if (length > 0) {
            head = new Node(rhs.head->data);
            tail = head;
            Node* otemp = rhs.head->next;
            Node* temp = head;
            while (otemp != nullptr) {
                tail->next = new Node(otemp->data);
                tail = tail->next;
                tail->prev = temp;
                temp->next = tail;
                temp = temp->next;
                otemp = otemp->next;
            }
        }
    }
    return *this; 
}

void Deque::push_front(int elt) {
    if (length == 0) {
        head = new Node(elt);
        tail = head;
        length++;
    } else {
        Node* n = new Node(elt);
        head->prev = n;
        n->next = head;
        head = n;
        length++;
    }
}

void Deque::push_back(int elt) {
    if (length == 0) {
        tail = new Node(elt);
        head = tail;
        length++;
    } else { 
        Node* n = new Node(elt);
        tail->next = n;
        n->prev = tail;
        tail = n;
        length++;
    }
}

int Deque::pop_front() { 
    if (length == 0) {
        throw DequeEmptyException();
    } else if (length == 1) {
        Node* temp = head;
        int t = temp->data;
        head = nullptr;
        tail = head;
        delete temp;
        length --;
        return t;
    } else {
        Node* temp = head;
        head = head->next;
        int t = temp->data;
        head->prev = nullptr;
        delete temp;
        length--;
        return t;
        }
    }

int Deque::pop_back() {
    if (length == 0) {
        throw DequeEmptyException();
    } else if (length == 1) {
        Node* temp = tail;
        int t = temp->data;
        tail = nullptr;
        head = tail;
        delete temp;
        length --;
        return t;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        int t = temp->data;
        tail->next = nullptr;
        delete temp;
        length--;
        return t;
    }
}

int Deque::size() const {
    return length;
    }

bool Deque::is_empty() const {
    return length == 0;
}

void Deque::clear() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
length = 0; 
}