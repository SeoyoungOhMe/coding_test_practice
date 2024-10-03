#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> storage(n, 0);

    for (int i=0; i<n; i++) {
        cin >> storage[i];
    }

    vector<int> dp(n, 0);

    dp[0] = storage[0];
    dp[1] = max(storage[0], storage[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-2] + storage[i], dp[i-1]);
    }

    cout << dp[n-1];

    
    return 0;
}