#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int N, K;
int dist[MAX + 1]; // 최단 거리
int pre[MAX + 1]; // 경로 추적
int cnt[MAX + 1]; // 어떻게 이동해야 되는지

vector <int> route;

void bfs(){
  queue <int> q;
  q.push(N); // 현재 위치
  dist[N] = 1;

  while(!q.empty()) {
    int now = q.front();
    q.pop();

    // 도착할 경우
    if (now == K) break;
    for(int next : {now - 1, now + 1, now * 2}) {
      if (0 <= next && next <= MAX) {
        if (!dist[next]) {
          q.push(next);
          dist[next] = dist[now] + 1;
          pre[next] = now;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> K;
  bfs();
  cout << dist[K] - 1 << "\n" ;

  // 추적 경로
  vector <int> v;
  for(int i = K; i != N; i = pre[i]) {
    v.push_back(i);
  }
  v.push_back(N);

  reverse(v.begin(), v.end());
  for(int iter : v) cout << iter << " ";

  return 0;
} 