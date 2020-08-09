#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>>a(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        
        int result = 0;
        for(int i = 0; i < n; i++){
            if(a[i][m-1] == 'R'){
                result += 1;
            }
        }
        for(int i = 0; i < m; i++){
            if(a[n-1][i] == 'D'){
                result += 1;
            }
        }
        cout << result << "\n";
        
        
        //vector<vector<int>>dp(n, vector<int>(m));
        //dp[n-1][m-1] = 0;
        //for(int i = m-2; i >= 0; i--){
            //dp[n-1][i] = dp[n-1][i+1];
            //if(a[n-1][i] != 'R'){
                //dp[n-1][i] += 1;
            //}
        //}
        //for(int i = n-2; i >= 0; i--){
            //dp[i][m-1] = dp[i+1][m-1];
            //if(a[i][m-1] != 'D'){
                //dp[i][m-1] += 1;
            //}
        //}
        
        //for(int i = n-2; i >= 0; i--){
            //for(int j = m-2; j >= 0; j--){
                //int min_value = min(dp[i][j+1], dp[i+1][j]);
                //dp[i][j] = min_value;
                //if(dp[i][j+1] == dp[i+1][j]){
                    //continue;
                //}
                //if(min_value == dp[i][j+1]){
                    //if(a[i][j] == 'D'){
                        //dp[i][j] += 1;
                    //}
                //}else{
                    //if(a[i][j] == 'R'){
                        //dp[i][j] += 1;
                    //}
                //}
            //}
        //}
        
        //cout << dp[0][0] << "\n";
        //for(int i = 0; i < n; i++){
            //for(int j = 0; j < m; j++){
                //cout << dp[i][j] << " ";
            //}cout << endl;
        //}
        
        
        
    }
}
