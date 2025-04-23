#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

struct Trie {
  bool isEnd; // 끝나는 지점
  Trie* children[26]; // 알파벳

  Trie() {
    isEnd = false;
    for(int i = 0; i < 26; i++){
      children[i] = NULL;
    }
  }
  
  string insert(const string &word) {
    Trie* node = this; // 현재 지점
    bool isNew = false;
    int uniquePos = word.size();

    for(int i = 0; i < word.size(); i++){
      int idx = word[i] - 'a';
      // 새로 만들어지는 거라면
      if (!node->children[idx]) {
        node->children[idx] = new Trie();
        // 처음 생기는 위치
        if (!isNew) {
          uniquePos = i + 1;
          isNew = true;
        }
      } 
      node = node->children[idx]; // 다음 위치로
    }
    // 끝지점
    node->isEnd = true;
    return word.substr(0, uniquePos);
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    Trie trie;
    unordered_map<string, int> m;

    while(N--){
      string name;
      cin >> name;

      string uniquePrefix = trie.insert(name);
      if (m[name] == 0) {
        m[name] = 1;
        cout << uniquePrefix << "\n";
      } else {
        m[name]++;
        cout << name << m[name] << "\n";
      }
    }

    return 0;
}
