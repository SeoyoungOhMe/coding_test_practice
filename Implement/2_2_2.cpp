#include <iostream>
#include <string>

using namespace std;

int main() {
    // 체스판의 위치 입력
    string input;
    cin >> input;

    // 입력된 위치를 좌표로 변환
    int x = input[0] - 'a' + 1;  // 열 변환 (a ~ h -> 1 ~ 8)
    int y = input[1] - '1' + 1;  // 행 변환 (1 ~ 8 -> 1 ~ 8)

    // 나이트가 이동할 수 있는 8가지 방향
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    int count = 0;

    // 8가지 방향에 대해 나이트가 이동 가능한지 확인
    for (int i = 0; i < 8; i++) {
        int nextX = x + moves[i][0];
        int nextY = y + moves[i][1];

        // 이동 후 좌표가 체스판 안에 있는지 확인
        if (nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8) {
            count++;
        
        }
    }

    // 결과 출력
    cout << count;

    return 0;
}
