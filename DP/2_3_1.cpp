#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int dp[101];
    int stock[101];

    for (int i=1; i<=n; i++){
        cin >> stock[i];
    }
    
    dp[1] = stock[1];
    dp[2] = max(stock[1], stock[2]);

    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+ stock[i]);
    }
    
    cout << dp[n];

    return 0;
}