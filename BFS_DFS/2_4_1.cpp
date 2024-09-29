#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};
vector<vector<int>> maze;
vector<vector<bool>> visited_bfs;
int cnt = 0;
int n, m;

void bfs(int x, int y){
    queue <pair<int, int>> q;
    q.push({x, y});
    visited_bfs[x][y]=true;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        cnt++;

        for (int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >=0 && nextX <n 
                && nextY >=0 && nextY <m 
                && !visited_bfs[nextX][nextY] 
                && maze[nextX][nextY] == 1){

                cout << nextX << " "<< nextY << "\n";
                q.push({nextX, nextY});
                visited_bfs[nextX][nextY]=true;

            }

            if (nextX==m-1 && nextY==n-1){
                return;
            }
        }
    }
}

int main(){
    vector<string> map;

    cin >> n >> m;
    map.assign(n, "");

    for (int i=0; i<n; i++){
        cin >> map[i];
    }

    maze.assign(n, vector<int>(m, 0));
    visited_bfs.assign(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            maze[i][j] = map[i][j] - '0';
        }
    }

    bfs(0, 0);
    

    cout << cnt << "\n";
     
    return 0;
}