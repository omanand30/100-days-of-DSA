#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

int main() {
    int n, c, e;
    cin >> n;

    Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        cin >> c >> e;
        Node* newNode = new Node(c, e);

        if (!head) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL) {
        cout << temp->coeff;

        if (temp->exp > 0) {
            cout << "x";
            if (temp->exp > 1) {
                cout << "^" << temp->exp;
            }
        }

        if (temp->next != NULL) {
            cout << " + ";
        }

        temp = temp->next;
    }

    return 0;
}