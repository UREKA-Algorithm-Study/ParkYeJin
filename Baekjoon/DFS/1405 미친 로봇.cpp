#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int num;
double E, W, S, N; 
int map[30][30];
bool visited[30][30];

double perSum = 0; // 갔던 곳을 안 가는 확률

void dfs(int x, int y, int cnt, double per) {
  visited[x][y] = true;

  if (cnt == num) {
    perSum += per;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (visited[nx][ny])
      continue;

    if (i == 0)
      dfs(nx, ny, cnt + 1, per * (E * 0.01));
    else if (i == 1)
      dfs(nx, ny, cnt + 1, per * (W * 0.01));
    else if (i == 2)
      dfs(nx, ny, cnt + 1, per * (S * 0.01));
    else if (i == 3)
      dfs(nx, ny, cnt + 1, per * (N * 0.01));

    visited[nx][ny] = false;
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> num >> E >> W >> S >> N;
  dfs(15, 15, 0, 1.0);

  cout.precision(10);
  cout << fixed << perSum;

  return 0;
}