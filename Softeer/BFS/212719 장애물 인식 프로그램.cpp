#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int arr[26][26];
bool visited[26][26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int x, int y){
    queue <pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > N)
                continue;
            if (arr[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char** argv)
{
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &arr[i][j]); // 01이 붙어서 입력되므로
        }
    }

    vector <int> obstacle; // 각 블록 내 장애물 수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (!visited[i][j] && arr[i][j] == 1) {
                int n = bfs(i, j);
                obstacle.push_back(n);
            }
        }
    }
    sort(obstacle.begin(), obstacle.end());

    cout << obstacle.size() << "\n";
    for(auto i : obstacle){
        cout << i << "\n";
    }

   return 0;
}