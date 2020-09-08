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
    
    vector<int>b(n);
    int g = *max_element(a.begin(), a.end());
    int index = max_element(a.begin(), a.end()) - a.begin(); 
    vector<bool>visited(n, false);
    visited[index] = true;
    b[0] = g;
    for(int i = 1; i < n; i++){
        int idx = -1;
        int curr_g = INT_MIN;
        for(int j = 0; j < n; j++){
            if(!visited[j] && __gcd(g, a[j]) > curr_g){
                idx = j;
                curr_g = __gcd(g, a[j]);
            }
        }
        b[i] = a[idx];
        visited[idx] = true;
        g = curr_g;
    }
    
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }cout << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
