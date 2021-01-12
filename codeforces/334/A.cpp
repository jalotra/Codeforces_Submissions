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
    // n = 4
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 = (n**2(n**2 + 1))//2
    
    int n;
    cin >> n;
    int start = 1, end = n*n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            cout << start << " ";
            start++;
        }
        for(int j = 0; j < n/2; j++){
            cout << end << " ";
            end--;
        }
        cout << endl;
    }

} 


int main(){
    
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
