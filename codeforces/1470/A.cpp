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
    vector<int>k_values(n), c_values(m + 1);
    for(int i = 0; i < n; i++)cin >> k_values[i];
    for(int i = 1; i <= m; i++)cin >> c_values[i];
    
    sort(k_values.begin(), k_values.end(), greater<int>());
    debug() << imie(k_values);
    debug() << imie(c_values);
    int idx = 1; long long ans = 0;
    for(int i = 0; i < n; i++){
        debug() << imie(i) imie(idx) imie(k_values[i]);
        if(idx > k_values[i]){
            ans += c_values[k_values[i]];
        }else{
            ans += c_values[idx];
            idx++;
        }
        debug() << imie(ans);
    } 
    
    cout << ans << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
