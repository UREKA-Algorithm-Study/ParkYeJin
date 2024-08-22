#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// k 양, v 늑대

int R, C;
bool visitied[251][251];
string str[251];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

pair<int, int> bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  visitied[x][y] = true;

  int vcnt = 0;
  int kcnt = 0;

  if (str[x][y] == 'v') vcnt++;
  else if (str[x][y] == 'k') kcnt++;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1)
        continue;

      if (str[nx][ny] != '#' && !visitied[nx][ny]) {
        if (str[nx][ny] == 'k') {
          kcnt++;
        } else if (str[nx][ny] == 'v') {
          vcnt++;
        }
        q.push({nx, ny});
        visitied[nx][ny] = true;
      }
    }
  }

  if (kcnt > vcnt)
    vcnt = 0;
  else
    kcnt = 0;

  return {kcnt, vcnt};
}

int main() {

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> str[i];
  }

  int sumV = 0;
  int sumK = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (str[i][j] != '#' && !visitied[i][j]) {
        pair<int, int> p = bfs(i, j);
        sumK += p.first;
        sumV += p.second;
      }
    }
  }
  cout << sumK << " " << sumV;

  return 0;
}
