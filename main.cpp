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
       
        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        return true;
    }

    void printQueue() const {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << "Customer: " << current->data.name << ", Drink: " << current->data.drink << endl;
            if (current->next)
                cout << "";
            current = current->next;
        }
        cout << endl;
    }
        int getSize() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
           count++;
            temp = temp->next;
    }
    return count;
   }
};

struct BraceletCustomer {
    string name;
    string bracelet;
};

vector<string> names = {
    "Nafi","Mehraj","Tracy","Drew","Evan","Finley","Grace","Harper"
};

vector<string> drinks = {
    "Latte","Espresso","Mocha","Cappuccino","Americano","Chai"
};

vector<string> bracelets = {
    "Beaded","Charm","Glow","Friendship","Woven"
};

Customer randomCustomer() {
    Customer c;
    c.name = names[rand() % names.size()];
    c.drink = drinks[rand() % drinks.size()];
    return c;
}

BraceletCustomer randomBraceletCustomer() {
    BraceletCustomer c;
    c.name = names[rand() % names.size()];
    c.bracelet = bracelets[rand() % bracelets.size()];
    return c;
}

bool fiftyPercentChance() {
    return rand() % 2 == 0;
}

int main() {
    srand(time(nullptr));
    LinkedListQueue queue;

    vector<BraceletCustomer> braceletQueue;

    int totalServed = 0;
    int totalArrived = 3;
    int maxQueueSize = 0;


    queue.enqueue(randomCustomer());
    queue.enqueue(randomCustomer());
    queue.enqueue(randomCustomer());

    cout << "Current Queue:" << endl;
    queue.printQueue();

    Customer served;
    if (queue.dequeue(served)) {
        cout << "Served Customer: " << served.name << ", Drink: " << served.drink << endl;
        totalServed++;
    }  

    cout << "Queue after serving one customer:" << endl;
    queue.printQueue();     

    cout << " 10 round simulation starts now! " << endl;
    for (int round = 1; round <= 10; ++round) {
        cout << "Round " << round << ":" << endl;

        Customer served2;
        if (queue.dequeue(served2)) {
            cout << "Served Customer: " << served2.name << ", Drink: " << served2.drink << endl;
            totalServed++;
        } else {
            cout << "No customer to serve." << endl;
        }

        if (fiftyPercentChance()){
            Customer newcustomer = randomCustomer();
            queue.enqueue(newcustomer);
            cout << "New Customer Arrived: " << newcustomer.name << ", Drink: " << newcustomer.drink << endl;
        totalArrived++;
        }else {
            cout << "No new customer arrived." << endl;
        }

        if (!braceletQueue.empty()) {
        cout << "Bracelet Booth Served: "
             << braceletQueue.front().name
              << ", Bracelet: " << braceletQueue.front().bracelet << endl;
            braceletQueue.erase(braceletQueue.begin());
        }
        else {
            cout << "Bracelet Booth: No customer to serve." << endl;
        }

        if (fiftyPercentChance()) {
            BraceletCustomer bc = randomBraceletCustomer();
            braceletQueue.push_back(bc);
            cout << "Bracelet Customer Arrived: "
                 << bc.name << ", Bracelet: " << bc.bracelet << endl;
        } else {
            cout << "No bracelet customer arrived this round." << endl;
        }


        int currentQueueSize = queue.getSize();
        if (currentQueueSize > maxQueueSize) {
            maxQueueSize = currentQueueSize;
        }

        cout << "Queue Status:" << endl;
        queue.printQueue();
    }

    cout << "----Simulation Summary----" << endl;
    cout << "Total Customers Arrived: " << totalArrived << endl;
    cout << "Total Customers Served: " << totalServed << endl;
    cout << "Maximum Queue Size: " << maxQueueSize << endl;

    return 0;
}


        