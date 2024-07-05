#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101][101];

bool game(int idx) {
  queue<pair<int, int>> q;
  memset(visited, 0, sizeof(visited));

  q.push({0, idx});
  visited[0][idx] = true;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    // 왼쪽 다리 있을 경우
    int ny = y - 1;
    if (ny >= 0 && ny <= 99) {
      if (arr[x][ny] == 1 && !visited[x][ny]) {
        q.push({x, ny});
        visited[x][ny] = true;
        continue;
      }
    }
    // 오른쪽 다리 있을 경우
    ny = y + 1;
    if (ny >= 0 && ny <= 99) {
      if (arr[x][ny] == 1 && !visited[x][ny]) {
        q.push({x, ny});
        visited[x][ny] = true;
        continue;
      }
    }
    // 양쪽 다리 없을 경우 아래로 내려감
    int nx = x + 1;
    // 목적지 찾음
    if (nx < 100) {
      if (arr[nx][y] == 2) {
        return true;
      } else if (arr[nx][y] == 1) {
        q.push({nx, y});
        visited[nx][y] = true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T = 10;
  while (T--) {
    int Tnum;
    cin >> Tnum;

    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        cin >> arr[i][j];
      }
    }
    // 1번째 행에서 막대기 시작되는 지점
    bool res = false;
    for (int i = 0; i < 100; i++) {
      if (arr[0][i] == 1) {
        res = game(i);
        if (res) {
          cout << '#' << Tnum << ' ' << i << "\n";
          break;
        }
      }
    }
  }
}