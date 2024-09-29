#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, v;
vector<vector<int>> li; // 연결되어 있는지를 저장한 배열 
vector<bool> visited_bfs;

void bfs(vector<int>& ans_bfs) {
    queue<int> q;
    q.push(v);
    visited_bfs[v] = true;

    while (!q.empty()) {
        int current_v = q.front();
        q.pop();
        ans_bfs.push_back(current_v);

        for (int i = 1; i <= n; i++) {
            if (li[current_v][i] == 1 && !visited_bfs[i]) {
		            q.push(i);
                visited_bfs[i] = true;
            }
        }
    }
}

int main() {
    n = 8;
    li.assign(n + 1, vector<int>(n + 1, 0));
    visited_bfs.assign(n + 1, false);

    li[1] = {0, 0, 1, 1, 0, 0, 0, 0, 1};
    li[2] = {0, 1, 0, 0, 0, 0, 0, 1, 0};
    li[3] = {0, 1, 0, 0, 1, 0, 0, 0, 0};
    li[4] = {0, 0, 0, 1, 0, 1, 0, 0, 0};
    li[5] = {0, 0, 0, 1, 1, 0, 0, 0, 0};
    li[6] = {0, 0, 0, 0, 0, 0, 0, 1, 0};
    li[7] = {0, 0, 1, 0, 0, 0, 1, 0, 1};
    li[8] = {0, 1, 0, 0, 0, 0, 0, 1, 0};

    v = 1;
    vector<int> ans_dfs, ans_bfs;
    bfs(ans_bfs);

    for (int i : ans_bfs) {
        cout << i << " ";   
    }
    cout << "\n";

    return 0;
}