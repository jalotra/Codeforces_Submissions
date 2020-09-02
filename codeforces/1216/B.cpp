#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];

int main(){
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<pair<int, int>>pii(n);
    for(int i = 0; i < n; i++){
        pii[i] = {a[i], i};
    }
    
    sort(pii.begin(), pii.end(), [](pair<int, int>&x, pair<int, int>&y){
            return x.first > y.first;
        });
    
    int ans = 0;
    int cnt = 0;
    while(cnt < n){
        ans += cnt*pii[cnt].first + 1;
        cnt += 1;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << pii[i].second  + 1 << " ";
    }cout << endl;
    
    
}

