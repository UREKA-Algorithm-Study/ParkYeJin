#include<iostream>
#include<vector>

using namespace std;

struct Point {
    int x, y;
};

int n, m, ans;
int arr[5][5];
bool visited[5][5];
Point dest[16];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(Point cur, int cnt) {
    int x = cur.x;
    int y = cur.y;
    
    if ((x == dest[cnt].x) && (y == dest[cnt].y)) {
        if (cnt == (m - 1)) {
            ans++;
            return;
        }
        cnt++;
    }

    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (!visited[nx][ny] && !arr[nx][ny]){
            dfs({nx, ny}, cnt);
        }
    }
    visited[x][y] = false;
}

int main(int argc, char** argv)
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        dest[i] = {x, y};
    }

    dfs(dest[0], 1);
    cout << ans;
    
   return 0;
}