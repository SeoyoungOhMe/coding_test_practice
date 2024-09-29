#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{

    int answer = 0;
    vector<vector<int>> dp;
    int row = board.size();
    int col = (row > 0) ? board[0].size() : 0;
    dp.assign(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++){
        for  (int j = 0; j < col; j++){
            if (board[i][j] == 1) {
                if (i==0 || j==0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
            }
            cout << "dp[" << i << j << "] = " << dp[i][j] << " ";
        }
        cout << "\n";
    }
   
    

    for (int i = 0; i < row; i++){
        for (int j : dp[i]){
            cout << j << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++){
        answer = max(answer, *max_element(dp[i].begin(), dp[i].end()));
    }

    return answer*answer;
}

int main() {
    // 테스트 케이스 1
    vector<vector<int>> board1 = {
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {0, 0, 1, 0}
    };

    // 테스트 케이스 2
    vector<vector<int>> board2 = {
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    // 결과 출력
    // cout << "Test Case 1: " << solution(board1) << endl; // 예상 출력: 9
    cout << "Test Case 2: " << solution(board2) << endl; // 예상 출력: 9

    return 0;
}