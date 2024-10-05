#include <vector>
#include <iostream>
#include <cctype>

using namespace std;


int solution(string &letters) {
    bool lowercase[26] = {false};
    bool uppercase[26] = {false};
    vector<bool> answer(26, false);

    for (char ch : letters) {
        if (islower(ch)) {
            if (uppercase[ch - 'a']) {
                answer[ch - 'a'] = false;
            }
            lowercase[ch - 'a'] = true;
        } else if (isupper(ch)) {
            if (lowercase[ch - 'A'] && !uppercase[ch - 'A']) {
                answer[ch - 'A'] = true;
            }
            uppercase[ch - 'A'] = true;
        }   
    }

    int cnt = 0;
    for (bool ans : answer) {
        if (ans) cnt++;
    }

    return cnt;
}

int main() {
    
    // 예제 문자열
    string test1 = "aaAbcCABBc";
    string test2 = "xyzXYZabcABC";
    string test3 = "ABCabcAefG";

    // 각 문자열에 대해 결과 출력
    cout << solution(test1) << endl; // 2
    cout << solution(test2) << endl; // 6
    cout << solution(test3) << endl; // 0

    return 0;
}