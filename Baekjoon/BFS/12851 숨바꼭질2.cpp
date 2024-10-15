// case1. queue <int> q

#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int N, K;
int dist[MAX + 1]; // 가장 빠른 시간
int cnt[MAX + 1]; // 가장 빠른 시간으로 찾는 방법의 수

void bfs(){
  queue <int> q;
  q.push(N);
  dist[N] = 1;
  cnt[N] = 1;

  while(!q.empty()) {
    int now = q.front();
    q.pop(); 

    for(int next : {now - 1, now + 1, now * 2}){
      if (0 <= next && next <= MAX) {
        if (!dist[next]) {
          q.push(next);
          dist[next] = dist[now] + 1;
          cnt[next] += cnt[now];
        } 
        // 방문했지만, 최단 경로일 경우 cnt
        else if (dist[next] == dist[now] + 1) {
          cnt[next] += cnt[now];
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
  cout << dist[K] - 1 << "\n" << cnt[K];

  return 0;
} 



// case2. queue <pair <int, int>> 

#include <bits/stdc++.h>
using namespace std;

int N, K;
int cnt, res; // 방법의 수, 시간
bool visited[100001];

void bfs(){
  queue <pair <int, int>> q; // N, time
  q.push({N, 0});
  visited[N] = 1;

  while(!q.empty()) {
    int now = q.front().first;
    int time = q.front().second;
    visited[now] = 1;
    q.pop(); 

    // 동생 위치 도착
    if (now == K) {
      // 처음
      if (!cnt) {
        res = time; // 동생을 찾는 빠른 시간
        cnt++;
      }
      // 또 다시 도착
      else if (cnt && res == time) {
        cnt++;
      }
    }

    // 후진
    if (now - 1 >= 0 && !visited[now - 1]) {
      q.push({now - 1, time + 1});
    }
    // 전진
    if (now + 1 < 100001 && !visited[now + 1]){
      q.push({now + 1, time + 1});
    }
    // 순간이동
    if (now * 2 < 100001 && !visited[now * 2]){
      q.push({now * 2, time + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> K;
  bfs();
  cout << res << "\n" << cnt;

  return 0;
} 