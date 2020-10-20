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
    set<int>s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() == 1){
        cout << -1 << "\n";
        return ;
    } 
    int mx = *max_element(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i  < n; i++){
        if(a[i] == mx){
            if(i - 1 >= 0 && a[i - 1] < mx){
                ans = i;
                break;
            }else if(i + 1 < n && a[i + 1] < mx){
                ans = i;
                break;
            }
        }
    }
    ans++;
    cout << ans << endl;
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
