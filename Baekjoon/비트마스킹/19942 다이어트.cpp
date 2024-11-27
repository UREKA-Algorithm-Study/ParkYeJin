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


// 백트래킹

#include <bits/stdc++.h>
using namespace std;

/*
  최저 영양소 기준 만족하는 최소 비용의 식재료 집합
*/

int N;
int mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int res = 1e9;

vector <int> temp;
vector <int> vres;

void dfs(int idx, int sp, int sf, int ss, int sv, int sc){
  if (sp >= mp &&  sf >= mf && ss >= ms && sv >= mv) {
    if (res > sc) {
      res = sc;
      vres.clear();
      for(auto iter: temp) {
        vres.push_back(iter);
      }
    }
  }

  for(int i = idx + 1; i < N; i++){
    temp.push_back(i + 1);
    dfs(i, sp + p[i], sf + f[i], ss + s[i], sv + v[i], sc + c[i]);
    temp.pop_back();
  }
}

int main() { 
  cin >> N;
  cin >> mp >> mf >> ms >> mv; // 최소 영양성분

  for(int i = 0; i < N; i++){
    cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
  }
  dfs(-1, 0, 0, 0, 0, 0);
  if (res == 1e9) cout << -1 << "\n";
  else cout << res << "\n";

  for(auto iter: vres) {
    cout << iter << " ";
  }

  return 0;
}

