#include <iostream>
#include <cmath>
using namespace std;

bool canComplete(int n, int k, int v) {
    int sum = 0;
    int power = 1;
    while (v / power > 0) {
        sum += v / power;
        power *= k;
    }
    return sum >= n;
}

int main() {
    int n, k;
    cin >> n >> k;
    int left = 1, right = n, answer = n;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canComplete(n, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}
