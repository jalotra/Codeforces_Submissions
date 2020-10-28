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

const int N = 1e+5 + 9;

pair<int, int>sec, fir;
int n; string s;

string mv = "UDLR";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
pair<int, int>d[N];


void test_case(){
    cin >> fir.first >> fir.second >> sec.first >> sec.second;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int id = -1;
        for(int j = 0; j < 4; j++){
            if(mv[j] == s[i]){
                id = j;
            }
        }
        assert(id != -1);
        d[i + 1] = make_pair(d[i].first + dx[id], d[i].second + dy[id]);
    }
    
    long long l = 0, r = 1e+18;
    while(r - l > 1){
        
        long long mid = l + (r - l)/2;
        long long cnt = mid/n, rem = mid%n;
        long long x = fir.first + d[rem].first + cnt *  1LL * d[n].first;
		long long y = fir.second + d[rem].second + cnt *  1LL * d[n].second;
		long long dist = abs(x - sec.first) + abs(y - sec.second);
		if(dist <= mid)
			r = mid;
		else
			l = mid;
    }
    if(r > 1e17) r = -1;
    
    cout << r << endl;
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
