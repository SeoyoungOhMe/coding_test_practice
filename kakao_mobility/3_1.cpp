#include <vector>
#include <iostream>
#include <string>

using namespace std;

int answer;

bool isNextSame(int i, int j, vector<int> &A) {
    return (A[j] == A[i]);
}

void popDomino(int index, vector<int> &A) {
    if (index == A.size()) {
        return;
    }

    for (int i=2; i<A.size(); i+=2) {
        for (int j=1; j<i; j+=2) {
            if (isNextSame(i, j, A)) {
                popDomino(index+2, A);
            }
        }
    }
}

int solution(vector<int> &A) {
    answer = A.size()/2;
    popDomino(0, A);

    return answer;
}

int main() {
    vector<int> A = {2, 4, 1, 3, 4, 6, 2, 4, 1, 6};
    int result = solution(A);  // solution 함수 호출
    
    cout << result << endl;  // 결과 출력
    
    return 0;
}