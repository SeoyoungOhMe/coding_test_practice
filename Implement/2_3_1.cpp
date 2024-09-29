#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    vector<vector<int>> map;
    vector<vector<bool>> visited;
    int x, y, dir;
    int cnt = 1;

    // 상 좌 하 우
    const int dx[4] = {0, -1, 0, 1};
    const int dy[4] = {-1, 0, 1, 0};

    cin >> n >> m;
    cin >> x >> y >> dir;

    map.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int start = 4-dir;
    int j = start % 4;

    for (int i=0; i<4; i++){

        int nextX = x + dx[j];
        int nextY = y + dy[j];

        cout << "j:" << j << "\n";
        cout << "nextX:" << nextX << "\n";
        cout << "nextY:" << nextY << "\n";

        if (nextX >= 0 && nextX <= m-1 && nextY >= 0 && nextY <= n-1 && !visited[nextX][nextY] && map[nextX][nextY] == 0){
            cnt++;
            x = nextX;
            y = nextY;
        }

        j++;
    }

    cout << cnt << "\n";

    return 0;
}