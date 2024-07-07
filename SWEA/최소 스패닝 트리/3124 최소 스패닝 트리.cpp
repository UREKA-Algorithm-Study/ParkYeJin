#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E, num;
long long sum; 
int parent[100001];

int getParent(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = getParent(parent[x]);
}

void kruskal(vector<pair<int, pair<int, int>>> &edge) {
  sum = 0; // 가중치 합
  num = 0; // 연결된 간선 개수

  for (int i = 0; i < E; i++) {
    int cost = edge[i].first;
    int first = edge[i].second.first;
    int second = edge[i].second.second;

    int a = getParent(first);
    int b = getParent(second);

    if (a == b)
      continue;
    if (a < b)
      parent[b] = a;
    else
      parent[a] = b;

    sum += cost;
    num++;

    // 모든 노드 연결완료
    if (num == V - 1)
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, cnt = 1;
  cin >> T;
  while (T--) {
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edge;

    for (int i = 1; i <= V; i++) {
      parent[i] = i;
    }
    for (int i = 0; i < E; i++) {
      int A, B, C; // 가중치 C
      cin >> A >> B >> C;
      edge.push_back({C, {A, B}});
    }
    sort(edge.begin(), edge.end()); // 가중치로 오름차순

    kruskal(edge);

    cout << '#' << cnt << ' ' << sum << "\n";
    cnt++;
  }
}