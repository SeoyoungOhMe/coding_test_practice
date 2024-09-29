#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int n = board.size();
    vector<int> top_row(n+1, 0);

    for (int i=0; i< n; i++){
        for (int j=0; j<n; j++){
            if (board[j][i] != 0){
                top_row[i+1] = j+1;
                break;
            }
        }
    }

    for (const int& p: top_row){
        cout << p;
    }
    cout << "\n";

    cout << top_row[1] << "\n";

    stack<int> s;
    int new_board, new_row =0;;

    for (int i=0; i<moves.size(); i++){

        cout << "i:" << i << "\n";

        if (top_row[moves[i]] == 0) {
            continue;
        }

        for (const int& p: top_row){
            cout << p;
        }
        cout << "\n";

        new_row = top_row[moves[i]]-1;
        new_board= board[new_row][moves[i]-1];
        cout << "new board:" << new_board << "\n";
        cout << "top_row[1]:" << top_row[1] << "\n";


        if (s.empty() && new_board != 0){
            s.push(new_board);
            if (top_row[moves[i]] < n){
                top_row[moves[i]]++;
            } else {
                top_row[moves[i]] = 0;
            }

            cout << "1" << "\n";
            cout << "new_board:" << new_board << "\n";
        } 
        else if(s.empty() && new_board == 0){

            cout << "2" << "\n";
            continue;
        }
        else{
            if (new_board == s.top()){
                s.pop();
                answer += 2;
                cout << moves[i]<<"\n";
                cout << "top_row[moves[i]]: " << top_row[moves[i]] << "\n";

                if (top_row[moves[i]]  < n){
                    top_row[moves[i]]++;
                } else {
                    top_row[moves[i]] = 0;
                }
                
                for (const int& p: top_row){
                    cout << p;
                }
                cout << "\n";

                cout << "3" << "\n";
            } else { 
                s.push(new_board);
                if (top_row[moves[i]]  < n){
                    top_row[moves[i]]++;
                } else {
                    top_row[moves[i]] = 0;
                }


                cout << "4" << "\n";
                cout << "new_board:" << new_board << "\n";
            }
        }

    }

    return answer;
}

int main() {
    // 예시 보드
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };

    // 예시 moves
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    // solution 함수 호출 및 결과 출력
    int result = solution(board, moves);
    cout <<"ans:" << result;

    return 0;
}