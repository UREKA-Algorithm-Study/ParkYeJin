#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, x, y, parent[501];
bool cycle[501];

void init() {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    cycle[i] = false;
  }
}

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int tc = 1;
  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    init();

    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      int start = getParent(x);
      int end = getParent(y);

      // 다른 집합
      if (start != end) {
        if (cycle[start] || cycle[end]) {
          cycle[start] = cycle[end] = true;
        }
        parent[start] = end;
      }
      // 같은 집합
      else cycle[start] = true;
    }

    set<int> treeRoots;
    int res = 0;

    for (int i = 1; i <= n; i++) {
      int root = getParent(i);
      // set 삽입 성공시 second ture 반환
      if (!cycle[root] && treeRoots.insert(root).second) {
        res++;
      }
    }

    cout << "Case " << tc;
    tc++;
    if (res == 0) cout << ": No trees.\n";
    else if (res == 1) cout << ": There is one tree.\n";
    else if (res > 1) cout << ": A forest of " << res << " trees.\n";
  }
  return 0;
}


// 왜 틀린지 이해 못하겠는 코드 -> 트리 개수 셀 때 getParent(i)로 변경뒤 성공

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, x, y, parent[501];
bool cycle[501];

void init() {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    cycle[i] = false;
  }
}

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);                                      
}

void unionParent(int x, int y) {
  if (x > y) swap(x, y);
  parent[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int tc = 1;
  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    init();

    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      int start = getParent(x);
      int end = getParent(y);

      // 다른 집합
      if (start != end) {
        if (cycle[start] || cycle[end]) {
          cycle[start] = cycle[end] = true;
        }
        unionParent(start, end);
      }
      // 같은 집합
      else cycle[start] = true;
    }

    set<int> treeRoots;
    int res = 0;

    for (int i = 1; i <= n; i++) {
      // set 삽입 성공시 second ture 반환
      if (!cycle[getParent(i)] && treeRoots.insert(getParent(i)).second) {
        res++;
      }
    }

    cout << "Case " << tc;
    tc++;
    if (res == 0) cout << ": No trees.\n";
    else if (res == 1) cout << ": There is one tree.\n";
    else if (res > 1) cout << ": A forest of " << res << " trees.\n";
  }
  return 0;
}
