#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
class CountingRooms {
public:
    int rows, cols;
    // right, left, up, down
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    CountingRooms(int r, int c): rows(r), cols(c){}
 
    int solve(vector<string> &grid) {
        int ans = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '.') {
                    ans++;
                    dfs(r, c, grid);
                }
            }
        }
        return ans;
    }
 
    void dfs(int row, int col, vector<string> &grid) {
        grid[row][col] = '#';
        for (auto &dir: directions) {
            int r = row + dir[0];
            int c = col + dir[1];
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '#') continue;
            dfs(r, c, grid);
        }
    }
};
 
int main() {
    // read the input
    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    for (int i = 0; i < rows; i++) cin >> grid[i];
 
    // solve
    CountingRooms solver(rows, cols);
    cout << solver.solve(grid);
 
    return 0;
}