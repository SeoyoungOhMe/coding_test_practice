#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_set<int> uset;

    uset.insert(1);
    uset.insert(2);
    uset.insert(3);

    if (uset.find(2) != uset.end()) {
        cout << "uset find";
    }

    uset.erase(1);

    for (int x: uset) {
        cout << x;
    }
    
    return 0;
}