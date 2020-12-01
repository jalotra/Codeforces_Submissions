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

long long nc2(long long n){
    long long ans = n*1ll*(n - 1);
    return ans/2;
}



void test_case(){
    
    int m, s;
    cin >> m >> s;
    vector<int>mx(m), mn(m);
    
    if(s > 9*m || (m > 1 && s == 0)){
        cout << -1 << " " << -1 << endl;
        return;
    }
    
    int n_s = s;
    for(int i = 0; i < m; i++){
        mx[i] = min(n_s, 9);
        if(n_s <= 0){
            break;
        }
        n_s -= min(n_s, 9);
    }
    n_s = s - 1;
    mn[0] = 1;
    for(int i = m - 1; i >= 0; i--){
        mn[i] += min(n_s, 9);
        if(n_s <= 0){
            break;
        }
        n_s -= min(n_s, 9);
        
    }
    
    for(auto v : mn){
        cout << v;
    }cout << " ";
    
    for(auto v : mx){
        cout << v;
    }cout << endl;

}


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
