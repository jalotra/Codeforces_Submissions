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
    int x = 0, y = 0;
    int prev_x = 0, prev_y = 0;
    long long ans = 1;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0)continue;
        int mx = max(x, y);
        debug() << imie(n) imie(a) imie(b);
        debug() << imie(x) imie(y) imie(mx);
        x = mx;
        y = mx;
        if(x == prev_x && y == prev_y){
            x++, y++;
        }
        debug() << imie(prev_x) imie(prev_y);
        debug() << imie(x) imie(y);
        debug();
        if(x <= a && y <= b){
            ans++;
            ans += min(a - x, b - y);
        }
        debug() << imie(ans);
        
        prev_x = x + min(a - x, b - y), prev_y = y + min(a - x, b - y);
        x = a, y = b; 
        
    }
    cout << ans << endl;
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
