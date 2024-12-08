#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }
    
    int max_books = 0, current_sum = 0, j = 0;
    
    for (int i = 0; i < n; ++i) {
        current_sum += books[i];
        
        while (current_sum > t) {
            current_sum -= books[j];
            j++;
        }
        
        max_books = max(max_books, i - j + 1);
    }
    
    cout << max_books << endl;
    
    return 0;
}
