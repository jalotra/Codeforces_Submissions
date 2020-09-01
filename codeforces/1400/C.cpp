#include <bits/stdc++.h>
using namespace std;


void testcase(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n= s.size();
    vector<int>w(n, 1);
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(i - k >= 0)w[i-k] = 0;
            if(i + k < n)w[i+k] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            bool found = false;
            if(i - k >= 0){
                if(w[i - k] == 1){
                    found = true;
                }
            }
            if(i + k < n){
                if(w[i+k] == 1){
                    found = true;
                }
            }
            if(!found){
                cout << -1 << endl;
                return;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << w[i];
    }cout << endl;
    
}



int main(){
    
    int t;
    cin >> t;
    while(t--){
        testcase();
        
    }
    
}
