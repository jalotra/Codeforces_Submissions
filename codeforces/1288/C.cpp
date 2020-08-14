#include <bits/stdc++.h>
using namespace std;

const int mod = 1e+9 + 7;
int n, m;
int dp[40][1005];
int solve(int pos, int last_max){
    if(pos == m){
        return 1;
    }
    if(last_max == n){
        return 1;
    }
    if(dp[pos][last_max] > 0){
        return dp[pos][last_max];
    }
    long long current_value = 0;
    for(int i = last_max; i <= n; i++){
        long long next_value = solve(pos + 1, i);
        current_value += next_value;
        current_value %=mod;
    } 
    
    return dp[pos][last_max] = current_value;
    
}


int main(){
    
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> m;
        m *= 2;
        memset(dp, -1LL
        , sizeof(dp));
        
        cout << solve(0, 1) << endl;
        
    }
}
