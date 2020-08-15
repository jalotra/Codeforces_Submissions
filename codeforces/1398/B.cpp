#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        
        vector<int>l;
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cur += 1;
            }else{
                l.push_back(cur);
                cur = 0;
            }
        }
        l.push_back(cur);
        
        sort(l.begin(), l.end(), greater<int>());
        
        int alice = 0;
        for(int i = 0; i < (int)l.size(); i++){
            alice += l[i];
            i += 1;
        }
        
        cout << alice << endl;
        
    }
    
}
