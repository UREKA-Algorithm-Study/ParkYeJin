#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// {소요시간, 요청시점} 소요시간 오름차순
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end()); // 요청시점 오름차순
    
    int sum = 0, time = 0, cnt = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int required = pq.top().first; // 소요시간
        int start = pq.top().second; // 요청시점
        pq.pop();
        
        sum += time - start + required; // 저번 끝나는 시간 - 요청시점 + 소요시간
        time += required;
        
        while(cnt < jobs.size() && time >= jobs[cnt][0]) {
            pq.push({jobs[cnt][1], jobs[cnt][0]});
            cnt++;
        }
        if (pq.empty() && cnt < jobs.size()) {
            time = jobs[cnt][0];
            pq.push({jobs[cnt][1], jobs[cnt][0]});
            cnt++;
        }
    }
    answer = sum / jobs.size();
    
    return answer;
}