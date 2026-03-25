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

Node* frontNode = NULL;
Node* rearNode = NULL;

void enqueue(int x) {
    Node* newNode = new Node(x);

    if (rearNode == NULL) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void dequeue() {
    if (frontNode == NULL) {
        cout << -1 << endl;
        return;
    }

    cout << frontNode->data << endl;

    Node* temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == NULL) {
        rearNode = NULL;
    }

    delete temp;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            enqueue(x);
        }
        else if (op == "dequeue") {
            dequeue();
        }
    }

    return 0;
}