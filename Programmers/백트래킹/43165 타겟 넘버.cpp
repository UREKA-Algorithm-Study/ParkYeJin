#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ctarget, res;
vector <char> op;
vector <char> v = {'+', '-'};

int calc(int x, int y, char c) {
    if (c == '+') return x + y;
    else if (c == '-') return x - y;
}

void dfs(vector<int> &numbers, vector<char> &op, int depth){
    if (depth == numbers.size()) {
        int sum = numbers[0];
        if (op[0] == '-') sum *= -1;
        for(int i = 1; i < op.size(); i++){
            sum = calc(sum, numbers[i], op[i]); 
        }
        
        if (sum == ctarget) res++;
        return;
    }
    
    for(int i = 0; i < 2; i++){
        op.push_back(v[i]);
        dfs(numbers, op, depth + 1);
        op.pop_back();
    }
}

int solution(vector<int> numbers, int target) {
    ctarget = target;
    dfs(numbers, op, 0);
    
    return res;
}


// dfs 풀이방법
#include <string>
#include <vector>

using namespace std;

int res, ctarget;

void dfs(vector<int> numbers, int sum, int idx){
    if(idx == numbers.size()){
        if(ctarget == sum) res++;
        return;
    }
    dfs(numbers, sum + numbers[idx], idx + 1);
    dfs(numbers, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    ctarget = target;
    dfs(numbers, 0, 0);
    
    return res;
}