#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int arr[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    arr[++rear] = x;
}

void display() {
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
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

    display();

    return 0;
}