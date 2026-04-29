#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(int arr[], int n, int k, int dist) {
    int cows = 1;
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            cows++;
            lastPos = arr[i];
        }
        if (cows >= k)
            return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int left = 1, right = arr[n - 1] - arr[0];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            left = mid + 1;  
        } else {
            right = mid - 1; 
        }
    }

    cout << ans;
    return 0;
}