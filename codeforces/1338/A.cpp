#include <bits/stdc++.h>
using namespace std;


void testcase(){
    int n ;
    cin >> n;
   vector<int>a(n);
   for(int i = 0; i < n; i++){
       cin >> a[i];
   }
   vector<int>b(n), d(n);
   b[0] = a[0];
   for(int i = 1; i < n; i++){
       b[i] = a[i];
       if(b[i - 1] > b[i]){
           b[i] = b[i-1];
       }
       d[i] = b[i] - a[i];
        //cout << b[i] << " ";
   }
   int max_value = INT_MIN;
   for(int i = 0; i < n; i++){
       if(d[i] > max_value){
           max_value = d[i];
       }
   }
   
   int cnt = 0;
   while(max_value > 0){
       cnt++;
       max_value = max_value/2;
   }
   
   cout << cnt << endl;
    
}



int main(){
    
    int t;
    cin >> t;
    while(t--){
        testcase();
        
    }
    
}
