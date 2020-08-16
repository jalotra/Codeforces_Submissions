#include "bits/stdc++.h"
using namespace std;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define loop(a, b, i) for(int i = a; i < b; i++)


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(a[i] != a[0]){
                cnt += 1;
            }
        }
        if(cnt > 0){
            cout << 1 << endl;
        }else{
            cout << n << endl;
        }
        
        
        
        //cout << s.size() << endl;
        
    }
}
