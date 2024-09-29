#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector<vector<int>> node;
vector<vector<int>> li; // 연결되어 있는지를 저장한 배열 
vector<bool> visited_dfs;
vector<bool> visited_bfs;

void dfs(int index, vector<int>& ans_dfs) {
    visited_dfs[index] = true;
    ans_dfs.push_back(index);

    for (int i = 1; i <= n; i++) { // 인접한 노드를 순회함 
        if (li[index][i] == 1 && !visited_dfs[i]) { // 아직 방문하지 않은 근처 노드
            dfs(i, ans_dfs); // 깊은 부분 우선 탐색 
        }
    }
}

int main() {
    cout << "start" << endl;
    node.push_back(vector<int>{});
    node.push_back(vector<int>{2, 3, 8});
    node.push_back(vector<int>{1,7});
    node.push_back(vector<int>{1, 4, 5});
    node.push_back(vector<int>{3,5});
    node.push_back(vector<int>{3, 4});
    node.push_back(vector<int>{7});
    node.push_back(vector<int>{2, 6, 8});
    node.push_back(vector<int>{1, 7});

    n = node.size()-1;

    li.assign(n + 1, vector<int>(n + 1, 0));
    visited_dfs.assign(n + 1, false);
    visited_bfs.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= node[i].size(); j++){
            li[i][j] = li[j][i] = 1;
        }
    }

    int v = 0;
    vector<int> ans_dfs, ans_bfs;
    dfs(v, ans_dfs);
    // bfs(ans_bfs);
    cout << "start";
    for (int i : ans_dfs) {
        cout << "start";
        cout << i << " ";
        cout << "done";
    }
    cout << "\n";

    // for (int i : ans_bfs) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    return 0;
}