#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int heapArr[MAX];
int size = 0;

void heapifyUp(int i) {
    while (i > 0 && heapArr[(i - 1) / 2] > heapArr[i]) {
        swap(heapArr[i], heapArr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heapArr[left] < heapArr[smallest])
            smallest = left;

        if (right < size && heapArr[right] < heapArr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heapArr[i], heapArr[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int x) {
    heapArr[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin() {
    if (size == 0) {
        cout << -1 << endl;
        return;
    }

    cout << heapArr[0] << endl;

    heapArr[0] = heapArr[size - 1];
    size--;

    heapifyDown(0);
}

void peek() {
    if (size == 0) cout << -1 << endl;
    else cout << heapArr[0] << endl;
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
        else if (op == "extractMin") {
            extractMin();
        }
        else if (op == "peek") {
            peek();
        }
    }

    return 0;
}