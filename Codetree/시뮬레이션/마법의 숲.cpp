#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int Tcnt = 0;
int R, C, K; 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int arr[71][71];
int newArr[71][71];
int nowX, nowY, nowDir; // 현재 골룸 위치

int westDx[5] = {-1, 0, 1, 1, 2};
int westDy[5] = {-1, -2, -2, -1, -1}; 

int eastDx[5] = {-1, 0, 1, 1, 2};
int eastDy[5] = {1, 2, 1, 2, 1};

int visited[71][71];
bool flag = false;

void reset() {
    memset(arr, 0, sizeof(arr));
    memset(newArr, 0, sizeof(newArr));
    Tcnt = 0;
    flag = true;
}

int downHeight(int x, int y) {
    int cnt = 0;
    for(int i = x + 1; i <= R; i++){
        int left = arr[i][y - 1];
        int g = arr[i][y];
        int right = arr[i][y + 1];

        if (!left && !g && !right) cnt++;
        // 블록이 있을 경우 
        else {
            // 꼭대기 떨
            if (g == 1) return i - (x + 1) - 1;
            // 양쪽 떨
            else return i - (x + 1);
        }
    }
    // 블록이 없을 경우 (처음)
    if (cnt == R + 1) return R;
    // 블록이 없을 경우 (땅바닥)
    else return 0; 
}

void down(int x, int y, int h, int dir) {
    if (flag) return;

    x += h; // 떨어진 골렘 위치
    cout << "떨어진 골렘 위치 " << x << " " << y << " " << h << "\n";

    nowX = x;
    nowY = y;
    nowDir = dir;
    arr[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        arr[nx][ny] = 1;
    }

    if (h == R) return;

    // 서쪽 회전이 가능한지 확인
    int wcnt = 0;
    for(int i = 0; i < 5; i++){
        int nx = x + westDx[i];
        int ny = y + westDy[i];

        if (nx > R || ny < 1 || ny > C) continue;
        // 5곳 다 0이어야 회전 가능
        if (!arr[nx][ny]) wcnt++;
    }
    if (wcnt == 5) {
        // 원래 위치 0으로
        arr[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            arr[nx][ny] = 0;
        }

        // 방향 바꾸기
        x += 1;
        y -= 1;
        dir -= 1;
        if (dir < 0) dir = 3;

        // 또 떨어트리기
        int h = downHeight(x, y);
        down(x, y, h, dir);
    }

    // 동쪽 회전이 가능한지 확인
    int ecnt = 0;
    for(int i = 0; i < 5; i++){
        int nx = x + eastDx[i];
        int ny = y + eastDy[i];

        if (nx > R || ny < 1 || ny > C) continue;
        // 4곳 다 0이어야 회전 가능
        if (!arr[nx][ny]) ecnt++;
    }
    if (ecnt == 5) {
        // 원래 위치 0으로
        arr[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            arr[nx][ny] = 0;
        }

        // 방향 바꾸기
        x += 1;
        y += 1;
        dir += 1;
        if (dir > 3) dir = 0;

        // 떨어트리기
        int h = downHeight(x, y);
        down(x, y, h, dir);
    }

    // 가장 떨어졌을 때 떨어진 골렘 위치가 밖이지만 회전 못할 경우 reset
    if(nowX <= 1) {
        reset();
        return;
    }
}

int bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    queue <pair <int ,int >> q;
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
        int c, d; // 골렘 출발 열, 출구 방향 정보
        cin >> c >> d;
        cout << c << " " << d << "\n";
        flag = false; 

        int h = downHeight(-1, c);
        cout << "떨어트리는 높이 " << h << "\n";
        down(-1, c, h, d);

        // arr 테스트
        cout << "arr\n";
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                cout << arr[i][j];
            }
            cout << "\n";
        }   

        if (flag) {
            continue; // 맵 초과
        }

        // 방향 블록 위치
        int blockX, blockY;
        if (nowDir == 0) {
            blockX = nowX - 1;
            blockY = nowY;
        } else if (nowDir == 1) {
            blockX = nowX;
            blockY = nowY + 1;
        } else if (nowDir == 2) {
            blockX = nowX + 1;
            blockY = nowY;
        } else if (nowDir == 3) {
            blockX = nowX;
            blockY = nowY - 1;
        }

        if (Tcnt == 0) { // 처음 들어왔을 때나, reset후 처음
            for(int i = 1; i <= R; i++){
                for(int j = 1; j<= C; j++){
                    newArr[i][j] = arr[i][j];
                }
            }
        } else { // 후에 들어왔을 땐 방향만 연결
            newArr[blockX][blockY] = 1;
        }

        int blockCnt = bfs(blockX, blockY);

        // newArr 테스트
        cout << "newArr\n";
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                cout << newArr[i][j];
            }
            cout << "\n";
        }

        // 이어지지 않을 경우 (방향 위치 블록 상하좌우 다 0일 경우)
        if (blockCnt == 1) {
            sum += (nowX + 1);
        } // 원래 것과 이어질 경우
        else sum += res();
        cout << sum << "\n";

        for(int i = 1; i <= R; i++){
            for(int j = 1; j<= C; j++){
                newArr[i][j] = arr[i][j];
            }
        }
        cout << "\n\n";
        Tcnt++;
    }
    //cout << sum;
    return 0;
}