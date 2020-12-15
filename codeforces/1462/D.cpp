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
    vector<ll>a(n), pref(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i] += a[i];
        if(i != 0){
            pref[i] += pref[i - 1];
        }
    }
    map<ll, bool>mp;
    for(int i = 0; i < n; i++){
        mp[pref[i]] = true;
    }
    int min_length = 1;
    for(int len = n; len >= 1; len--){
        if(pref[n - 1]%len != 0)continue;
        
        ll x = pref[n - 1]/len;
        int found = true;
        for(int i = 1; i < len; i++){
            if(!mp[i*x]){
                found = false;
                break;
            }
        }
        if(found == true){
            min_length = len;
            break;
        }
    }
    
    cout << n - min_length  << endl;
    
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
