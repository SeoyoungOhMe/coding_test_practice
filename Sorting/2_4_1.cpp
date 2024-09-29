#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr1(n, 0);
    vector<int> arr2(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr1[i];
    }

    for (int i=0; i<n; i++){
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<>());

    for(int i=0; i<k; i++){
        arr1[i] = arr2[i];
    }

    int sum = accumulate(arr1.begin(), arr1.end(), 0);

    cout << sum;

    return 0;
}