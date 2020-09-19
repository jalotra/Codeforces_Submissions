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

const long long mod = 1e+9 + 7; 

vector<long long>dp_table;

long long solve(long long remain){
    if(remain == 0)return 1;
    else if(remain < 0) return 0;
    if(dp_table[remain] > 0)return dp_table[remain];
    long long ans = 0;
    for(long long i = 3; i <= remain; i++){
        (ans += solve(remain - i)) %= mod;
    }
    
    return dp_table[remain] = ans;
}

bool comp(pair<long long, long long>a, pair<long long, long long>b){
    return (a.first + a.second) < (b.first + b.second);
}


void test_case(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int raze_odd = 0, raze_even =0 , breach_odd = 0, breach_even = 0;
    for(int j = 1; j <= n; j++){
        int i = j - 1;
        if(j%2 == 1){
            if((s[i] - '0')%2 == 0){
                raze_even ++;
            }else{
                raze_odd ++;
            }
        }else{
            if((s[i] - '0')%2 == 0){
                breach_even ++;
            }else{
                breach_odd ++;
            }
        }
    }
    if(n%2 == 0){
        //  breach will be the last one
        if(breach_even >= 1){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
        
    }else{
        // raze will be the last one
        if(raze_odd >= 1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
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


 
