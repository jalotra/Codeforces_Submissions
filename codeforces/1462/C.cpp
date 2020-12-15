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
    
    int x;
    cin >> x;
    if(x > 45){
        cout << -1 << endl;
        return;
    }
    vector<int>a(9);
    for(int i = 0; i < 9; i++){
        a[i] = i  + 1;
    }
    string ans;
    for(int i = 0; i < (1 << 9); i++){
        bitset<32>b(i);
        //debug() << imie(i) imie(b);
        vector<int>values;
        debug() << imie(b);
        for(int j = 0; j <= 8; j++){
            if(b[j] > 0){
                values.push_back(a[j]);
            }
        }
        debug() << imie(values);
        if(accumulate(values.begin(), values.end(), 0) == x){
            sort(values.begin(), values.end());
            string curr = "";
            for(int y: values){
                curr += (y + '0');
            }
            if(ans.size()){
                if(curr.size() < ans.size()){
                    ans = curr;
                }else if(curr.size() == ans.size()){
                    ans = min(ans, curr);
                }
            }
            else ans = curr; 
        }
    }
    cout << ans << endl;
    
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
