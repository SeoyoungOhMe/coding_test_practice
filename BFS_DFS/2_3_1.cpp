// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    
    visited[x][y] = true;
                    //오, 아, 왼, 위
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && board[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int main() {

    cin >> n >> m;
    board.assign(n, vector<int>(m, false));

    for (int i=0; i<n; i++) {
        string input;
        cin >> input;

        for (int j=0; j<m; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    int answer = 0;
    visited.assign(n, vector<bool>(m, false));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 0 && !visited[i][j]) {
                answer++;
                dfs(i, j);
            }
        }
    } 

    cout << answer;
    
    return 0;
}