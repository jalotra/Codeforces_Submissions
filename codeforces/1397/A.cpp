#include <bits/stdc++.h>
using namespace std;

void testcase(){
    int n;
    cin >> n;
    map<char, int>mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(auto c : s){
            mp[c]++;
        }
    }
    bool found = true;
    for(auto v : mp){
        if(v.second%n != 0){
            cout << "NO" << endl;
            found = false;
            break;
        }
    }
    if(found)cout << "YES" << endl;
    
    
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        
        testcase();
        
    }
    
}
