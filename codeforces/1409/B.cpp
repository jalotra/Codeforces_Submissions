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
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    
    ll ans = LONG_LONG_MAX;
    
    ll n_n = n;
    ll n_a = a;
    //ll del = n - n_a;
    n_a = max(a - n_n, x);
    n_n = n -(a - n_a);
    ans = min(ans, max(y, b - n_n)*n_a);
    
    swap(a, b);
    swap(x, y);
    n_n = n;
    n_a = a;
    n_a = max(a - n_n, x);
    n_n = n -(a - n_a);
    ans = min(ans, max(y, b - n_n)*n_a);
    
    cout << ans << endl;
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
