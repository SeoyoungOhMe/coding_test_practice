#include <iostream>
#include <vector>
#include <string>

using namespace std;

void moveKnight(vector<vector<int>>& board, int& answer, int row, int col) {

    vector<int> delX = {-2, -2, 2, 2, -1, 1, -1, 1};
    vector<int> delY = {-1, 1, -1, 1, -2, -2, 2, 2};
    
    for (int i=0; i<8; i++) {
        int x = col + delX[i];
        int y = row + delY[i];

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            answer++;
        }
    }
}

int main() {

    // 초기화 : 2차원 board, queen의 row, col, 나이트가 이동하는 경우의 수(ans)
    vector<vector<int>> board(8, vector<int>(8, 0));
    int row, col;
    int answer = 0;
    string input;

    // string 입력받고 queen 위치 초기화
    cin >> input;
    row = input[1] - '0' - 1; // '1'-> 0
    col = input[0] - 'a'; // 'a'-> 0
    
    // moveKnight 호출해서 answer 계산하기
    moveKnight(board, answer, row, col);
    
    // answer 출력하기
    cout << answer << "\n";
    
    return 0;
}