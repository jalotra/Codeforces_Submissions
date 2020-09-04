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

int find_factors(int x, int y){
    
    for(int i = y - 1; i >= 0; i--){
        if((x/i )* i == x){
            //cout << i << endl;
            return i;
        }
    }
    
}

const int inf = 1e+9 + 5;

pair<int, int>good(vector<int>&a){
    int min_elem = *min_element(a.begin(), a.end());
    int max_elem = *max_element(a.begin(), a.end());
    
    if(min_elem > 0){
        return {true, max_elem};
    }else{
        return {false, inf};
    }
}

void test_case(){
    
    int n,x, y;
    cin >> n >> x >> y;
    
    int max_diff = find_factors(y - x, n);
    int k = (y - x)/max_diff;
    debug() << imie(max_diff) << imie(k);
    
    vector<int>result(n, -1);
    int mx = INT_MAX;
    for(int i = 0; i < n; i++){
        vector<int>possible(n, inf);
        if(i + max_diff >= n){
            continue;
        }
        possible[i] = x;
        possible[i + max_diff] = y;
        for(int j = i - 1; j >= 0; j--){
            if(j >= 0 && possible[j] == inf)possible[j] = possible[j + 1] - k;
        }
        for(int j = i + 1; j < n; j++){
            if(possible[j] == inf && j < n){
                possible[j] = possible[j - 1] + k; 
            }
        }
        bool check = good(possible).first;
        int max_elem =  good(possible).second;
        if(check &&  max_elem < mx){
            result = possible;
            mx = max_elem;
        }
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }cout << endl;
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
    
} 


 
