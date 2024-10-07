#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int>> board;
                //상하좌우
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        pair<int, int> current_v = q.front();
        int x = current_v.first;
        int y = current_v.second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 1) {
                q.push({nx, ny});
                board[nx][ny] = board[x][y] + 1;
            }
        }

    }
}

int main() {
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    bfs();

    cout << board[n-1][m-1];
    
    return 0;
}