#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        
        int min = *min_element(a.begin(), a.end());
        
        
        vector<int>idxs;
        vector<int>values;
        for(int i = 0; i < n; i++){
            if(a[i]%min == 0){
                idxs.push_back(i);
                values.push_back(a[i]);
            }
        }
        
        sort(values.begin(), values.end());
        
        for(int i = 0; i < (int)idxs.size(); i++){
            a[idxs[i]] = values[i];
        }
        
        vector<int>sorted = a;
        sort(sorted.begin(), sorted.end());
        bool done = true;
        for(int i = 0; i < n; i++){
            if(a[i] != sorted[i]){
                done = false;
                break;
            }
        }
        if(done) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}
