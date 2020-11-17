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
    
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int zeros = 0, ones = 0;
    for(auto ch : s){
        if(ch == '0'){
            zeros++;
        }else{
            ones++;
        }
    }
    assert(ones + zeros == n);
    
    int init = c0*zeros + c1*ones;
    //debug() << imie(ones) imie(zeros);
    int ans = INT_MAX;
    for(int i = 0; i <= ones; i++){
        //debug() << imie(i) << ans << end 
        ans = min(ans, init + i*(c0 - c1 + h));
    }
    
    for(int i = 0; i <= zeros; i++){
        ans = min(ans, init + i*(c1 - c0 + h));
    }
    
    cout << ans << endl;
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
