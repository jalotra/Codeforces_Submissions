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
const int mxN = 3e5 + 5;
int n, a[mxN];
int isHill(int i){
    if(i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]){
        return true;
    }
    return false;
}

int isValley(int i){
    if(i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]){
        return true;
    }
    return false;
}

void test_case(){
    cin >> n;
    for(int i= 0; i < n; i++)cin >> a[i];
    int s[n] = {false};
    for(int i = 1; i < n - 1; i++){
        if(isHill(i))s[i] = true;
        if(isValley(i))s[i] = true;
    }
    int ans = 0;
    for(int x : s){
        //cout << x << " ";
        ans += x;
    }// cout << endl;
    int curr = ans;
    for(int i = 0; i < n; i++){
        int here = a[i];
        if(i > 0 && i < n - 1){
            a[i] = a[i - 1];
            curr = min(curr, ans - s[i] - s[i - 1] - s[i + 1] + isHill(i) + isHill(i - 1) + isHill(i + 1) + isValley(i) + isValley(i - 1) + isValley(i + 1));
        }
        if(i > 0 && i < n - 1){
            a[i] = a[i + 1];
            curr = min(curr, ans - s[i] - s[i - 1] - s[i + 1] + isHill(i) + isHill(i - 1) + isHill(i + 1) + isValley(i) + isValley(i - 1) + isValley(i + 1));
        }
        a[i] = here;
        debug() << imie(curr)  imie(ans);
    }    
        
            
    cout << curr << endl;
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
