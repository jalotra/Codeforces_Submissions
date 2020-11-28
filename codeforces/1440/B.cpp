#include <bits/stdc++.h>
using namespace std;


void test_case(){
    
    int n, k;
    cin >> n >> k;
    vector<int>a(n*k);
    for(int i = 0; i < n*k; i++)cin >> a[i];
    int idx = n*k;
    long long ans = 0;
    while(k > 0){
        int leave = (n/2 + 1);
        idx -= leave;
        if(idx < 0)break;
        ans += a[idx];
        // cout << start << " " << idx << " " << a[idx] << endl;
        k--;
    }
    
    cout << ans << endl;
    
}



int main(){
    
    int t;
    cin >> t;
    while(t--)
        test_case();
    
}
