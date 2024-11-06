#include <bits/stdc++.h>

using namespace std;

int r, c, k;
vector<vector<bool>> occupied;
vector<vector<bool>> visited;
vector<vector<bool>> exitPlace; // 출구 위치 저장

vector<int> dx = {-1, 0, 1, 0}; // 상, 우, 하, 좌
vector<int> dy = {0, 1, 0, -1};

int answer = 0;
int x, y; // 현재 골렘의 위치

bool isInRange(int x, int y) {
    return (0 <= x && x < r && 0 <= y && y < c);
}

bool isTop() {
    return (occupied[x+1][y] || occupied[x+1][y-1] || occupied[x+2][y] || occupied[x+1][y+1]);
}

bool isMovingDownValid() {
    return isInRange(x+1, y) && !occupied[x+1][y-1] && !occupied[x+2][y] && !occupied[x+1][y+1];
}

void moveDown() {
    x++;
}

bool isFloor() {
    return (x+1 == r-1);
}

void changeOccupied() {
    occupied[x][y] = true;
    occupied[x-1][y] = true;
    occupied[x+1][y] = true;
    occupied[x][y-1] = true;
    occupied[x][y+1] = true;
}

int moveChar() { 
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int last_row = x;

    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (isInRange(nx, ny) && occupied[nx][ny] && !visited[nx][ny]) {
                if (occupied[nx][ny] || exitPlace[curX][curY]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    last_row = max(last_row, nx);
                }
            }
        }
    }
    return last_row;
}

bool isTurningLeftValid() {
    return x != 1 && !occupied[x][y-2] && !occupied[x+1][y-1] && isMovingDownValid();
}

bool isTurningRightValid() {
    return x != c-2 && !occupied[x][y+2] && !occupied[x+1][y+1] && isMovingDownValid();
}

void turnLeft(int& exit_dir) {
    exit_dir = (exit_dir + 3) % 4;
}

void turnRight(int& exit_dir) {
    exit_dir = (exit_dir + 1) % 4;
}

int main() {
    cin >> r >> c >> k;
    occupied.assign(r, vector<bool>(c, false));
    visited.assign(r, vector<bool>(c, false));
    exitPlace.assign(r, vector<bool>(c, false));

    for (int i = 0; i < k; i++) {
        int start, exit_dir;
        cin >> start >> exit_dir;

        x = -1;
        y = start - 1;

        while (true) {
            if (isTop()) {
                occupied.assign(r, vector<bool>(c, false));
                exitPlace.assign(r, vector<bool>(c, false));
                break;
            } else if (isMovingDownValid()) {
                moveDown();
            } else if (isFloor()) {
                int last_row = moveChar();
                answer += last_row;
                changeOccupied();
                break;
            } else {
                if (isTurningLeftValid()) {
                    turnLeft(exit_dir);
                    moveDown();
                } else if (isTurningRightValid()) {
                    turnRight(exit_dir);
                    moveDown();
                } else {
                    visited.assign(r, vector<bool>(c, false));
                    int last_row = moveChar();
                    answer += last_row;
                    changeOccupied();
                    break;
                }
            }
        }
    }

    cout << answer;
    return 0;
}
