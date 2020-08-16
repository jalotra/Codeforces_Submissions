#include "bits/stdc++.h"
using namespace std;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define loop(a, b, i) for(int i = a; i < b; i++)

void brute(vector<int>&a, int k){
    for(int i = 0; i < k; i++){
        int mx = *max_element(a.begin(), a.end());
        for(int j = 0; j < (int)a.size(); j++){
            a[j] = mx - a[j];
            //cout << a[j] << " ";
        }
    } 
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        
        if(k%2 == 0){
            brute(a, 2);
        }else{
            brute(a, 1);
        }
        
        for(int i = 0; i < (int)a.size(); i++){
            cout << a[i] << " ";
        }cout << endl;
    }
}
