#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, res = 100;
int light[11][2]; // 맨 앞뒤 전구
bool visited[11];

// 순열 permutation (순서o, 중복x)
void backtracking(int cnt, int last, int num) {
  if (cnt == N) {
    res = min(res, num);
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      backtracking(cnt + 1, light[i][1], num + (last != light[i][0] ? 1 : 0));
      visited[i] = false;
    }
  }
}

int count(string str) {
  int cnt = 0;
  for (int i = 0; i < str.size() - 1; i++) {
    if (str[i] != str[i + 1]) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  cin >> N;

  int sum = 0;
  string str[11];

  for (int i = 0; i < N; i++) {
    cin >> str[i];
    sum += count(str[i]);

    // 전구 맨 앞뒤
    light[i][0] = str[i][0];
    light[i][1] = str[i][str[i].size() - 1];
  }
  backtracking(0, -1, -1);
  cout << res + sum;

  return 0;
}


// 시간초과 코드

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, res = 100;
bool visited[11];
string str[11];
vector<string> v;

int count(string str) {
  int cnt = 0;
  int tmp = str[0];
  for (int i = 1; i < str.size(); i++) {
    if (tmp != str[i]) {
      cnt++;
      tmp = str[i];
    }
  }
  return cnt;
}

// 순열 permutation (순서o, 중복x)
void backtracking(int cnt, string current) {
  if (cnt == N) {
    res = min(res, count(current));
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      backtracking(cnt + 1, current + str[i]);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> str[i];
  }
  backtracking(0, "");
  cout << res;

  return 0;
}
