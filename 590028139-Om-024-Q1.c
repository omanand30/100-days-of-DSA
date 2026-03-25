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

    if (head != NULL && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
    } else {
        Node* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                break;
            }
            curr = curr->next;
        }
    }

    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}