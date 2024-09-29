#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> coin(n);

    for (int i=0; i<n; i++){
        cin >> coin[i];
    }

    vector<int> dp(m+1, INT_MAX);
    dp[0]=0;

    for (int i=1; i<=m; i++){
        for (int c: coin){
            if (i >= c && dp[i-c] != INT_MAX) dp[i] = min(dp[i], dp[i-c]+1);
        }
    }

    if (dp[m]==INT_MAX) cout << -1;
    else cout << dp[m];

    return 0;
}