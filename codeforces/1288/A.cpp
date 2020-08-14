#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        
        double min_value = 2*sqrt(d) - 1;
        
        if(ceil(min_value) <= n){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
