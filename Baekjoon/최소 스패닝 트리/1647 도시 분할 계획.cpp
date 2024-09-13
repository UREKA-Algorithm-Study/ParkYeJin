// 크루스칼 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, result, maxCost;
int parent[100001];

vector <pair <int, pair <int, int>>> v;

void init(){
  for(int i = 1; i <= N; i++){
    parent[i] = i;
  }
}

int getPrent(int x){
  if (parent[x] == x) return x;
  else return parent[x] = getPrent(parent[x]);
}

void unionParent(int x, int y){
  x = getPrent(x);
  y = getPrent(y);
  if (x > y) swap(x, y);
  parent[y] = x;
}

void kruskal(){
  for(int i = 0; i < M; i++){
    int cost = v[i].first;
    int start = v[i].second.first;
    int end = v[i].second.second;

    int a = getPrent(start);
    int b = getPrent(end);

    if (a == b) continue;
    else {
      maxCost = max(maxCost, cost);
      result += cost;
      unionParent(a, b);
    }
  }
}

int main(){
  cin >> N >> M;

  init();
  for(int i = 0; i < M; i++){
    int A, B, C;
    cin >> A >> B >> C;
    v.push_back({C, {A, B}});
  }
  sort(v.begin(), v.end());
  kruskal();
  cout << result - maxCost << "\n";

  return 0;
}


// 프림 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, result, maxCost;
vector<pair<int, int>> edge[100001];
bool visited[100001];

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void prim(){
  visited[1] = true;
  for(int i = 0; i < edge[1].size(); i++){
    int next = edge[1][i].first;
    int cost = edge[1][i].second;
    pq.push({cost, next});
  }

  while(!pq.empty()){
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (!visited[cur]) {
      visited[cur] = true;
      result += cost;
      maxCost = max(maxCost, cost);

      for(int i = 0; i < edge[cur].size(); i++){
        int next = edge[cur][i].first;
        int nextcost = edge[cur][i].second;
        if (!visited[next]) {
          pq.push({nextcost, next});
        }
      }
    }
  }
}

int main(){
  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    edge[from].push_back({to, cost});
    edge[to].push_back({from, cost});
  }
  prim();
  cout << result - maxCost;

  return 0;
}