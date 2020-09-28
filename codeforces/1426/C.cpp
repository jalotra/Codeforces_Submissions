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

int c(int a, int b){
    return (a + b - 1)/b;
}

int f(int n, int x){
    return c(n - x, x) + (x - 1);
}

void ternary_search(int n){
    int low = 1;
    int high = n;
    
    while((high - low) >= 3){
        int m1 = low + (high - low)/3;
        int m2 = high - (high - low)/3;
        
        int f1 = f(n, m1);
        int f2 = f(n, m2);
        debug() << imie(low) imie(high) imie(m1) imie(m2) imie(f1) imie(f2);
        if(f1 < f2){
            high = m2;
        }else{
            low = m1;
        }
    }
    int ans = INT_MAX;
    for(int i = max(1, low - 1000); i <= high + 1000; i++){
        ans = min(ans, f(n, i));
    }
    
    cout << ans << "\n";
    
}




void test_case(){
    int n;
    cin >> n;
    ternary_search(n);
    
    //for(int i = 1; i <= n; i++){
        //cout << f(n, i) << " ";
    //}cout << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
