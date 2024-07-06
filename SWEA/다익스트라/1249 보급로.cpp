#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int arr[101][101];
int dist[101][101];
bool visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra() {
    fill(&dist[0][0], &dist[N][N], 1e9);
    
    dist[0][0] = 0;
    pq.push({ 0, {0, 0} }); // 가중치, 정점

    while (!pq.empty()) {
        int cost = -pq.top().first;        // 가중치
        int nowx = pq.top().second.first;  // 정점 x
        int nowy = pq.top().second.second; // 정점 y
        pq.pop();

        // 이미 최단경로 체크한 노드
        if (dist[nowx][nowy] < cost)
            continue;

        for (int i = 0; i < 4; i++) {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];
            int nextcost = arr[nextx][nexty];

            if (nextx < 0 || nextx > N - 1 || nexty < 0 || nexty > N - 1) continue;
            if (dist[nextx][nexty] > dist[nowx][nowy] + nextcost) {
                dist[nextx][nexty] = dist[nowx][nowy] + nextcost;
                pq.push({ -dist[nextx][nexty], {nextx, nexty} });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T, cnt = 1;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++) {
                arr[i][j] = str[j] - 48;
            }
        }
        dijkstra();

        cout << '#' << cnt << " " << dist[N - 1][N - 1] << "\n";
        cnt++;
    }
    return 0;
}