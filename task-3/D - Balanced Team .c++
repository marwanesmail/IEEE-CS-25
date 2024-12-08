#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> skills(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }
    
    sort(skills.begin(), skills.end());
    
    int max_team_size = 0;
    int j = 0;
    
    for (int i = 0; i < n; ++i) {
        while (j < n && skills[j] - skills[i] <= 5) {
            ++j;
        }
        max_team_size = max(max_team_size, j - i);
    }
    
    cout << max_team_size << endl;
    
    return 0;
}
