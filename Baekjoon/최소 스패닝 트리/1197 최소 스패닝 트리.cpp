#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int parent[10001];

vector <pair <int, pair <int, int>>> graph;

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int V, E;
  cin >> V >> E;

  for(int i = 1; i <= V; i++){
    parent[i] = i;
  }
  for (int i = 0; i < E; i++) {
    int A, B, C; // A번 정점, B번 정점, C 가중치
    cin >> A >> B >> C;
    graph.push_back({C, {A, B}});
  }
  // 가중치를 기준으로 정렬
  sort(graph.begin(), graph.end());

  int sum = 0; // 가중치 합
  int num = 0; // 연결된 노드 개수
  for (int i = 0; i < E; i++){
    int cost = graph[i].first;
    int start = graph[i].second.first;
    int end = graph[i].second.second;

    int a = getParent(start);
    int b = getParent(end);

    if (a == b) continue;
    if (a < b) parent[b] = a;
    else parent[a] = b;

    sum += cost;
    num++;

    if (num == V - 1) {
      cout << sum;
      break;
    }
  }
}