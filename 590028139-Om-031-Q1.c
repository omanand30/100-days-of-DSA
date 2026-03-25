#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << stackArr[top] << endl;
    top--;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}