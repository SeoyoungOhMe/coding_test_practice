#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    sort(arr.begin(), arr.end());

    sort(arr.begin(), arr.end(), greater<>());

}