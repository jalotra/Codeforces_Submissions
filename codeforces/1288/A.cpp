#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        
        
        int start = 0;
        int end = n;
        int found = 0;
        while(start <= end){
            int x = start + (end - start)/2;
            //cout << x << endl;
            //cout << x + ceil((double)d/(double)(x+1)) << endl; 
            if(x + ceil((double)d/(double)(x+1)) <= n){
                cout << "YES" << endl;
                found = 1;
                break;
            }else {
                start = x + 1;
            }
            
        }
        if(!found)cout << "NO" << endl;
    }
}
