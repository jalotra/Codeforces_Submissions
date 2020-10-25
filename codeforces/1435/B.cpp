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
    vector<vector<int>>a(n, vector<int>(m));
    vector<vector<int>>rows(n, vector<int>(m));
    vector<vector<int>>cols(m, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> rows[i][j];
        }
    }
    debug() << imie(rows);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> cols[i][j];
        }
    }
    debug() << imie(cols);
    int start = 0;
    while(start < n){
        for(int row = 0; row < n; row++){
            int found = false;
            for(int col = 0; col < m; col++){
                if(rows[row][0] == cols[col][start]){
                    a[start] = rows[row];
                    start++;
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            } 
        }
    }
    //debug() << imie(a);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }
} 


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
