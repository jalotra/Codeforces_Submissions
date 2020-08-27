#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a[3], b[3];
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 3; i++)cin >> a[i];
        for(int i = 0; i < 3; i++)cin >> b[i];
        
        long long res = 0;
        int value = min(a[2], b[1]);
        a[2] = a[2] - value;
        b[1] = b[1] - value;
        res += value;
        
        int b2_max = b[2] - a[0] - a[2];
        b2_max = max(b2_max, 0);
        res -= min(a[1], b2_max);
        
        cout << 2*res << endl;
        
        
    }
    
}
