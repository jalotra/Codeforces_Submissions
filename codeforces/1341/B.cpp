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
    int n, k;
    cin >> n >> k;
    vector<int>a(n), peaks(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i] > a[i - 1] && a[i] > a[i + 1]){
            peaks[i]++;
        }
        peaks[i] += peaks[i - 1];
    }
    
    
    
    debug() << imie(peaks);
    int mx = INT_MIN;
    for(int l = 0; l < n - k + 1; l++){
        int r = l + k - 1;
        mx = max(mx, peaks[r - 1] - peaks[l]);
    }
    
    for(int l = 0; l < n - k + 1; l++){
        int r = l + k - 1;
        int here = peaks[r - 1] - peaks[l];
        if(here == mx){
            cout << mx + 1 << " " << l + 1<< endl;
            break;
        }
    }
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
