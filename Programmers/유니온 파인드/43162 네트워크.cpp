#include <vector>
#include <iostream>
#include <set>

using namespace std;

int parent[201];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    
    if (x > y)  parent[x] = y;
    else parent[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && computers[i][j]){
                unionParent(i + 1, j + 1);
            }
        }
    }
    
    set<int> s;
    for(int i = 1; i <= n; i++){
        if(s.insert(getParent(i)).second){
            answer++;
        }
    }
    return answer;
}