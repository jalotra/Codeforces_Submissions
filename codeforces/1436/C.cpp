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

const int mod = 1e+9 + 7;
vector<int>filled;
void bs(int pos, int n){
    filled.resize(n, -1);
    int left = 0;
    int right = n;
    // 1 - greater
    // 0 - less 
    while(left < right){
        int mid = (left + right)/2;
        if(mid <= pos){
            filled[mid] = 0;
            left = mid + 1;
        }else{
            filled[mid] = 1;
            right = mid;
        }
    }
    debug() << imie(filled);
}


void test_case(){
    int n, x, pos;
    cin >> n >> x >> pos;
    bs(pos, n);
    long long ans = 1;
    int less_values = x - 1;
    int bigger_values = n - x;
    for(int i = 0; i < n; i++){
        if(filled[i] == 0 && i != pos){
            (ans *= less_values) %= mod;
            less_values--;
        }else if(filled[i] == 1 && i != pos){
            (ans *= bigger_values) %= mod;
            bigger_values--;
        }
        debug() << imie(i) imie(ans);
    }
    int total = less_values + bigger_values; 
    for(int i = 0; i < n; i++){
        if(filled[i] == -1 && i != pos){
            (ans *= total) %= mod;
            total--;
        }
    }
    cout << ans%mod<< endl;
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
