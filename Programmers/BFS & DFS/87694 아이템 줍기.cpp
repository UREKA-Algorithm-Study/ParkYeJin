#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/* 
    1. 좌표 2배 확장해서 내부 arr 1로 처리
    2. 처음에 테두리만 new arr 1 처리
    3. dfs 가장 짧은 거리 
*/

int arr[102][102];
int new_arr[102][102];
bool visited[102][102];
bool new_visited[102][102];

int ex, ey;
int answer = 1e9;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

const int new_dx[] = {0, -1, 0, 1};
const int new_dy[] = {1, 0, -1, 0};

// 3. dfs 가장 짧은 거리
void dfs(int x, int y, int depth){
    if (x == ex && y == ey) {
        answer = min(answer, depth);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + new_dx[i];
        int ny = y + new_dy[i];
            
        if (nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
        if (!new_visited[nx][ny] && new_arr[nx][ny] == 1) {
            new_visited[nx][ny] = true;
            dfs(nx, ny, depth + 1);
            new_visited[nx][ny] = false;
        }
    }
}

// 2. 테두리만 1 처리
void bfs(int x, int y){
    queue <pair <int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
            if (!visited[nx][ny]) {
                if (arr[nx][ny] == 1) {
                    new_arr[nx][ny] = 1;
                } else { // arr[nx][ny] == 0;
                    q.push({nx, ny});
                }
                visited[nx][ny] = true;
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    ex = itemX * 2;
    ey = itemY * 2;
    
    // 1. 사각형 좌표 확장
    for (int k = 0; k < rectangle.size(); k++) {
        int x1 = rectangle[k][0] * 2;
        int y1 = rectangle[k][1] * 2;
        int x2 = rectangle[k][2] * 2;
        int y2 = rectangle[k][3] * 2;
        
        for (int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++){
                arr[i][j] = 1;
            }
        }
    }

    bfs(0, 0);
    dfs(characterX * 2, characterY * 2, 0);
    
    return answer / 2; 
}