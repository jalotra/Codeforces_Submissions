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

vector<long long>primes;
void make_primes(int n){
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}



void test_case(){
    int d;
    cin >> d;
    long long ans = 1;
    long long previous = 1;
    debug() << imie(primes.size());
    for(int i = 0; i < 2; i++){
        long long prime_needed = previous + d;
        int idx = lower_bound(primes.begin(), primes.end(), prime_needed) - primes.begin();
        assert(idx != (int)primes.size());
        ans *= primes[idx];
        debug() << imie(i) imie(prime_needed) imie(primes[idx]);
        previous = primes[idx];
    }
    
    cout << ans << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    make_primes(1000005);
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
