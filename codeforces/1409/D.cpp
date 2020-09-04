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

int summer(string s){
    int sum = 0;
    for(int i = 0; i < (int)s.size(); i++){
        sum += s[i] - '0';
    }
    
    //cout << sum;
    return sum;
}

int return_digit(string s, int i){
    //string s = to_string(x);
    return (int)(s[s.size() - i] - '0');
}

void test_case(){
    
    ll n, s;
    cin >> n >> s;
    
    string str = to_string(n);
    int cnt = 1;
    unsigned ll steps = 0;
    int initial_sum = summer(str);
    while(initial_sum > s){
        debug() << imie(initial_sum); 
        int digit = return_digit(str, cnt) + (cnt > 1 ? 1 : 0);
        initial_sum -= digit - (cnt >= 1 ? 1 : 0);
        steps += (long long)pow(10,cnt - 1)*(10 - digit);
        debug() << imie(initial_sum) imie(digit)  imie(steps);
        cnt += 1;
     }

    
    cout << steps << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
