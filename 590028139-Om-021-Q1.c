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
    int n;
    cin >> n;

    if (n == 0) return 0;

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}