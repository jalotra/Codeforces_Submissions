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
    
    int n, m;
    cin >> n >> m;
    map<string, pair<string, int>>mp;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        mp[a] = make_pair(b, 2);
        mp[b] = make_pair(a, 1);
    }
    
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        pair<string , int>poss = mp[x];
        string first_language, second_language; 
        if(poss.second == 2){
            second_language = poss.first;
            first_language = x;
        }else{
            first_language = x;
            second_language = poss.first;
        }
        if(first_language.size() == second_language.size()){
            cout << first_language << " ";
        }else{
            int mn_len = min(first_language.size(), second_language.size());
            if(mn_len == first_language.size()){
                cout << first_language << " ";
            }else{
                cout << second_language << " ";
            }
        }
    }cout << endl;
    
    
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
