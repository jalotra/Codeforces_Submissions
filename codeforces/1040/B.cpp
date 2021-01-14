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

int turn_over(int idx, int n, int k){
    // idx -> (idx - k to idx + k + 0)
    // Next index should be idx + 2*k + 1 -> (idx + k + 1 to idx + 3*k + 1)
    // Next index should be idx + 4*k + 2 -> (idx + 3*k + 2 to idx + 5*k + 2)
    int ans = 1;
    int mid = idx;
    int done = 0;
    while(mid < n){
        done++;
        if(mid + k < n){
            done += k;
        }else{
            done += n - mid - 1;
        }
        
        if(mid - k >= 0){
            done += k;
        }else{
            done += mid;
        }
        mid = idx + (2*ans)*k + ans; 
        if(mid >= n)break;
        ans += 1;
    }
    if(done >= n){
        return ans;
    }else{
        return INT_MAX;
    }
}

// 0 1 2 3 4 5 6 7 8 9 


void test_case(){
    int n, k;
    cin >> n >> k;
    
    // 
    int ans = INT_MAX;
    int min_idx = 0;
    for(int idx = 0; idx <= k; idx++){
        // Turn this pan over and start from here.
        int here = turn_over(idx, n, k);
        if(here < ans){
            ans = here;
            min_idx = idx;
        }
    }
    
    cout << ans << endl;
    debug() << imie(min_idx);
    // Now Start from min_idx;
    int x = min_idx;
    int i = 1;
    while(min_idx < n){
        cout << min_idx + 1 << " ";
        min_idx = x + (2*i)*k + i;
        i += 1; 
    }cout << endl;
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
