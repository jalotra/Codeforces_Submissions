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
    int zeros, ones;
    cin >> zeros >> ones;
    if(zeros == 0 && ones == 1){
        cout << 1 << endl;
    }
    
    if(ones >= zeros - 1 && ones <= 2*(zeros + 1)){
        int sz = 2*zeros + 1; 
        int ones_left = ones - zeros + 1;
        int start = 0;
        vector<int>a(sz, 0);
        start = 1;
        int last_zero = 0;
        while(start < sz && zeros > 0){
            a[start] = 0;
            zeros -= 1;
            last_zero = max(last_zero, start);
            start += 2;
        }
        debug() << imie(a);
        debug() << imie(last_zero);
        start = 2;
        while(start < last_zero && ones > 0){
            //cout << "HERE1";
            a[start] = 1;
            start += 2;
            ones -= 1;
        }
        debug() << imie(a);
        start = 0;
        debug() << imie(ones_left);
        while(start < sz && ones_left > 0){
            int here = min(ones_left, 2 - a[start]);
            a[start] += here;
            start += 2;
            ones_left -= here;
        }
        debug() << imie(a);
        
        string s = "";
        for(int i = 0; i < sz; i++){
            
            if(i%2 == 0){
                if(a[i] == 0)continue;
                else if(a[i] == 1) s += "1";
                else s += "11"; 
            }else {
                if(a[i] == 0){
                    s += "0";
                }
            }
        }
        cout << s << endl;
    
    
    }else{
    cout << -1 << endl;
}
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
