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

ll npr(int n, int r){
    
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= (ll)i;
    }
    for(int i = 1; i <= r; i++){
        ans = ans/(ll)i;
    }
    for(int i = 1; i <= (n - r); i++){
        ans = ans/(ll)i;
    }
    
    return ans;
    
}


void test_case(){
    
    string a, b;
    cin >> a >> b;
    
    int sum_a = 0;
    for(char c : a){
        sum_a += (c == '+' ? 1 : -1);
    }
    
    int sum_b = 0;
    int unknowns = 0;
    for(char c : b){
        if(c == '?')unknowns++;
        sum_b += (c == '+' ? 1 : (c == '-' ? -1 : 0));
    }
    
    long double prob = 0;
    if(unknowns == 0){
        if(sum_a == sum_b){
            prob = 1.0;
        }else{
            sum_a = 0.0;
        }
    }else{
        
        int max_possible = unknowns + sum_b;
        int min_possible = sum_b - unknowns;
        if(sum_a > max_possible || sum_a < min_possible){
            ;
        }else{
            debug() << imie(unknowns) imie(sum_a) imie(sum_b); 
            int found = 0;
            int m = -1, n = -1;
            for(int pos = 0; pos <= unknowns; pos++){
                int neg = unknowns - pos;
                if(sum_b + pos - neg == sum_a){
                    m = pos;
                    n = neg;
                }
            }
            debug() << imie(m) imie(n);
            if(m != -1 && n  != -1){
                ll values = npr(unknowns, m);
                debug() << imie(values);
                prob = values/(long double)pow(2, unknowns);
            }
            
            
        }
        
        
    }
    cout << setprecision(20) << prob << endl;
    
    
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
