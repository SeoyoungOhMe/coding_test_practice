#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x;
    cin >> x;

    int dp[30001] = {0};

    dp[1] = 0;

    for (int i=2; i<=x; i++) {
        dp[i] = dp[i-1] +1;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // 3으로 나누어 떨어지면 그 값을 갱신
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }

        // 5로 나누어 떨어지면 그 값을 갱신
        if (i % 5 == 0) {
            dp[i] = min(dp[i], dp[i / 5] + 1);
        }
    }
    
    return 0;
}