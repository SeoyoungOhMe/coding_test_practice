#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> visited;
int n, m;
int init_x, init_y, init_dir;
vector<vector<int>> map;
int answer = 0;

bool isValid(int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && map[x][y] == 0) {
        return true;
    }
    return false;
}

void moveCharacter(int row, int col, int dir) {
    answer++;
    visited[row][col] = true;

    cout << "row=" << row << ", col=" << col << "\n";

    // 왼, 아래, 오른, 위 방향 벡터 설정하기
    vector<int> delX = {-1, 0, 1, 0};
    vector<int> delY = {0, -1, 0, 1};

    int delDir = (4 - dir) % 4;
    
    int cnt = 0;
    int x, y;

    // for문 돌며 네 방향 모두 확인해보기
        // stop하는 경우인지 확인
    for (int i=0; i<4; i++) {
        cout << "i=" << i << ", dir=" << dir << "\n";
        // 왼쪽으로 회전 후 한 칸 이동
        x = delX[(i + delDir)%4] + col;
        y = delY[(i + delDir)%4] + row;
       
        if (isValid(x, y)) {
            cnt++;
            cout << "i+delDir=" << i + delDir << ", delDir=" << delDir << "\n";
            cout << "delX[i+delDir]=" << delX[i + delDir] << ", col=" << col << "\n";
            cout << "delY[i+delDir]=" << delY[i + delDir] << ", row=" << row << "\n";
            cout << "(" << x << ", " << y << ")" << "\n";
            moveCharacter(x, y, dir);
        }
    }

    if (cnt == 0) {
        x = col + delX[(5-dir)%4];
        y = row + delY[(5-dir)%4];

        if (x >= 0 || x < m || y >= 0 || y < n || map[x][y] == 1) {
            return;
        }
        answer--;
        cout << "(" << x << ", " << y << ") => stocked" << "\n";
        moveCharacter(x, y, dir);
    }
}

int main() {

    // map 크기, 캐릭터의 초기 위치와 방향, 맵의 구성 입력받기, answer=0 초기화, 2차원 visited 초기화
    cin >> n >> m;

    cin >> init_x >> init_y >> init_dir;

    map.assign(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int input;
            cin >> input;
            if (input == 1) {
                map[i][j] = 1;
            }
        }
    }

    visited.assign(n, vector<int>(m, 0));

    // 이동하는 함수 호출하기
    moveCharacter(init_y, init_x, init_dir);

    // 방문한 칸의 개수 출력
    // cout << answer;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}