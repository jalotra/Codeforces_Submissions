#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
#define ll long long


void test_case(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    
    int one = 0, zero = 0;
    for(int i = 0; i  <n; i++){
        if(a[i]){
            one++;
        }else{
            zero++;
        }
    }
    
    if(one > zero){
        bool flag = false;
        if(one%2){
            flag = true;
        }
        cout << one - flag << endl;
        int time = one - flag;
        while(time > 0){
            cout << 1 << " ";
            time -= 1;
        }
    }else{
        //bool flag = false;
        //if(zero%2){
            //flag = true;
        //}
        cout << zero << endl;
        int time = zero;
        while(time > 0){
            cout << 0 << " ";
            time -= 1;
        }
    }
    cout << endl;
    
    
    //vector<int>odd(n, 0), even(n, 0);
    //if(a[n-1] == 1){
        //even[n-1] = 1;
    //}
    //for(int i = n-2; i >= 0; i--){
        //int temp = odd[i + 1];
        //odd[i] = even[i+1];
        //even[i] = temp;
        //if(a[i] == 1){
            //even[i]++;
        //}
    //}
    
    //for(int i = 0; i < n; i++){
        //cout << even[i] << " ";
    //}cout << endl;
    
    //for(int i = 0; i < n; i++){
        //cout << odd[i] << " ";
    //}cout << endl;
     
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
