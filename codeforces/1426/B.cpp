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

struct matrix{
    
    int rows, cols;
    vector<vector<int>>a;
    matrix(){
        rows = 2;
        cols = 2;
        a.resize(rows, vector<int>(cols, 0));
    }
    
};


void test_case(){
    
    int n, m;
    cin >> n >> m;
    vector<struct matrix>x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i].a[0][0]  >> x[i].a[0][1];
        cin >> x[i].a[1][0]  >> x[i].a[1][1];
    }
    if(m%2){
        cout << "NO" << endl;
    }else{
        int found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(x[i].a[1][0] == x[i].a[0][1]){
                    found = true;
                }
            }
        }
        if(found){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
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


 
