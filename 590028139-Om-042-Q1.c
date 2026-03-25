#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    stack<int> st;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}