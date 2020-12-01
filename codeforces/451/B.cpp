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

long long nc2(long long n){
    long long ans = n*1ll*(n - 1);
    return ans/2;
}



void test_case(){
    
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    
    b = a;
    sort(b.begin(), b.end());
    
    vector<pair<int, int>>s;
    int l = -1, r = -1;  
    for(int i = 0; i < n; i++){
        if(a[i] != b[i] && l == -1){
            l = i;
        }else if(a[i] == b[i] &&  l != -1){
            r = i - 1;
        }
        if(l != -1 && r != -1){
            s.push_back(make_pair(l, r));
            l = -1, r = -1;
        }
        debug() << imie(i) imie(s);
    }
    if(r == -1){
        if(l != -1){
            s.push_back(make_pair(l, n - 1));
        }else if(s.size() == 0){
            s.push_back(make_pair(0, 0));
        }
    }
    debug() << imie(s);
    // merging the intervals
    int start = s[0].first;
    int end = s[0].second;
    for(int i = 1; i < (int)s.size(); i++){
        if(abs(end - s[i].first) == 2){
            end = s[i].second;
        }else{
            cout << "no" << endl;
            return ;
        }
    }
    // check
    for(int i = start +1; i <= end; i++){
        if(a[i - 1] < a[i]){
            cout << "no" << endl;
            return;
        }
    }
    
    cout << "yes" << endl;
    cout << start + 1 << " " << end + 1 << endl;
    
    
}


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
