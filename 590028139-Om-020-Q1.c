#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<long long, int> freq;
    long long sum = 0;
    long long count = 0;

    freq[0] = 1; 

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq.find(sum) != freq.end()) {
            count += freq[sum];
        }

        freq[sum]++;
    }

    cout << count << endl;

    return 0;
}