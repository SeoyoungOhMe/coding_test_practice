#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, direction;
// 방문한 위치를 저장하기 위한 맵을 bool로 변경
vector<vector<bool>> visited(50, vector<bool>(50, false));
// 전체 맵 정보
vector<vector<int>> board(50, vector<int>(50, 0));

// 북, 동, 남, 서 방향 정의
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 왼쪽으로 회전
void turn_left() {
    if (direction == 0) direction == 3;
    else direction--;
}

int moveForward() {
    int nx, ny;
    nx = x + dx[direction];
    ny = y + dy[direction];
    return nx, ny;
}

int moveBackward() {
    int nx, ny;
    nx = x - dx[direction];
    ny = y - dy[direction];
    return nx, ny;
}

// 시뮬레이션을 수행하는 함수
int simulate() {
    int answer = 1; // 방문한 칸 수
    int fail_cnt = 0;

    // while문
    while(true) {
        // 왼쪽으로 돌고, 한 칸 앞으로 전진하는 좌표를 계산
        turn_left();
        int nx, ny = moveForward();

        // 왼쪽으로 한 칸 이동 좌표가 육지이고, visited가 아니라면 이동하고, 다음 while문으로 진행
        if (board[nx][ny] == 0 && !visited[nx][ny]) {
            answer++;
            visited[nx][ny] = true;
            x = nx;
            y = ny;
            fail_cnt = 0;
            continue;
        }
        // 이동할 수 없다면, 실패 횟수+1
        else {
            fail_cnt++;
        }

        // 만약 실패 횟수=4라면, 한 칸 뒤로 가는 좌표를 계산
        if (fail_cnt == 4) {
            int nx, ny = moveBackward();
            // 만약 한 칸 뒤로 가는 좌표가 바다라면 break
            if (board[nx][ny] == 1) {
                break;
            }
            // 아니라면 뒤로 가는 좌표로 갱신해서 이동하고, 다음 while문으로 진행
            else {
                x = nx;
                y = ny;
            }
        }
        fail_cnt = 0;
    }
    
    return answer; // 방문한 칸 수를 반환
}

int main(void) {
    // N, M을 공백을 기준으로 구분하여 입력받기
    cin >> n >> m;
    // 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
    cin >> x >> y >> direction;
    visited[x][y] = true; // 현재 좌표 방문 처리

    // 전체 맵 정보를 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 시뮬레이션 시작
    int answer = simulate();
    cout << answer << '\n';

    return 0;
}
