#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dcnt; // 주사위 개수
bool visited[11];

vector<int> sumA; // A 주사위 조합의 합
vector<int> sumB; // B 주사위 조합의 합

vector<int> bestCombination; // 최적의 주사위 조합
int maxWins = 0; // 최대 승리 횟수

// 선택된 조합에 대해 각 주사위 모든 눈금의 합
void arrSum(int cnt, int sum, vector<int> &s, vector<int> v, vector<vector<int>> dice) {
    if (cnt == dcnt / 2) {
        s.push_back(sum);
        return;
    }
    for(int i = 0; i < 6; i++){
        int newSum = sum + dice[v[cnt]][i];
        arrSum(cnt + 1, newSum, s, v, dice);
    }
}

// 선택된 주사위 조합 저장 후 눈금 합 저장
int calc(vector<vector<int>> dice){
    vector<int> diceA; // A 주사위 조합
    vector<int> diceB; // B 주사위 조합

    // 선택된 주사위 조합 저장
    for(int i = 0; i < dcnt; i++){
        if (visited[i]) diceA.push_back(i);
        else diceB.push_back(i);
    }
    sumA.clear();
    sumB.clear();
    
    // 선택된 주사위 합 저장
    arrSum(0, 0, sumA, diceA, dice);
    arrSum(0, 0, sumB, diceB, dice);
    
    // 이분탐색을 위한 정렬
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());
    
    // A가 이기는 경우 (이분탐색)
    int Awin = 0;
    for(int i = 0; i < sumA.size(); i++){
        int start = 0;
        int end = sumB.size() - 1;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            if (sumB[mid] < sumA[i]) start = mid + 1;
            else end = mid - 1;
        }
        Awin += start;
    }
    return Awin;
}

// A, B가 가져갈 수 있는 주사위 조합 (백트래킹)
void combi(int cnt, int idx, vector<vector<int>> dice){
    if (cnt == dcnt / 2) {
        int Awin = calc(dice); // A가 이기는 경우
        
        if (Awin > maxWins) {
            maxWins = Awin;
            bestCombination.clear();
            for (int i = 0; i < dcnt; i++) {
                if (visited[i]) bestCombination.push_back(i);
            }
        }
        return;
    }
    for(int i = idx; i < dcnt; i++){
        if (!visited[i]) {
            visited[i] = true;
            combi(cnt + 1, i + 1, dice);
            visited[i] = false;
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    dcnt = dice.size(); // 주사위 개수
    combi(0, 0, dice); // A, B가 가져갈 수 있는 주사위 조합 생성
    
    for(auto idx : bestCombination) {
        answer.push_back(idx + 1);
    }
    sort(answer.begin(), answer.end()); // 오름차순 정렬
    
    return answer;
}