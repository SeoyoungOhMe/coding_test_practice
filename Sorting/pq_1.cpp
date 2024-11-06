#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << 0;
            } else {
                cout << pq.top();
                pq.pop();
            }
        } else {
            pq.push(a);
        }
    }

    return 0;
}