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

vector<bool>is_prime(1e+5, true);
vector<int>primes;
void setup(){
    int n = 1e+5 - 1;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 0; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    // debug() << imie(primes);
}


void test_case(){
    int n;
    cin >> n;
    vector<vector<int>>a(n, vector<int>(n, 1));
    int v = n - 1;
    int idx = lower_bound(primes.begin(), primes.end(), v) - primes.begin();
    int value;
    while(true){
        int curr = primes[idx];
        int needed = curr - v;
        if(needed > 0 && !binary_search(primes.begin(), primes.end(), needed)){
            value = needed;
            break;
        }
        //cout << "here";
        idx++;
    }
    for(int i = 0; i < n - 1; i++){
        a[n-1][i] = value;
        a[i][n-1] = value;
    }
    int new_value = (n - 1)*value;
    debug() << imie(a) imie(value) imie(new_value);
    
    idx = lower_bound(primes.begin(), primes.end(), new_value) - primes.begin();
    while(true){
        int curr = primes[idx];
        int needed = curr - new_value;
        if(needed >= 0 && !binary_search(primes.begin(), primes.end(), needed)){
            value = needed;
            break;
        }
        
        idx++;
    }
    a[n-1][n-1] = value;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }
    
    
    
} 


int main(){
    
    setup();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
