#include <bits/stdc++.h>
using namespace std;

int K;
int num[1024];
vector <int> res[14];

void go(int s, int e, int level){
  if (s > e) return; // 구간 쪼갤 때 무조건
  if (s == e) {
    res[level].push_back(num[s]);
    return;
  }
  int mid = (s + e) / 2; // s <= e
  res[level].push_back(num[mid]);
  go(s, mid - 1, level + 1);
  go(mid + 1, e, level + 1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> K;
  int tree = pow(2, K) - 1; // 트리 노드 크기
  for(int i = 0; i < tree; i++){
    cin >> num[i];
  }
  go(0, tree, 0);

  for(int i = 0; i < K; i++){
    for(int j = 0; j < res[i].size(); j++){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
} 