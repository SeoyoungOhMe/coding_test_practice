#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr;
    arr.assign(n, 0);

    int first, second = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    first = arr[arr.size()-1];
    second = arr[arr.size()-2];

    int sum=0;
    while (true){
        for (int i=0; i<k; i++){
            if (m==0){
                break;
            }
            sum += first;
            m--;
        }
        if (m==0){
            break;
        }
        sum += second;
        m--;
    }

    cout << sum;
}