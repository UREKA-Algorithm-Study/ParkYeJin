#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], cost[16];
int minRes = 1e9;

vector <int> resIdx;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  cin >> mp >> mf >> ms >> mv;
  for(int i = 0; i < N; i++){
    cin >> p[i] >> f[i] >> s[i] >> v[i] >> cost[i];
  }

  // 모든 부분 집합, 비트마스킹
  for(int i = 1; i < (1 << N); i++){
    int psum = 0, fsum = 0, ssum = 0, vsum = 0, costsum = 0;
    vector <int> idx;

    for(int j = 0; j < N; j++){
      if (i & (1 << j)) { // j번째 식재료가 포함된 경우
        psum += p[j];
        fsum += f[j];
        ssum += s[j];
        vsum += v[j];
        costsum += cost[j];
        idx.push_back(j + 1);
      }
    }

    // 필요 영양소 만족
    if (psum >= mp && fsum >= mf && ssum >= ms && vsum >= mv) {
      if (minRes > costsum) {
        minRes = costsum;
        resIdx = idx;
      } 
      // 반례: 비용이 동일한 경우 번호가 작은 순서
      else if (minRes == costsum) {
        if (resIdx > idx) {
          resIdx = idx;
        }
      }
    }

  }

  // 조건을 만족하는 답 x
  if (minRes == 1e9) {
    cout << -1;
  } else {
    cout << minRes << "\n";
    for(auto iter : resIdx) {
      cout << iter << " ";
    }
  }

  return 0;
} 



// 시간초과 코드 (백트래킹)

#include <bits/stdc++.h>
using namespace std;

/*
  nC?
*/

int N, mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], cost[16];

vector <int> res;
bool visited[16];
int ret = 1e9;

vector <int> idx; // 최소 비용 식재료의 번호

void dfs(int r){
  if (res.size() == r) {
    int psum = 0, fsum = 0, ssum = 0, vsum = 0, costsum = 0;
    for(auto iter : res) {
      psum += p[iter];
      fsum += f[iter];
      ssum += s[iter];
      vsum += v[iter];
      costsum += cost[iter];
    }
    if (psum >= mp && fsum >= mf && ssum >= ms && vsum >= mv) {
      if (ret > costsum) {
        ret = costsum;
        idx.clear();
        for(auto iter: res) {
          idx.push_back(iter + 1);
        }
      } 
    }
    return;
  }
  for(int i = 0; i < N; i++){
    if (!visited[i]){
      visited[i] = true;
      res.push_back(i);
      dfs(r);
      res.pop_back();
      visited[i] = false;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  cin >> mp >> mf >> ms >> mv;
  for(int i = 0; i < N; i++){
    cin >> p[i] >> f[i] >> s[i] >> v[i] >> cost[i];
  }

  // nC1~N
  for(int i = 1; i <= N; i++){
    memset(visited, 0, sizeof(visited));
    res.clear();
    dfs(i);
  }
  // 조건을 만족하는 답 x
  if (ret == 1e9) {
    cout << -1;
    return 0;
  }

  // 출력
  cout << ret << "\n";
  sort(idx.begin(), idx.end());
  for(auto iter : idx) {
    cout << iter << " ";
  }

  return 0;
} 