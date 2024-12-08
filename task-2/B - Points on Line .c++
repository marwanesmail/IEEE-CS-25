#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    
    sort(points.begin(), points.end());
    
    int max_points = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && points[j] - points[i] <= d) {
            ++j;
        }
        max_points = max(max_points, j - i);
    }
    
    cout << max_points << endl;
    return 0;
}
