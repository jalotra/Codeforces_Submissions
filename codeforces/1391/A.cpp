#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 1; i <= n; i++){
            cout << i << " ";
            a[i-1] = i;
        }cout << endl;
        
        //for(int i = 0; i < n; i++){
            //for(int j = 0; j < n; j++){
                //int value = 0;
                //for(int k = i ; k <= j; k++){
                    //value |= a[k];
                //}
                //if(value < j - i + 1){
                    //cout << "Not found" << endl;
                //else{
                    //cout << "FOund" << endl;
                //}
            //}
        //}
        
    //}
    }
}
