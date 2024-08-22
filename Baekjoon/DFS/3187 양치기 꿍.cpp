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

pair<int, int> dfs(int x, int y) {
  visitied[x][y] = true;

  int vcnt = 0;
  int kcnt = 0;

  if (str[x][y] == 'v') vcnt++;
  else if (str[x][y] == 'k') kcnt++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1)
      continue;

    if (str[nx][ny] != '#' && !visitied[nx][ny]) {
      pair<int, int> result = dfs(nx, ny);
      kcnt += result.first;
      vcnt += result.second;
    }
  }
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
        pair<int, int> p = dfs(i, j);
        if (p.first > p.second) {
          sumK += p.first;
        } else {
          sumV += p.second;
        }
      }
    }
  }
  cout << sumK << " " << sumV;

  return 0;
}
