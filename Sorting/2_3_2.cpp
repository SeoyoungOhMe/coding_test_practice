#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> student; // std::map을 사용하여 이름과 점수를 저장

    for (int i = 0; i < n; ++i) {
        string value;
        int key;

        cin >> value >> key;

        // 이름과 점수를 map에 삽입
        student[value] = key;
    }

    // 저장된 학생들의 점수를 출력 (이름 순으로 자동 정렬됨)
    for (const auto& p : student) {
        cout << p.first << " "; // 이름과 점수를 출력
    }

    return 0;
}
