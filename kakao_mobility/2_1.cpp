#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> visited;

                    // 상 하 좌 우
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool isValid(int nx, int ny, int plan_row, int plan_col, vector<string> &plan) {
    return (nx >= 0 && nx < plan_row && ny >= 0 && ny < plan_col && plan[nx][ny] != '#' && !visited[nx][ny]);
}

void dfs(int x, int y, int plan_row, int plan_col, vector<string> &plan) {
    
    visited[x][y] = true;

    for (int d=0; d<4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (isValid(nx, ny, plan_row, plan_col, plan)) {
            dfs(nx, ny, plan_row, plan_col, plan);
        }
    }
}

int solution(vector<string> &plan) {
    int plan_row = plan.size();
    int plan_col = plan[0].size();
    int answer = 0;

    visited.assign(plan_row, vector<bool>(plan_col, false));

    for (int i=0; i<plan_row; i++) {
        for (int j=0; j<plan_col; j++) {
            if (plan[i][j] == '*' && !visited[i][j]) {
                answer++;
                dfs(i, j, plan_row, plan_col, plan);
            }
        }
    }

    return answer;

}

int main() {

    vector<string> plan1 = {
        "*#..",
        "#..#",
        ".##.",
        "...*"
    };

    vector<string> plan2 = {
        ".*#..*",
        ".*#*.#",
        "######",
        ".*..#.",
        "...###"
    };

    vector<string> plan3 = {
        "**###**",
        "*#*#*#*",
        "##*#*##",
        "*#***#*",
        ".#####.",
        "..*#*.."
    };

    cout << solution(plan1) << "\n"; // 2
    cout << solution(plan2) << "\n"; // 3
    cout << solution(plan3) << "\n"; // 5
    
    return 0;
}