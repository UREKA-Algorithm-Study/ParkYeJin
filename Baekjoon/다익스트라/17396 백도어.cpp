#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 10000000001

int N, M;
bool flag[100001]; // 상대 시야에 보이는지

vector<long long> dist;
vector<pair<int, int>> edge[100001];

priority_queue<pair<long long, int>> pq;

void dijkstra() {
  dist.resize(N, INF);
  dist[0] = 0;
  pq.push({0, 0}); // 가중치, 정점

  while (!pq.empty()) {
    long long cost = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    // 상대 시야에 보이거나, 이미 최단경로를 체크한 노드인 경우
    if (flag[now] || dist[now] < cost)
      continue;
    for (int i = 0; i < edge[now].size(); i++) {
      int next = edge[now][i].first;
      long long nextcost = edge[now][i].second;

      if (dist[next] > dist[now] + nextcost) {
        dist[next] = dist[now] + nextcost;
        pq.push({-dist[next], next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  /*
    0 분기점이 상대의 시야에 보이지 않음
    1 보임
  */
  cin >> N >> M; //분기점의 수, 분기점들을 잇는 길의 수
  for (int i = 0; i < N; i++) {
    cin >> flag[i];
  }
  for (int i = 0; i < M; i++) {
    int a, b, t; // a번째 분기점과 b번째 분기점 사이를 지나는데 t만큼 시간 걸림
    cin >> a >> b >> t;
    edge[a].push_back({b, t});
    edge[b].push_back({a, t});
  }
  dijkstra();

  if (dist[N - 1] != INF)
    cout << dist[N - 1];
  else
    cout << -1; // 상대 넥서스까지 갈 수 없음
}