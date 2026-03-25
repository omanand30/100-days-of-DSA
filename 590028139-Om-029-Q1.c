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
    int n, x, k;
    cin >> n;

    Node *head = NULL, *temp = NULL;

    // create list
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!head) {
            head = new Node(x);
            temp = head;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

    cin >> k;

    if (!head || !head->next || k == 0) {
        temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }

    int len = 1;
    temp = head;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;

    int steps = len - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    newTail->next = NULL;

    temp = newHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}