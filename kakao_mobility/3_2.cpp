#include <vector>
#include <iostream>

using namespace std;

// 연속된 도미노 조각을 삭제하는 함수
void popDomino(int& answer, vector<int>& A) {
    // A.size()는 도미노 조각의 개수의 2배 (2*n)
    for (int i = 0; i < A.size() - 2; i += 2) {
        // 현재 도미노의 오른쪽 숫자가 다음 도미노의 왼쪽 숫자와 같은지 확인
        if (A[i + 1] == A[i + 2]) {
            // 만약 같다면, 이 도미노 두 조각을 삭제 (즉, 제거된 것처럼 생각)
            answer -= 1; // 전체 남은 도미노 쌍 개수 감소
            i += 2;      // 다음으로 넘어가서 연속된 도미노 확인
        }
    }
}

int solution(vector<int>& A) {
    // 처음엔 모든 도미노가 남아있는 상태 (전체 도미노 쌍의 개수)
    int answer = A.size() / 2;
    // 도미노를 재배열하거나 연속된 조각을 삭제
    popDomino(answer, A);
    return answer;
}

int main() {
    vector<int> A = {2, 4, 1, 3, 4, 6, 2, 4, 1, 6};  // 예시 입력
    int result = solution(A);  // solution 함수 호출

    cout << result << endl;  // 결과 출력

    return 0;
}
