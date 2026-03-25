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

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* p1 = head1;
    Node* p2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++) p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    
    cin >> n;
    Node *head1 = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!head1) {
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
        if (!head2) {
            head2 = new Node(x);
            temp = head2;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }


    Node* ans = getIntersection(head1, head2);

    if (ans) cout << ans->data;
    else cout << "No Intersection";

    return 0;
}