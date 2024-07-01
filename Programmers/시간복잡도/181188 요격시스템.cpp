#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    int cur = targets[0][1]; // 현재 두번째값
    for(int i = 1; i < targets.size(); i++){
        int first = targets[i][0];
        int second = targets[i][1];
        
        if (cur > first) cur = min(cur, second);
        else {
            answer++;
            cur = second;
        }
    }
    
    return answer;
}