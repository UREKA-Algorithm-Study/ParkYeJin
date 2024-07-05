#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int R, C;
char arr[1001][1001];
bool fvisited[1001][1001];
bool jvisited[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> jq; // 지훈
queue<pair<int, int>> fq; // 불

void fireBfs() {
  int cnt = fq.size();
  while (cnt--) {
    int x = fq.front().first;
    int y = fq.front().second;
    fq.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > R || ny < 1 || ny > C)
        continue;
      if (arr[nx][ny] != '#' && !fvisited[nx][ny]) {
        arr[nx][ny] = 'F';
        fq.push({nx, ny});
        fvisited[nx][ny] = true;
      }
    }
  }
}

int jihoonBfs() {
  int time = 0;
  while (!jq.empty()) {
    time++;
    fireBfs();

    int cnt = jq.size();
    while (cnt--) {
      int x = jq.front().first;
      int y = jq.front().second;
      jq.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > R || ny < 1 || ny > C)
          return time;
        if (arr[nx][ny] == '.' && !jvisited[nx][ny]) {
          arr[nx][ny] = 'J';
          jq.push({nx, ny});
          jvisited[nx][ny] = true;
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> R >> C;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'J') {
        jq.push({i, j});
      } else if (arr[i][j] == 'F') {
        fq.push({i, j});
      }
    }
  }

  int time = jihoonBfs();
  if (time == -1)
    cout << "IMPOSSIBLE";
  else
    cout << time;
}