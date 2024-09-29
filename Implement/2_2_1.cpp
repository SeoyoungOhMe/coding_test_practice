#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){

    string input;
    cin >> input;

    char col;
    int row;

    col = input[0];
    row = input[1]- '0';

    int cnt = 0;

    if (col >= 'c' && row >= 2){//좌
        cnt++;
    }
    if (col >= 'c' && row <= 7){
        cnt++;
    }
    if (col <= 'f' && row >= 2){//우
        cnt++;
    }
    if (col <= 'f' && row <= 7){
        cnt++;
    }
    if (col >= 'b' && row >= 3){//상
        cnt++;
    }
    if (col <= 'g' && row >= 3){
        cnt++;
    }
    if (col >= 'b' && row <= 6){//하
        cnt++;
    }
    if (col <= 'g' && row <= 6){
        cnt++;
    }

    cout << cnt;

    return 0;
}