#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid * mid == n) {
            cout << mid;
            return 0;
        }
        else if (mid * mid < n) {
            ans = mid;        
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
    return 0;
}