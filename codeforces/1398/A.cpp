#include <bits/stdc++.h>
using namespace std;

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
        
        if(a[n-1] >= a[0] + a[1]){
            cout << 1 << " " << 2 << " " << n << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
