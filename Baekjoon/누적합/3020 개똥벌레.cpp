#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, H; // 동굴의 길이, 높이
int bottom[500001]; // 석순
int top[500001]; // 종유석

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> H;
  for(int i = 0; i < N; i++){
    int height; 
    cin >> height;
    if (i % 2 == 0) bottom[height]++;
    else top[H - height + 1]++;
  }

  for(int i = 1; i <= H; i++){
    top[i] += top[i - 1];
    bottom[H - i] += bottom[H - i + 1];
  }

  int cnt = 0;
  int ans = 200000;
  for(int i = 1; i <= H; i++){
    if (ans > top[i] + bottom[i]){
      ans = top[i] + bottom[i];
      cnt = 1;
    }
    else if(top[i] + bottom[i] == ans) cnt++;
  }

  cout << ans << " " << cnt;
}