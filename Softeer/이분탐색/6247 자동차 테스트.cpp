#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int car[50001];

int binary_search(int m){
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if (m == car[mid]) return mid;

        if (m < car[mid]) {
            right = mid - 1;
        } else if (m > car[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> car[i];
    }
    sort(car, car + n);
    for(int i = 0; i < q; i++){
        int m;
        cin >> m; 
        int idx = binary_search(m);

        if (idx == -1) cout << 0 << "\n";
        else {
            cout << idx * (n - idx - 1) << "\n";
        }
        
    }
    
   return 0;
}