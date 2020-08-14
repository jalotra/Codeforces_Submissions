#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > a;
int a1, a2;

bool can(int mid){
    
    vector<int>msk(1<<m, -1);
    for(int i = 0; i < n; i++){
        
        int cur = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] >= mid){
                
                cur |= (1 << j);
            }
        }
        msk[cur] = i;
    }
    if(msk[(1 << m) - 1] != -1)
    {
        a1 = a2 = msk[(1 << m) - 1];
        return true;
    }
    for(int i = 0; i < (1 << m) - 1 ;i++){
        for(int j = 0; j < (1 << m) -1; j++){
            if(msk[i] != -1 && msk[j] != -1 && (i|j) == (1 << m) - 1){
                a1 = msk[i];
                a2 = msk[j];
                return true;
            }
        }
    }
    
    return false;
    
    
}

int main(){
    
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    } 
    
    // Binary Search starts from here
    int lf = 0;
    int rg = int(1e+9) + 43;
    
    while(rg  - lf > 1){
        
        int mid = (rg + lf)/2;
        if(can(mid)){
            lf = mid;
        }else{
            rg = mid;
        }
    }
    
    cout << a1 + 1 << " " << a2 + 1 << endl;
}
