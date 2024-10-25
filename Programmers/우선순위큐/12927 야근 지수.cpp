#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

// 우선순위 큐

using namespace std;

priority_queue <int> q;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i = 0; i < works.size(); i++){
        q.push(works[i]);    
    }
    while(n--) {
        int now = q.top();
        q.pop();
        
        now--;
        if (now < 0) now = 0;
        q.push(now);
    }
    
    while(!q.empty()){
        answer += pow(q.top(), 2);
        cout << q.top() << " ";
        q.pop();
    }
    
    return answer;
}