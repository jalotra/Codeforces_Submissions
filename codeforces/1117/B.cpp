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
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int>a(n);
    long long mx1 = LONG_LONG_MIN, mx2 = LONG_LONG_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= mx1){
            long long temp = mx1;
            mx1 = a[i];
            mx2 = temp;
        }else if(a[i] > mx2){
            mx2 = a[i];
        }
    }
    debug() << imie(mx1) imie(mx2);
    long long ans = 0;
    ans += (m/(k + 1))*mx1*k;
    ans += (m/(k + 1))*mx2;
    ans += (m%(k + 1))*mx1;
    
    cout << ans << endl;
    
} 

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
