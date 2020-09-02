#include <bits/stdc++.h>
using namespace std;

#define lli long long 

int main(){
    
    int n;
    cin >> n;
    vector<lli>a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    
    lli mx = *max_element(a.begin(), a.end()) ;
    vector<lli>b(n);
    lli g = 0; 
    for(int i = 0; i < n; i++){
        b[i] = mx - a[i];
        //cout << b[i] << " ";
        g = __gcd(b[i], g);
    }
    
    lli cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += b[i]/g; 
    }
    cout << cnt << " ";
    cout << g << endl;
    
    
}
