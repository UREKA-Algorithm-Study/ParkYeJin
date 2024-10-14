// 정답 코드
#include <bits/stdc++.h>
using namespace std;

int N, M, res = 1e9;
int arr[51][51];
int dist[51][51];

vector <pair <int, int>> home; // 집 1 
vector <pair <int, int>> chicken; // 치킨집 2

vector <pair <int, int>> selected; // 선택된 치킨집

// 모든 집(1)에서 선택된 치킨집(2)까지 거리
int distance() {
  memset(dist, 0, sizeof(dist));
  // 집
  for(auto h : home) {
    for(auto s : selected) {
      int num = abs(h.first - s.first) + abs(h.second - s.second);
      if (!dist[h.first][h.second]) {
        dist[h.first][h.second] = num;
      } else {
        dist[h.first][h.second] = min(dist[h.first][h.second], num);
      }
    }
  }

  int sum = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if (arr[i][j] == 1) {
        sum += dist[i][j];
      }
    }
  }
  return sum;
}

void dfs(int idx, int cnt) {
  if (cnt == M) {
    res = min(res, distance());
    return;
  }
  for(int i = idx; i < chicken.size(); i++) {
    selected.push_back({chicken[i].first, chicken[i].second});
    dfs(i + 1, cnt + 1);
    selected.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> arr[i][j];
      if (arr[i][j] == 1) home.push_back({i, j});
      if (arr[i][j] == 2) chicken.push_back({i, j});
    }
  }
  dfs(0, 0);
  cout << res;

  return 0;
} 



// 시간초과
#include <bits/stdc++.h>
using namespace std;

int N, M, res = 1e9;
int arr[51][51];
bool visited[51][51];

int dist[51][51];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

// 모든 집(1)에서 남은 치킨집(2)까지 거리
int distance(int x, int y) {
  memset(dist, 0, sizeof(dist));
  
  queue <pair <int, int>> q;
  q.push({x, y});
  dist[x][y] = 1;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
      // 남아있는 치킨집이라면
      if (visited[nx][ny]) {
        return dist[x][y];
      }
      if (!dist[nx][ny] && !visited[nx][ny]) {
        q.push({nx, ny});
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }
}

void dfs(int cnt) {
  if (cnt == M) {
    int sum = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if (arr[i][j] == 1) {
          sum += distance(i, j);
        }
      }
    }
    res = min(sum, res);
    return;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if (!visited[i][j] && arr[i][j] == 2) {
        visited[i][j] = true;
        dfs(cnt + 1);
        visited[i][j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> arr[i][j];
    }
  }
  dfs(0);
  cout << res;

  return 0;
} 