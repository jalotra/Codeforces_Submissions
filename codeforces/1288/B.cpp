#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        
        int start = 9;
        long long total = 0;
        while(start <= b){
            total += a;
            start = 10*start + 9;
        }
        
        cout << total << endl;
    }
    
}
