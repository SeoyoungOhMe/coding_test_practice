#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>

using namespace std;

int n, m;
vector<vector<int>> board;

bool isValid(int nx, int ny) {
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1) return true;
    else return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0)); // first: row, second: col

                    // 하 우 좌 상
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, 1, -1, 0};

    while (!q.empty()) {
    // for (int cnt = 0; cnt<10; cnt++) {
        
        pair<int, int> current_v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current_v.first + dx[i];
            int ny = current_v.second + dy[i];
            
            if (isValid(nx, ny)) {
                q.push(make_pair(nx, ny));
                board[nx][ny] = board[current_v.first][current_v.second] + 1;
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