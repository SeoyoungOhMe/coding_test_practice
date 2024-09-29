#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> card;
    vector<int> min;

    card.assign(n, vector<int>(m, 0));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> card[i][j];
        }
    }

    min.assign(n, 0);

    for (int i=0; i<n; i++){
        min[i] = *min_element(card[i].begin(), card[i].end());
    }

    cout << *max_element(min.begin(), min.end());

    return 0;
}