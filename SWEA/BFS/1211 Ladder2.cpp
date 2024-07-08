#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101][101];

int bfs(int x, int y) {
    queue <pair <int, int>>q;
    memset(visited, 0, sizeof(visited));

    q.push({ x, y });
    visited[x][y] = true;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;

        // 왼쪽에 1이 있을 경우
        int ny = y - 1;
        if (ny >= 0 && ny <= 99) {
            if (arr[x][ny] == 1 && !visited[x][ny]) {
                q.push({ x, ny });
                visited[x][ny] = true;
                continue;
            }
        }
        // 오른쪽에 1이 있을 경우
        ny = y + 1;
        if (ny >= 0 && ny <= 99) {
            if (arr[x][ny] == 1 && !visited[x][ny]) {
                q.push({ x, ny });
                visited[x][ny] = true;
                continue;
            }
        }
        // 양쪽에 1이 없을 경우 아래로
        int nx = x + 1;
        if (nx <= 99 && arr[nx][y] == 1 && !visited[nx][y]) {
            q.push({ nx, y });
            visited[nx][y] = true;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 10, Tnum = 1;
    while (T--) {
        cin >> Tnum;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
        // 시작지점에서 bfs
        int res = 1e9, cnt, idx;
        for (int i = 0; i < 100; i++) {
            if (arr[0][i] == 1) {
                cnt = bfs(0, i);
                if (res >= cnt) {
                    res = cnt;
                    idx = i;
                }
            }
        }
        cout << '#' << Tnum << ' ' << idx << '\n';
        Tnum++;
    }
}