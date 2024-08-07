#include <iostream>
#include <vector>
using namespace std;

int k, s[14], res[6];

// Combination 조합 (순서 x, 중복 x)
void lotto(int cnt, int idx) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++) {
      cout << res[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = idx; i < k; i++) {
    res[cnt] = s[i];
    lotto(cnt + 1, i + 1);
  }
}

int main() {
  while (1) {
    cin >> k;
    if (k == 0)
      break;

    for (int i = 0; i < k; i++) {
      cin >> s[i];
    }
    lotto(0, 0);
    cout << "\n";
  }

  return 0;
}
