#include <bits/stdc++.h>
using namespace std;

vector<int>a;
#define ll long long 

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        a.resize(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        int ans = 0, mx = 0, s = 0;
        
        for(int zz = 0; zz <= z; zz++){
            int final_position = k - 2*zz + 1;
            if(final_position < 0) continue;
            
            mx = 0;
            s = 0;
            for(int i = 1; i <= final_position; i++){
                s += a[i];
                if(i < n){
                    mx = max(mx, a[i] + a[i+1]);
                }
            }
            ans = max(ans, s + mx*zz);
            
        }
        
        cout << ans << endl;
        
    }
}
