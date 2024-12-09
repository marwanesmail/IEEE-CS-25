#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> distA, distM;
pair<int, int> start;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfs(queue<pair<int, int>>& q, vector<vector<int>>& dist) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

string reconstructPath(pair<int, int> end) {
    string path;
    pair<int, int> at = end;
    while (at != start) {
        for (int i = 0; i < 4; ++i) {
            int nx = at.first - dx[i];
            int ny = at.second - dy[i];
            if (isValid(nx, ny) && distA[nx][ny] == distA[at.first][at.second] - 1) {
                path += dir[i];
                at = {nx, ny};
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    distA.assign(n, vector<int>(m, -1));
    distM.assign(n, vector<int>(m, -1));
    queue<pair<int, int>> qA, qM;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start = {i, j};
                qA.push({i, j});
                distA[i][j] = 0;
            } else if (grid[i][j] == 'M') {
                qM.push({i, j});
                distM[i][j] = 0;
            }
        }
    }
    bfs(qA, distA);
    bfs(qM, distM);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i == 0 || i == n-1 || j == 0 || j == m-1) && distA[i][j] != -1 && (distM[i][j] == -1 || distA[i][j] < distM[i][j])) {
                cout << "YES\n";
                string path = reconstructPath({i, j});
                cout << path.length() << '\n';
                cout << path << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
 