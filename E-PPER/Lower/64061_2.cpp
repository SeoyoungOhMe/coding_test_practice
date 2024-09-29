// gpt의 리팩토링

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; // 인형을 담을 스택

    int n = board.size(); // 보드의 크기

    // moves 순서대로 처리
    for (int move : moves) {
        int col = move - 1; // 열 값은 1부터 시작하므로 -1

        // 각 열에서 맨 위의 인형 찾기
        for (int row = 0; row < n; ++row) {
            if (board[row][col] != 0) { // 인형이 있는 경우
                int doll = board[row][col]; // 인형 선택
                board[row][col] = 0; // 인형을 뽑았으므로 빈 칸으로 만듦

                // 스택이 비어있지 않고, 스택의 최상단 인형과 같다면 터뜨림
                if (!s.empty() && s.top() == doll) {
                    s.pop(); // 인형 제거
                    answer += 2; // 두 개의 인형이 터졌으므로 2점 추가
                } else {
                    s.push(doll); // 그렇지 않으면 인형을 스택에 추가
                }
                break; // 인형을 뽑았으므로 다음 move로 이동
            }
        }
    }

    return answer;
}

int main() {
    // 예시 보드
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };

    // 예시 moves
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    // solution 함수 호출 및 결과 출력
    int result = solution(board, moves);
    cout << "정답: " << result << endl;

    return 0;
}
