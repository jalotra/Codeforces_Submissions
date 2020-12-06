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
    ll ans = 0;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
    }
    if(ans%3 != 0){
        cout << 0 << endl;
        return;
    }
    vector<int>locations[1];
    ll curr = 0;
    for(int i = 0; i < n; i++){
        curr += a[i];
        if(curr == (2*ans)/3){
            locations[0].push_back(i);
        }
    }
    curr = 0;
    ll sol = 0;
    debug() << imie(locations[0]);
    for(int i = 0; i < n; i++){
        curr += a[i];
        if(curr == ans/3 ){
            debug() << imie(i);
            int idx = upper_bound(locations[0].begin(), locations[0].end(), i) - locations[0].begin();
            if(idx != (int)locations[0].size()){
                sol += locations[0].size() - idx;
                if(locations[0][locations[0].size() - 1] == n - 1){
                    sol--;
                }
            }
        }
    }
    cout << sol << endl;
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
