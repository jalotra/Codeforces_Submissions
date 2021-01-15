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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    assert((int)s.size() == n);
    
    debug() << imie(n) imie(m) imie(s);
    vector<int>values(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '-'){
            values[i] -= 1;
        }else{
            values[i] += 1;
        }
        if(i > 0){
            values[i] += values[i - 1];
        }
    }
    // Contains pair {min, max}
    vector<pair<int, int>>pref(n, make_pair(0, 0)),suff(n, make_pair(INT_MAX, INT_MIN)); 
    for(int i = 0; i < n; i++){
        pref[i].first = min(pref[i].first, values[i]);
        pref[i].second = max(pref[i].second, values[i]);
        if(i > 0){
            pref[i].first = min(pref[i].first, pref[i-1].first);
            pref[i].second = max(pref[i].second, pref[i-1].second);
        }
    }
    
    for(int i = n - 1; i >=0 ; i--){
        suff[i].first = min(suff[i].first, values[i]);
        suff[i].second = max(suff[i].second, values[i]);
        if(i + 1 < n){
            suff[i].first = min(suff[i].first, suff[i+1].first);
            suff[i].second = max(suff[i].second, suff[i+1].second);
        }
    }
    debug() << imie(values);
    debug() << imie(pref) ;
    debug() << imie(suff);
    
    
    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        // Delte the range from [l, r]
        
        // Take the range from [0, l - 1]
        int x = 0, y = 0, mn_pref = 0, mx_pref = 0;
        debug() << imie(l) imie(r);
        if(l - 1 >= 0){
            mn_pref = pref[l - 1].first , mx_pref = pref[l-1].second;
            x = values[l - 1];
            y = values[l - 1];
        }
        debug() << imie(suff[r]);
        int mn_suff = suff[r].first;
        int mx_suff = suff[r].second;
        if(mx_suff - values[r] > 0){
            x += mx_suff - values[r];
        } 
        if(mn_suff - values[r] < 0){
            y += mn_suff - values[r];
        }
        debug() << imie(m);
        debug() << imie(x) imie(y);
        debug() << imie(mx_pref) imie(mn_pref);
        debug() << imie(mx_suff) imie(mn_suff);
        
        cout << max(mx_pref, x) - min(mn_pref, y) + 1 << endl;
    }
    
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
