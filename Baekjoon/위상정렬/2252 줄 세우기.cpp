#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> graph[32001];
int indegree[32001];

int N, M;
void topology_sort(){
  queue <int> q;

  for(int i = 1; i <= N; i++){
    if (indegree[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    cout << now << " ";
    for(int i = 0; i < graph[now].size(); i++){
      int next = graph[now][i];
      indegree[next]--;
      if (indegree[next] == 0) q.push(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    indegree[B]++;
  }
  topology_sort();
  
  return 0;
}