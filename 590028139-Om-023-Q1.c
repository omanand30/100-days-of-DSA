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

Node* mergeLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0); 
    Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy->next;
}

int main() {
    int n, m, x;

    cin >> n;
    Node *head1 = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (head1 == NULL) {
            head1 = new Node(x);
            temp = head1;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

    cin >> m;
    Node *head2 = NULL;
    temp = NULL;

    for (int i = 0; i < m; i++) {
        cin >> x;
        if (head2 == NULL) {
            head2 = new Node(x);
            temp = head2;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

    Node* merged = mergeLists(head1, head2);

    while (merged != NULL) {
        cout << merged->data << " ";
        merged = merged->next;
    }

    return 0;
}