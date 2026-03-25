#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int arr[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    arr[rear] = x;
}

void dequeue() {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) return;

    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enqueue(x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}