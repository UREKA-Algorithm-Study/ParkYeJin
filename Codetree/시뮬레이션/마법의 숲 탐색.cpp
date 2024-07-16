#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C, K; 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int arr[71][71];
int newArr[71][71];

int westDx[5] = {-1, 0, 1, 1, 2};
int westDy[5] = {-1, -2, -2, -1, -1}; 

int eastDx[5] = {-1, 0, 1, 1, 2};
int eastDy[5] = {1, 2, 1, 2, 1};

int visited[71][71];
bool flag = false;

void mapReset() {
    memset(arr, 0, sizeof(arr));
    memset(newArr, 0, sizeof(newArr));
    flag = true;
}

void blockReset(int x, int y){
    arr[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        arr[nx][ny] = 0;
    }
}

int downHeight(int x, int y) {
    int cnt = 0;
    for(int i = x + 1; i <= R; i++){
        int left = arr[i][y - 1];
        int center = arr[i][y];
        int right = arr[i][y + 1];

        if (!left && !center && !right) cnt++;
        // 블록이 있을 경우 
        else {
            if (center == 1) return i - (x + 1) - 1; // 꼭대기 떨
            else return i - (x + 1); // 양쪽 떨
        }
    }
    // 블록이 없을 경우
    if (cnt == R - x) return R - x - 1;
    else return 0;
}

void down(int &x, int &y, int h, int &dir){
    if (flag) return; // reset 상태면 패스
    x += h; // 떨어진 골렘 위치
    
    // 현재 골렘 블록 표시 
    arr[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        arr[nx][ny] = 1;
    }

    // 서쪽 회전이 가능한지 확인
    int wcnt = 0;
    for(int i = 0; i < 5; i++){
        int nx = x + westDx[i];
        int ny = y + westDy[i];

        if (nx > R || ny < 1 || ny > C) continue;
        if (!arr[nx][ny]) wcnt++;
    }
    if (wcnt == 5) {
        blockReset(x, y); // 원래 블록 위치 0으로

        x += 1;
        y -= 1;
        dir -= 1;
        if (dir < 0) dir = 3;

        down(x, y, downHeight(x, y), dir); // 남쪽 재귀
        return;
    }

    // 동쪽 회전이 가능한지 확인
    int ecnt = 0;
    for(int i = 0; i < 5; i++){
        int nx = x + eastDx[i];
        int ny = y + eastDy[i];

        if (nx > R || ny < 1 || ny > C) continue;
        if (!arr[nx][ny]) ecnt++;
    }
    if (ecnt == 5) {
        blockReset(x, y);

        x += 1;
        y += 1;
        dir += 1;
        if (dir > 3) dir = 0;

        down(x, y, downHeight(x, y), dir); // 남쪽 재귀
        return;
    }

    // 가장 떨어졌을 때 떨어진 골렘 위치가 밖이지만 회전 못할 경우 reset
    if(x <= 1) mapReset();
    return;
}

int bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    queue <pair <int, int>> q;

    q.push({x, y});
    visited[x][y] = 1;
    int cnt = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (newArr[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    return cnt;
}

int res(){
    for(int i = R; i >= 1; i--){
        for(int j = 1; j <= C; j++){
            if (visited[i][j]) return R;
        }
    }
    return 0;
}

int main() {
    cin >> R >> C >> K;
    int sum = 0;
    for(int i = 0; i < K; i++){
        flag = false; 
        int col, dir; // 골렘 출발 열, 출구 방향 정보
        cin >> col >> dir;
        cout << col << " " << dir << "\n";

        int x = -1, y = col; // 현재 골룸의 위치
        int height = downHeight(x, y); // 골렘 떨어지는 높이
        down(x, y, height, dir); 

        // arr 테스트
        cout << "arr\n";
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                cout << arr[i][j];
            }
            cout << "\n";
        }

        if (flag) continue; // reset이면 아무 동작 x

        /* 골렘 탈출하기 */

        // 방향 블록 위치
        int blockX, blockY;
        if (dir == 0) {
            blockX = x - 1;
            blockY = y;
        } else if (dir == 1) {
            blockX = x;
            blockY = y + 1;
        } else if (dir == 2) {
            blockX = x + 1;
            blockY = y;
        } else if (dir == 3) {
            blockX = x;
            blockY = y - 1;
        }

        int blockCnt = bfs(blockX, blockY);
        if (blockCnt == 1) {
            sum += (x + 1); // 이어지지 않을 경우
        } else sum += res(); // 원래 것과 이어질 경우
        cout << sum << "\n\n";

        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                newArr[i][j] = arr[i][j];
            }
        }
    }
    cout << sum;
    return 0;
}