#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    while (true){
        if (n==1){
            break;
        }

        if (n%k==0){
            n/=k;
            cnt++;
        } else {
            n--;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}