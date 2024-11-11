#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  int TC, t = 1;
  cin >> TC;

  while(TC--){
    int N, M, res = 0;
    cin >> N >> M;

    string str[101];
    bool flag = false;
    bool flag1 = false;
    int pcnt = 0, npcnt = 0;

    for(int i = 0; i < N; i++){
      cin >> str[i];
      string ostr = str[i];

      reverse(str[i].begin(), str[i].end());
      if (ostr == str[i]) flag = true;
    }

    // 뒤집어서 같은 거 확인
    int cnt = 0;
    for(int i = 0; i < N; i++){
      reverse(str[i].begin(), str[i].end());
      for(int j = i + 1; j < N; j++){
        if (str[i] == str[j]) {
          flag1 = true;
          cnt++;
        }
      }
    }

    if (flag) res += M; // 펠린드롬 있다면
    if (flag1) res += (cnt * 2) * M; // 뒤집어서 같은 게 있다면
    
    cout << "#" << t++ << " " << res << "\n";
  }
  
  return 0;
}