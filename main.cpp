//
//
//Mehraj Hasan Nafi || COMSC - 210
//IDE Used: VSCode
//
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Customer {
    string name;
    string drink;
};

struct Node {
    Customer data;
    Node* next;

    Node(const Customer& c) : data(c), next(nullptr) {} 
};

class LinkedListQueue {
private:
    Node* head;
    Node* tail;

public:
    LinkedListQueue() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void enqueue(const Customer& c) {
        Node* newNode = new Node(c);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool dequeue(Customer& out) {
        if (isEmpty()) return false;

        Node* temp = head;
        out = head->data;
        head = head->next;
       
        if (head == nullptr) 
            tail = nullptr;
            delete temp;
        
        return true;
    }

    void printQueue() const {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }

        Node* current = head;
        While (current != nullptr) {
            cout << "Customer: " << current->data.name << ", Drink: " << current->data.drink << endl;
            if (cur->next) cout << " <- ";
            current = current->next;
        }
        cout << endl;
    }
};

vector<string> names = {
    "Nafi","Mehraj","Tracy","Drew","Evan","Finley","Grace","Harper"
};

vector<string> drinks = {
    "Latte","Espresso","Mocha","Cappuccino","Americano","Chai"
};

Customer randomCustomer() {
    Customer c;
    c.name = names[rand() % names.size()];
    c.drink = drinks[rand() % drinks.size()];
    return c;
}


        