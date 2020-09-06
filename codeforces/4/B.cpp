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

void test_case(){
   int d, sumtime;
   cin >> d >> sumtime;
   vector<int>mntime(d), mxtime(d);
   int mn_possible = 0;
   int mx_possible = 0;
   for(int i = 0; i < d; i++){
       cin >> mntime[i] >> mxtime[i];
       mn_possible += mntime[i];
       mx_possible += mxtime[i];
   }
   
   if(sumtime < mn_possible || sumtime > mx_possible){
       cout << "NO" << endl;
   }else{
       cout << "YES" << endl;
       int initial_sum = mn_possible;
       vector<int>a(d, 0);
       for(int i = 0; i < d; i++){
           a[i] = mntime[i];
       }
       int last_idx = -1;
       while(initial_sum < sumtime){
           int idx = max_element(mxtime.begin(), mxtime.end()) - mxtime.begin();
           initial_sum -= mntime[idx];
           initial_sum += mxtime[idx];
           a[idx] = mxtime[idx];
           mxtime[idx] = INT_MIN;
           last_idx = idx;
       }
       if(last_idx != -1 && initial_sum > sumtime){
           int diff = initial_sum - sumtime;
           a[last_idx] -= diff;
       }
       
       for(int i = 0; i < d; i++){
           cout << a[i] << " ";
       }cout << endl;
       
   }
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
