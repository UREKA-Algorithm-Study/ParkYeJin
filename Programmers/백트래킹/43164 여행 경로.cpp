#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector <string> v;
vector<vector<string>> answer;

bool visited[10001]; // 여행 경로

void dfs(string end, int idx, vector<vector<string>> &tickets){
    if (idx == tickets.size()) {
        v.push_back(end);
        answer.push_back(v);
        v.pop_back();
        return;
    }
    for(int i = 0; i < tickets.size(); i++){
        if (!visited[i] && end == tickets[i][0]) {
            visited[i] = true;
            v.push_back(end);
            dfs(tickets[i][1], idx + 1, tickets);
            visited[i] = false;
            v.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    for(int i = 0; i < tickets.size(); i++){
        v.clear();
        memset(visited, 0, sizeof(visited));
        if (tickets[i][0] == "ICN") {
            visited[i] = true;
            v.push_back("ICN");
            dfs(tickets[i][1], 1, tickets);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer[0];
}