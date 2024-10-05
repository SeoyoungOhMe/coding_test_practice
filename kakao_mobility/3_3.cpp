#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int>& A) {
    int n = A.size() / 2;  // 도미노 쌍의 개수
    int answer = n;  // 처음엔 모든 도미노가 남아있음
    
    // 두 개씩 비교하면서 연속된 도미노의 짝을 찾음
    for (int i = 0; i < A.size() - 2; i += 2) {
        // 현재 도미노의 오른쪽 숫자(A[i+1])가 다음 도미노의 왼쪽 숫자(A[i+2])와 같은지 확인
        if (A[i + 1] == A[i + 2]) {
            answer--;  // 도미노 쌍을 하나 제거
            i += 2;  // 이미 제거한 도미노를 건너뜀
        }
    }
    
    return answer;
}

int main() {
    vector<int> A = {2, 4, 1, 3, 4, 6, 2, 4, 1, 6};  // 예시 입력
    int result = solution(A);  // solution 함수 호출

    cout << result << endl;  // 결과 출력

    return 0;
}
