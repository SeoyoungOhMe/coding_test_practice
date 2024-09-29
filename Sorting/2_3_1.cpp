#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> student; // std::vector를 사용하여 키-값 쌍을 저장

    for (int i = 0; i < n; ++i) {
        string value;
        int key;

        cin >> value >> key;

        // 키와 값을 std::pair로 삽입
        student.push_back(make_pair(value, key));
    }

    // 저장된 학생들의 점수를 출력
    for (const auto& p : student) {
        cout << p.first << " " << p.second << endl; // 값과 점수를 출력
    }

    return 0;
}
