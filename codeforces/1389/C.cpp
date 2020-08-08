#include <bits/stdc++.h>
using namespace std;

int solve(const string& s, int x, int y){
    
    int res = 0;
    for(auto c : s){
        int value = c - '0';
        if(value == x){
            res += 1;
            swap(x, y);
        }
    }
    if(x != y && res%2 == 1){
        --res;
    }
    
    return res;
    
}



int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        int ans = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                ans = max(ans, solve(s, i, j));
            }
        }
        cout << s.size() - ans << endl;
        
    }
    return 0;
    
}
