#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cnt = 0;
    int n, k;
    string input;
    vector<bool> visitedH;

    cin >> n >> k;
    cin >> input;
    visitedH.assign(n, false);

    int crrntIndex = 0;
    for (int crrntIndex = 0; crrntIndex < n; crrntIndex++) {
        cout << "turn: " << crrntIndex << "\n";

        if (input[crrntIndex] == 'P') {
            for (int i = -k; i <= k; i++) {
                if ((crrntIndex+i >= 0) && (crrntIndex+i < n) && input[crrntIndex+i] == 'H' && !visitedH[crrntIndex+i]) {
                    cnt++; 
                    visitedH[crrntIndex+i] = true;
                    cout << "crrntIndex-i:" << crrntIndex+i<< "\n";
                    cout << visitedH[crrntIndex+i];
                    break;
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}