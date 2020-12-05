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

int MAX_N = 2005;

void test_case(){
    
    int n;
    cin >> n ;
    vector<vector<int>>a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = (s[j] - '0');
        }
    }
    
    vector<ll>ans(10, 0);
    
    vector<int>max_row(10), max_col(10), min_col(10, MAX_N), min_row(10, MAX_N);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int d = a[i][j];
            max_row[d] = max(max_row[d], i), min_row[d] = min(min_row[d], i);
            max_col[d] = max(max_col[d], j), min_col[d] = min(min_col[d], j);
        }
    }
    debug() << imie(max_row[2]) imie(min_row[2]) imie(max_col[2]) imie(min_col[2]);
    
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int d = a[i][j];
            ll curr = 0;
            curr = max(curr, max(i, n - i - 1)*1ll*max(max_col[d] - j, j - min_col[d]));
            if(d == 2)debug() << imie(curr) ;
            curr = max(curr, max(j, n - j - 1)*1ll*max(max_row[d] - i, i - min_row[d]));
            if(d == 2)debug() << imie(curr) ;
            ans[d] = max(ans[d], curr);
        }
    }
    
    for(int i = 0; i < 10; i++){
        cout << ans[i] << (i == 9 ? "\n" : " ");
    }
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
