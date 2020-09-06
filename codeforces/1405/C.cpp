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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    for(int i = 0; i < n; i++){
        if(s[i] != '?'){
            if(i + k < n){
                //cout << i << endl;
                if(s[i+k] != '?' && s[i + k] != s[i]){
                    cout << "NO" << endl;
                    return;
                }
                s[i+k] = s[i];
            }
            if(i - k >= 0){
                if(s[i-k] != '?' && s[i-k] != s[i]){
                    cout << "NO" << endl;
                    return;
                }
                s[i-k] = s[i];
            }
            
        }
    }
    vector<int>ones(n+1, 0);
    vector<int>zeros(n+1, 0);
    vector<int>questions(n+1, 0);
    for(int i = 1; i <= n; i++){
        ones[i] = ones[i-1];
        zeros[i] = zeros[i-1];
        questions[i] = questions[i-1];
        if(s[i-1] == '1')ones[i]++;
        if(s[i-1] == '0')zeros[i]++;
        if(s[i-1] == '?')questions[i]++;
    }
    //for(int i = 0; i <= n; i++){
       //cout << ones[i] << " ";
    //}cout << endl;
    //for(int i = 0; i <= n; i++){
       //cout << zeros[i] << " ";
    //}cout << endl;
    
    for(int i = k; i <= n; i++){
        int current_zeros = zeros[i] - (i-k>= 0 ? zeros[i- k] : 0);
        int current_ones = ones[i] - (i-k>= 0 ? ones[i- k] : 0);
        //cout << current_zeros << " " << current_ones << endl;
        if(current_zeros != current_ones){
            if(questions[i] - questions[i-k] >= abs(current_ones - current_zeros)){
                continue;
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
