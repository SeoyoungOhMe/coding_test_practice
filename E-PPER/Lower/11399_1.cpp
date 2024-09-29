#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> time(n, 0);

    for (int i=0; i<n; i++){
        cin >> time[i];
    }

    sort(time.begin(), time.end());

    int cnt = 0;

    for (int i=0; i<n; i++){
        cnt += time[i] * (n-i);
    }

    cout << cnt;

    return 0;
}