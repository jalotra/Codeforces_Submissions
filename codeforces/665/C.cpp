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
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int found = 0;
        int j = i;
        while(j < n && s[i] == s[j]){
            j++;
            found++;
        }
        debug() << imie(i) imie(j);
        if(found > 0){
            char make = 'a';
            for(char x = 'a'; x <= 'z'; x++){
                if((j < n ? (s[j] != x) : 1) && s[i] != x){
                    make = x;
                    break;
                }
            }
            debug() << imie(i) imie(make);
            for(int k = i + 1; k < j; k+= 2){
                debug() << imie(k) imie(j);
                s[k] = make;
            }
            i = j - 1;
        }
    }
    cout << s << endl;
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
