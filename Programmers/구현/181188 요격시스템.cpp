#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 
  1 ≤ targets의 길이 ≤ 500,000
  단순 1차원 배열 카운팅 x
*/

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());
    
    int cur = targets[0][1]; // 첫번째 배열의 e
    for(int i = 1; i < targets.size(); i++){
        int s = targets[i][0];
        int e = targets[i][1];
        
        if (cur > s) cur = min(cur, e);
        else {
            cur = e;
            answer++;
        }
    }
    
    return answer;
}