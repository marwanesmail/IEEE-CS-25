#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairs(vector<int>& arr, int l, int r) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int low = lower_bound(arr.begin() + i + 1, arr.end(), l - arr[i]) - arr.begin();
        int high = upper_bound(arr.begin() + i + 1, arr.end(), r - arr[i]) - arr.begin();
        count += (high - low);
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << countPairs(arr, l, r) << endl;
    }
    return 0;
}
