#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size - 1;

    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

void deleteMin() {
    if (size == 0) {
        cout << -1 << endl;
        return;
    }

    cout << pq[0] << endl;

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

void peek() {
    if (size == 0) {
        cout << -1 << endl;
    } else {
        cout << pq[0] << endl;
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
        else if (op == "delete") {
            deleteMin();
        }
        else if (op == "peek") {
            peek();
        }
    }

    return 0;
}