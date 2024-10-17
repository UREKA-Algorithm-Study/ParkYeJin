#include <bits/stdc++.h>
using namespace std;

/*
  0~9 숫자들 최소, 최대 정수
*/

int k;
char oper[10];
bool visited[10];

bool calc(int a, int b, char oper){
  if (oper == '<') return a < b;
  else if (oper == '>') return a > b;
}

vector <int> v;
long long maxRes = 0;
long long minRes = 10000000000;

void dfs(int cnt){
  if (cnt == k + 1) {
    string str = "";
    for(auto iter : v) {
      str += to_string(iter);
    }
    maxRes = max(maxRes, stoll(str));
    minRes = min(minRes, stoll(str));
    return;
  }

  for(int i = 0; i < 10; i++){
    if (!visited[i]) {
      // 첫번째 숫자는 바로 추가
      if (cnt == 0 || calc(v[cnt - 1], i, oper[cnt - 1])){
        visited[i] = true;
        v.push_back(i);
        dfs(cnt + 1);
        visited[i] = false;
        v.pop_back();
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> k;
  for(int i = 0; i < k; i++){
    cin >> oper[i];
  }
  dfs(0);

  cout << maxRes << "\n";
  if (to_string(minRes).size() == k) {
    cout << "0";
  }
  cout << minRes;

  return 0;
} 