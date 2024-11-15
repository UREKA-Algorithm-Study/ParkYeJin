// 풀이1 - 미리 값을 다 저장

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[301][301];

void start(){
  int num = 1;
  for(int i = 1; i <= 300; i++){
    arr[i][1] = num;
    num += i; 
  }

  for(int i = 1; i <= 300; i++){
    int num1 = i + 1;
    for(int j = 2; j <= 300; j++){
      arr[i][j] = arr[i][j - 1] + num1;
      num1++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  start();
  while(T--){
    int p, q;
    cin >> p >> q;

    int px, py, qx, qy;
    for(int i = 1; i <= 300; i++){
      for(int j = 1; j <= 300; j++){
        if (p == arr[i][j]) {
          px = i;
          py = j;
        } 
        if (q == arr[i][j]) {
          qx = i;
          qy = j;
        } 
      }
    }

    cout << "#" << TC << " " <<arr[px + qx][py + qy] << "\n";
    TC++;
  }

  return 0;
}


// 풀이2 - 수학식으로 계산
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getValue(int x, int y){
  return ((y + (x - 1)) * (y + x)) / 2 - (x - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    int p, q;
    cin >> p >> q;

    int px, py, qx, qy;
    bool pflag = false, qflag = false;
    for(int i = 1; i <= 300; i++){
      for(int j = 1; j <= 300; j++){
        if (p == getValue(i, j)) {
          px = i;
          py = j;
          pflag = true;
        } 
        if (q == getValue(i, j)) {
          qx = i;
          qy = j;
          qflag = true;
        } 
        if (pflag && qflag) break;
      }
      if (pflag && qflag) break;
    }

    cout << "#" << TC << " " << getValue(px + qx, py + qy) << "\n";
    TC++;
  }

  return 0;
}
