#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    for (int i = 0; i < len; i++) {
        insertPosition(i+1, array[i]); // insert at end
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    if (pos <= 1 || head == nullptr) {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int index = 1;
    while (current->link != nullptr && index < pos - 1) {
        current = current->link;
        index++;
    }
    newNode->link = current->link;
    current->link = newNode;
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }

    Node* current = head;
    int index = 1;
    while (current->link != nullptr && index < pos - 1) {
        current = current->link;
        index++;
    }

    if (current->link == nullptr) return false;

    Node* temp = current->link;
    current->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return numeric_limits<int>::max();

    Node* current = head;
    int index = 1;

    while (current != nullptr && index < pos) {
        current = current->link;
        index++;
    }

    if (current == nullptr) return numeric_limits<int>::max();

    return current->data;
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        if (current->data == target) return index;
        current = current->link;
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    if (head == nullptr) {
        cout << "[]";
        return;
    }

    cout << "[";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->link != nullptr) cout << " ";
        current = current->link;
    }
    cout << "]";
}
