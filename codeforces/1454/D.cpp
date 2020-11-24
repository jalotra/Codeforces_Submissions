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

vector<long long>res;
map<ll, ll>mp;
ll ans;
void solve(long long x){
    long long n = x;
    for(ll i = 2; i*i <= n; i++){
        if(x%i== 0){
            debug() << "here";
            ll curr = 0;
            while(x%i == 0){
                x /= i;
                curr++;
            }
            mp[i] = curr;
            ans = max(ans, curr);
        }
    }
    if(x > 1){
        mp[x] = 1;
        ans = max(ans, 1ll);
    }
    debug() << imie(mp);
        res.resize(ans, 1ll);
        for(pair<ll, ll>p : mp){
            ll times = p.second;
            ll value = p.first;
            debug() << imie(times) imie(value) imie(res);
            for(int i = res.size() - 1; i >= 0 && times > 0; i--){
                res[i] *= value;
                times--;
            }
        }
    //}
}

void test_case(){
    long long n;
    cin >> n;    
    
    solve(n);
    cout << ans << endl;
    for(ll x : res){
        cout << x << " ";
    }cout << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        mp.clear();
        res.clear();
        ans = 0;
        test_case();
    }
    
    return 0;
} 


 
