#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<bool> visited_dfs;
vector<bool> visited_bfs;
vector<vector<int>> li;

void dfs(int index, vector<int>& ans_dfs) {
    visited_dfs[index] = true;
    ans_dfs.push_back(index);

    for (int i=1; i<=n; i++) {
        if (li[index][i] == 1 && !visited_dfs[i]) {
            dfs(i, ans_dfs);
        }
    }
}

void bfs(vector<int>& ans_bfs) {
    queue<int> q;
    visited_bfs[v] = true;
    q.push(v);

    while (!q.empty()) {
        int current_v = q.front();
        q.pop();
        ans_bfs.push_back(current_v);

        for (int i=1; i<n; i++) {
            if (li[current_v][i] == 1 && !visited_bfs[i]) {
                q.push(i);
                visited_bfs[i] = true;
            }
        }
    }
}

int main() {

    cin >> n >> m >> v;

    visited_dfs.assign(n, false);
    li.assign(n, vector<int>(n, 0));

    for (int i=0; i<m; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        li[node1][node2] = 1;
        li[node2][node1] = 1;
    }

    vector<int> ans_bfs, ans_dfs;

    dfs(v, ans_dfs);
    bfs(ans_bfs);
    
    return 0;
}