#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string input;
    cin >> input;
    map<char, int> freq;
    int oddCnt = 0;
    char oddChar;

    // 각 문자 빈도수 계산
    for (char c : input){
        freq[c]++;
    }

    // 홀수 개수 문자 개수 체크
    for (auto& p : freq){
        if (p.second % 2 != 0){
            oddCnt++;
            oddChar = p.first;
        }
    }

    // 홀수 문자가 2개 이상이면 팰린드롬 불가
    if (oddCnt > 1){
        cout << "I'm Sorry Hansoo";
    }
    else {
        string half = "";

        // 빈도수의 절반을 저장하여 팰린드롬의 절반을 구성
        for (auto& p : freq){
            half += string(p.second / 2, p.first);
        }

        // 팰린드롬의 앞부분
        cout << half;

        // 가운데 문자가 필요하다면 추가
        if (oddCnt == 1) {
            cout << oddChar;
        }

        // 팰린드롬의 뒷부분 (앞부분을 뒤집어서 출력)
        reverse(half.begin(), half.end());
        cout << half;
    }

    return 0;
}
