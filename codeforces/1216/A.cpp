#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve(){
    int last = n-1;
    if(n%2){
        last--;
    }
    int ans = 0;
    last--;
    //cout << last << endl;
    int i = 0;
    while(i < n){
        if(s[i] == 'a' && s[i+1] == 'a'){
            s[i+1] = 'b';
            ans += 1;
        }
        if(s[i] == 'b' && s[i+1] == 'b'){
            s[i+1] = 'a';
            ans += 1;
        }
        i += 2;
    }
    
    cout << ans << endl;
    cout << s << endl;
    
}


int main(){
    cin >> n >> s;
    solve();
    
}
