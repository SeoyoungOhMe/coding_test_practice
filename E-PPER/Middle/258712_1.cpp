#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

vector<vector<int>> arrGifts;
map<string, int> personNum;
vector<vector<int>> arrGiftsDegree;
vector<int> giftsCount;

void fillArrGifts(vector<string>& gifts) {
    for (const auto& gift : gifts) {
        istringstream iss(gift);
        string givePerson, getPerson;

        iss >> givePerson >> getPerson;

        int arrGiftsY = personNum[givePerson];
        int arrGiftsX = personNum[getPerson];
        arrGifts[arrGiftsY][arrGiftsX]++;
    }
}

void fillArrGiftsDregree(int friendSize) {
    for (int i = 0; i < friendSize; i++){
        arrGiftsDegree[i][0] = accumulate(arrGifts[i].begin(), arrGifts[i].end(), 0);
        
        for (int j = 0; j < friendSize; j++){
            arrGiftsDegree[i][1] += arrGifts[j][i];
        }

        arrGiftsDegree[i][2] = arrGiftsDegree[i][0] - arrGiftsDegree[i][1];
    }
}

void fillGiftsCount(int friendSize) {
    for (int i = 0; i < friendSize; i++){
        for (int j = i+1; j < friendSize; j++){

            int giveCount = arrGifts[i][j];
            int getCount = arrGifts[j][i];

            if ((giveCount > 0 || getCount > 0) && giveCount != getCount){
                if (giveCount > getCount) giftsCount[i]++;
                else giftsCount[j]++;
            } else {

                int giveDegreeCount = arrGiftsDegree[i][2];
                int getDegreeCount = arrGiftsDegree[j][2];

                if (giveDegreeCount != getDegreeCount) {
                    if (giveDegreeCount > getDegreeCount) giftsCount[i]++;
                    else giftsCount[j]++;
                } else continue;
            }
        }
        }
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int friendSize = friends.size();

    arrGifts.assign(friendSize, vector<int>(friendSize, 0));
    
    int i = 0;
    for (string p: friends){
        personNum[p] = i;
        i++;
    }
    fillArrGifts(gifts);


    arrGiftsDegree.assign(friendSize, vector<int>(3, 0));
    fillArrGiftsDregree(friendSize);

    giftsCount.assign(friendSize, 0);

    fillGiftsCount(friendSize);

    answer = *max_element(giftsCount.begin(), giftsCount.end());

    return answer;
}

int main() {
    vector<string> friends1 = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts1 = {
        "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", 
        "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"
    };

    for (const auto& gift : gifts1) {
        istringstream iss(gift);
        string first, second;

        iss >> first >> second;
    }

    int result1 = solution(friends1, gifts1);
    cout << "Result: " << result1 << endl; 

    return 0;
}