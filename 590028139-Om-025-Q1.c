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
    int n, x, key;
    cin >> n;

    Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (head == NULL) {
            head = new Node(x);
            temp = head;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

    cin >> key;

    int count = 0;
    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    cout << count;

    return 0;
}