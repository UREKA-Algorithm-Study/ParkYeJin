#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    int sum = 0;
    priority_queue <int, vector<int>, greater<int>> pq; 
    
    for(int i = 0; i < enemy.size(); i++){
        pq.push(enemy[i]);
        
        if (k < pq.size()) {
            sum += pq.top();
            pq.pop();
            
            if (sum > n) return i;
        }
    }
    // 모든 공격 막을 수 있는 경우
    return enemy.size();
}