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
    
    ll sum = 0;
    for(int i = n - 1; i > 0; i--){
        sum += abs(a[i] - a[i - 1]);
        
    }
    ll best = sum;
    for(int i = 1; i < n-1; i++){
        int minus = abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]);
        int add = abs(-a[i - 1] + a[i + 1]);
        debug() << imie(i) imie(minus) imie(add);
        best = min(best, sum - minus + add);
    }
    best = min({best, sum - abs(-a[0] +a[1]), sum - abs(-a[n - 2] +a[n - 1])});
    
    cout << best << endl;
    
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
