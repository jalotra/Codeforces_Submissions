#include <bits/stdc++.h>
using namespace std;

//#define double db
double prob[20][20];
double dp[(1 << 19)];

double pmove(int previous_bitmask, int must_die, int &n){
     
     int total_fishes = __builtin_popcount(previous_bitmask);
     long long  deno = ((total_fishes)*(total_fishes-1))/2;
     
     double move_prob = 0;
     for(int fish = 0; fish < n; fish++){
         if(previous_bitmask&(1 << fish)){
         move_prob += prob[fish + 1][must_die + 1];
        }  
    }
    return move_prob/(1.0*deno); 
}

double solve(int bitmask, int n){
    
    // Base case
    if(__builtin_popcount(bitmask) == n){
        return 1;
    }
    
    if(dp[bitmask] > -0.9){
        return dp[bitmask];
    }
    
    double answer = 0;
    for(int fish = 0; fish < n; fish++){
        bool alive = bitmask&((1 << fish));
        if(!alive){
           int previous_bitmask = bitmask^(1 << fish);
           double previous_day = solve(previous_bitmask, n);
           
           answer += previous_day*pmove(previous_bitmask, fish, n); 
        }
    }
    //cout << answer << endl;
    return dp[bitmask] = answer;
    
    
}


int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> prob[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(10) << solve((1 << i), n) << endl;
    }
}
