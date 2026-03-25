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

int main() {
    int n, x;
    cin >> n;

    if (n == 0) return 0;

    Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    temp->next = head;

    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    return 0;
}