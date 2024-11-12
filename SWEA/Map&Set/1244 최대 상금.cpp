#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int n, exc;
string str, res;

/*
  set 사용하여 중복 문자열 탐색 x
  중복 탐색 or 조합하면 시간초과
*/

set <string> visited;

void dfs(string cstr, int cnt) {
  if (cnt == exc) {
    res = max(res, cstr);
    return;
  }
  if (visited.count(cstr) > 0) return;
  
  visited.insert(cstr);
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      swap(cstr[i], cstr[j]);
      dfs(cstr, cnt + 1);
      swap(cstr[i], cstr[j]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> str >> exc;
    n = str.size();
    res = "";

    visited.clear();
    dfs(str, 0);

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
