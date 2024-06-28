#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int N, M; // 회의실 수, 예약된 회의 수
    cin >> N >> M;
    
    vector <string> roomName;
    vector <pair<string, pair<int, int>>> info; // {회의실, {시작, 끝}}
    
    for(int i = 0; i < N; i++){
        string room;
        cin >> room;
        roomName.push_back(room);
    }
    for(int i = 0; i < M; i++){
        string room;
        int start, end;
        cin >> room >> start >> end;
        info.push_back({room, {start, end}});
    }

    sort(roomName.begin(), roomName.end());

    for(int i = 0; i < N; i++){
        int time[10] = {0}; // 9~18시
        for(int j = 0; j < M; j++){
            if (roomName[i] == info[j].first) {
                int start = info[j].second.first - 9;
                int end = info[j].second.second - 9;

                for(int k = start; k < end; k++){
                    time[k] = 1; // 회의할우
                }
            }
        }
        cout << "Room " << roomName[i] << ":\n";
        
        // 시간 체크
        int cnt = 0;
        bool flag = false;

        vector<int> v;
        for(int j = 0; j < 9; j++){ // 9, 10, 11, 12, 13, 14, 15, 16, 17
            if (time[j] == 0) { // 회의실 비어 있을 때
                if (!flag) {
                    v.push_back(j+9);
                    cnt++;
                }
                if (j == 8) v.push_back(j+10);
                flag = true;
            } else if (time[j] == 1){ // 회의할 때
                if(flag) {
                    v.push_back(j+9);
                }
                flag = false;
            }
        }
        if (cnt == 0) cout << "Not available\n";
        else cout << cnt << ' ' << "available:\n";

        for(int i = 0; i < v.size(); i += 2){
            if (v[i] < 10) {
                if (v[i + 1] < 10){
                    cout << v[i] << '-' << '0';
                } else {
                    cout << '0' << v[i] << '-';
                }
            } else cout << v[i] << '-';
            cout << v[i + 1] << "\n";
        }
        
        if (i != N - 1) cout << "-----\n";
    }
    

   return 0;
}