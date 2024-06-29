#include <algorithm>
#include <iostream>
using namespace std;

int parent[10001];
bool visited[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;
  
  while (T--) {
    int N; // 노드 수
    cin >> N;
    
    for(int i = 1; i <= N; i++){
      visited[i] = 0;
      parent[i] = i;
    }

    for(int i = 0; i < N - 1; i++){
      int A, B; // A가 B의 부모
      cin >> A >> B; 
      parent[B] = A;
    }

    // LCA 최소 공통 조상 찾기
    int u,v;
    cin >> u >> v;
    visited[u] = 1;

    // 루트 노드까지
    while(u != parent[u]){
      u = parent[u];
      visited[u] = 1;
    }
    
    while(1) {
      if (visited[v]){
        cout << v << "\n";
        break;
      }
      v = parent[v];
    }
  }
}