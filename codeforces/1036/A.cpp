#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long n, k;
    cin >> n >> k;
    
    long long q = k/n;
    long long r = k%n;
    
    if(r == 0){
        cout << q << endl;
    }else{
        cout << q + 1 << endl;
    }
    
    return 0;
    
}
