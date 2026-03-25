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

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }

    int count = 0;
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << count;

    return 0;
}