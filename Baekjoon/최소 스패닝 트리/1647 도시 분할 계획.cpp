#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, result, maxCost;
int parent[100001];

vector <pair <int, pair <int, int>>> v;

void init(){
  for(int i = 1; i <= N; i++){
    parent[i] = i;
  }
}

int getPrent(int x){
  if (parent[x] == x) return x;
  else return parent[x] = getPrent(parent[x]);
}

void unionParent(int x, int y){
  x = getPrent(x);
  y = getPrent(y);
  if (x > y) swap(x, y);
  parent[y] = x;
}

void kruskal(){
  for(int i = 0; i < M; i++){
    int cost = v[i].first;
    int start = v[i].second.first;
    int end = v[i].second.second;

    int a = getPrent(start);
    int b = getPrent(end);

    if (a == b) continue;
    else {
      maxCost = max(maxCost, cost);
      result += cost;
      unionParent(a, b);
    }
  }
}

int main(){
  cin >> N >> M;

  init();
  for(int i = 0; i < M; i++){
    int A, B, C;
    cin >> A >> B >> C;
    v.push_back({C, {A, B}});
  }
  sort(v.begin(), v.end());
  kruskal();
  cout << result - maxCost << "\n";

  return 0;
}