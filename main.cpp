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

public:
    Node* head;
    Node* tail;

    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool dequeue(customer& out) {
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
            current = current->next;
        }
        cout << endl;
    }
};
        