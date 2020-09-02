#include <bits/stdc++.h>
using namespace std;

#define lli long long 
const lli inf = 1e+18;  

const int N = 400005;
lli dp[N];
int pos_next[N];



int main(){
    
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    // Initialising vectors
    for(int i = 0; i < n; i++){
        dp[i] = inf;
        pos_next[i] = N;
    }
    
    int cur = 2*N;
    for(int i = n - 1; i >= -k; i--){
        if(i >= 0 && s[i] == '1'){
            cur = i; 
        }
        if(i + k < n){
            pos_next[i + k] = cur; 
        }
    }
    //for(int i = 0; i < n; i++){
        //cout << pos_next[i] << " ";
    //}cout << endl;
    
    for(int i = n; i > 0; i--)
	{
		if(pos_next[i - 1] - (i - 1) <= k)
		{
			int nw = max(0, pos_next[i - 1] - k);
			dp[nw] = min(dp[nw], dp[i] + pos_next[i - 1] + 1);
		}
		dp[i - 1] = min(dp[i - 1], dp[i] + i);
	}
    
    cout << dp[0] << endl;
    
    
    
    
    
    
}
