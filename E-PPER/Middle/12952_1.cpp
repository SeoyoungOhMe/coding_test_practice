// 못 품

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<vector<bool>> allowed(n, vector<bool>(n, false));

    for (int cnt = 0; cnt < n; cnt++) {
        allowed.assign(n, vector<bool>(n, false));
        bool exitFlag = false;

        for (int row = 0; row < n; row++){ // row
            
            for (int col = 0; col < n; col++){ // col
                if (row == 0) {
                    col = cnt;
                }
                if (!allowed[row][col]) {
                    cout << row << " " << col << "\n";
                
                    for (int a = 1; a < n-row; a++) {
                        
                        allowed[row+a][col] = true; // 세로

                        if (col-a >= 0) { // 왼대각선
                            allowed[row+a][col-a] = true;
                        }

                        if (col+a < n) { //오른대각선
                            allowed[row+a][col+a] = true;
                        }
                    }

                    if (row == n-1) { // 마지막 줄에 퀸 배치한 경우
                        answer++;
                        exitFlag = true;
                    }

                    for (int i=0; i<n; i++){
                        for (int j=0; j<n; j++){
                            cout << allowed[i][j] << " ";
                        }
                        cout << "\n";
                    }

                    break;

                } else if (col == n-1) {
                    exitFlag = true;
                }
            }
            if (exitFlag) break; 
        }
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    // solution 함수 호출 및 결과 출력
    int result = solution(n);
    cout << "The number of solutions for " << n << "-Queens is: " << result << endl;

    return 0;
}