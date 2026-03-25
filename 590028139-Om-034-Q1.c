#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void push(Node* &top, int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}

int pop(Node* &top) {
    if (top == NULL) return 0;

    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;

    Node* top = NULL;

    while (ss >> token) {

        if (isdigit(token[0])) {
            push(top, stoi(token));
        }
    
        else {
            int b = pop(top);
            int a = pop(top);

            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;

            push(top, result);
        }
    }

    cout << pop(top);

    return 0;
}