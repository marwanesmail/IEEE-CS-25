#include <iostream>
#include <vector>
using namespace std;

int maxBooks(int n, int t, vector<int>& a) {
    int max_books = 0;
    int current_time = 0;
    int start = 0;
    
    for (int end = 0; end < n; ++end) {
        current_time += a[end];
        
        while (current_time > t) {
            current_time -= a[start];
            ++start;
        }
        
        max_books = max(max_books, end - start + 1);
    }
    
    return max_books;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << maxBooks(n, t, a) << endl;
    return 0;
}
