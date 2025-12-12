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
