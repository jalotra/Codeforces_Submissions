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


struct Node{
    
    //unordered_set<int>levels;
    int max_level;
    Node(int level = 0){
        max_level = level;
    }
    void set_level(int x){
        max_level = max(x, max_level);
    }
    
    //bool is_greater(int x){
        //if(max_le)
    //}
    
};
int n, m;
bool good(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m){
        return true;
    }
    return false;
}

vector<vector<int>>a;
vector<vector<int>>pref_sums;
vector<vector<Node*>>b;


void test_case(){
    cin >> n >> m;
    a.clear(), b.clear(), pref_sums.clear();
    a.resize(n, vector<int>(m));
    pref_sums.resize(n, vector<int>(m));
    b.resize(n, vector<Node*>(m));
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = (s[j] == '*' ? 1 : 0);
            if(a[i][j])pref_sums[i][j] += 1;
            if(j != 0){
                pref_sums[i][j] += pref_sums[i][j-1];
            }
            
        }
    }
    
    debug()<< imie(a);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = new Node();
        }
    }
    
    debug() << imie(pref_sums);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                if(i == 0){
                    b[i][j]->set_level(1);
                    ans++;
                    continue;
                }
                int k = 0;
                while(true){
                    //debug() << imie(i) imie(j) imie(k) imie(good(i, j - k)) imie(good(i, j + k))imie(pref_sums[i][j + k] - pref_sums[i][j - k]);
                    if(good(i, j - k) && good(i, j + k) && (pref_sums[i][j + k] - (good(i, j - k - 1) == true ? pref_sums[i][j - k - 1] : 0) == 2*k + 1)){
                        if(b[i-1][j]->max_level >= k){
                            ans++;
                            b[i][j]->set_level(k + 1);
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                    k++;
                }
            }
        }
    }
    cout << ans << endl;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            delete b[i][j];
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


 
