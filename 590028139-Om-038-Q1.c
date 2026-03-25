#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int arr[MAX];
int front = -1, rear = -1;

bool empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    arr[front] = x;
}

void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    arr[rear] = x;
}

void pop_front() {
    if (empty()) return;

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (empty()) return;

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int getFront() {
    if (empty()) return -1;
    return arr[front];
}

int getBack() {
    if (empty()) return -1;
    return arr[rear];
}

void display() {
    if (empty()) return;

    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x; cin >> x;
            push_front(x);
        }
        else if (op == "push_back") {
            int x; cin >> x;
            push_back(x);
        }
        else if (op == "pop_front") {
            pop_front();
        }
        else if (op == "pop_back") {
            pop_back();
        }
        else if (op == "front") {
            cout << getFront() << endl;
        }
        else if (op == "back") {
            cout << getBack() << endl;
        }
        else if (op == "size") {
            cout << size() << endl;
        }
        else if (op == "empty") {
            cout << (empty() ? "true" : "false") << endl;
        }
        else if (op == "display") {
            display();
        }
    }

    return 0;
}