#include <string>
#include <vector>

using namespace std;

int visited[51];
int answer = 51;

void dfs(string word, string end, vector<string> &words, int cnt){
    if (word == end) {
        answer = min(answer, cnt);
        return;
    }
    for(int i = 0; i < words.size(); i++){
        // word와 하나의 단어만 다른 것
        if (!visited[i]) {
            int num = 0;
            for(int j = 0; j < words[i].size(); j++){
                if (word[j] != words[i][j]) num++;
            }
            if (num == 1) {
                visited[i] = true;
                dfs(words[i], end, words, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words, 0);
    if (answer == 51) answer = 0;
    
    return answer;
}