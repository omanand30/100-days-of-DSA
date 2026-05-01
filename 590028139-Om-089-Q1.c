#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return false;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return false;
        }
    }
    return true;
}

int allocateBooks(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << allocateBooks(arr, n, m);

    return 0;
}