#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int num[100001];
int scores[1000001];
int cards[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> num[i];
    cards[num[i]] = 1;
  }

  // 에라토스테네스의 체
  for(int i = 0; i < N; i++){
    for(int j = num[i] * 2; j < 1000001; j += num[i]){
      // 해당 카드 넘버의 배수의 카드가 존재하면 결투
      if (cards[j] == 1) {
        scores[num[i]]++;
        scores[j]--;
      }
    }
  }

  for(int i = 0; i < N; i++){
    cout << scores[num[i]] << ' ';
  }
}