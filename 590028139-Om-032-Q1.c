#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int stackArr[MAX];
int top = -1;

void push(int x) {
    stackArr[++top] = x;
}

void pop() {
    if (top == -1) return;
    top--;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        pop();
    }

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }

    return 0;
}