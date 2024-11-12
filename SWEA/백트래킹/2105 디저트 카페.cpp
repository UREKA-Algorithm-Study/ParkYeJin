#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[21][21];
const int dx[] = {-1, -1, 1, 1};
const int dy[] = {-1, 1, 1, -1};

bool desert[101];
int res;

void dfs(int x, int y, int sx, int sy, int dir, int depth, int dcnt) {
    if (x == sx && y == sy && depth > 0) {
        res = max(res, depth);
        return;
    }
    // 방향 다 돌았으면
    if (dcnt == 4) return;
    // 방문한 곳
    if (desert[arr[x][y]]) return;

    desert[arr[x][y]] = true;

    // 방향 전환 없이 고
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
        dfs(nx, ny, sx, sy, dir, depth + 1, dcnt);
    }
    // 방향 전환하고 고
    int nextDir = (dir + 1) % 4;
    nx = x + dx[nextDir];
    ny = y + dy[nextDir];
    if (nextDir != dir && nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
        dfs(nx, ny, sx, sy, nextDir, depth + 1, dcnt + 1);
    }

    desert[arr[x][y]] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T, TC = 1;
    cin >> T;
    while (T--) {
      cin >> N;
      for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
              cin >> arr[i][j];
          }
      }

      res = -1;
      for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
              for(int d = 0; d < 4; d++) {
                fill(desert, desert + 101, false);
                dfs(i, j, i, j, d, 0, 0);
              }
          }
      }

      cout << "#" << TC << " " << res << '\n';
      TC++;
    }

    return 0;
}
