#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& boards, int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return false;

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if (painters > k)
                return false;
        }
    }
    return true;
}

int minTime(vector<int>& boards, int n, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; i++)
        cin >> boards[i];

    cout << minTime(boards, n, k);

    return 0;
}