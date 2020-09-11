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

vector<vector<int>>g;
vector<bool>visited;
bool dfs(int x, int end){
    if(x == end){
        return true;
    }
    int ans = false;
    if(!visited[x]){
        visited[x] = true;
        for(auto v : g[x]){
            ans = ans || dfs(v, end);
        }
    }
    
    return ans;
}



void test_case(){
    int n;
    cin >> n;
    vector<int>matches(n);
    g.resize(n);
    visited.resize(n);
    for(int i = 0; i  < (n*(n-1))/2 - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        matches[x]++;
        matches[y]++;
    }
    int start = -10, end = -10;
    bool start_done = false;
    for(int i = 0; i < n; i++){
        if(matches[i] != n-1){
            if(!start_done){
                start = i;
                start_done = true;
            }
            else end = i;
        }
    }
    
    debug() << imie(start) imie(end);
    int result = dfs(start, end);
    //cout << result << endl;
    if(result){
        cout << start + 1 << " " << end + 1<< endl;
    }else{
       cout << end + 1 << " " << start + 1<< endl; 
    }
    
    
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
