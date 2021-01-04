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
    vector<ll>a, b;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x%2){
            b.push_back(x);
        }else{
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    
    debug() << imie(a) imie(b);
    
    int player = 0, x = 0, y = 0;
    ll alice = 0, bob = 0;
    while(x < a.size() && y < b.size()){
        debug() << imie(x) imie(y);
        if(player == 0){
            if(a[x] >= b[y]){
                alice += a[x];
                x++;
            }else{
                y++;
            }
        }else{
            if(a[x] <= b[y]){
                bob += b[y];
                y++;
            }else{
                x++;
            }
        }
        player = player^1;
    }
    while(x < a.size()){
        if(player == 0){
            alice += a[x];
            x++;
        }else{
            x++;
        }
        player = player^1;
    }
    while(y < b.size()){
        if(player == 1){
            bob += b[y];
            y++;
        }else{
            y++;
        }
        player = player^1;
    }
    
    
    //debug() << imie(alice) imie(bob);
    
    if(alice > bob){
        cout << "Alice" << endl;
    }else if(alice == bob){
        cout << "Tie" << endl;
    }else{
        cout << "Bob" << endl;
    }
    
    
    
    
} 


int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
