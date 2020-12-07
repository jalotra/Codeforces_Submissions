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
    
    int n;
    cin >> n;
    vector<char>a[n];
    vector<vector<int>>b(2, vector<int>(3));
    for(int i = 0; i < n; i++){
        a[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'X'){
                b[0][(i + j)%3]++;
            }else if(a[i][j] == 'O'){
                b[1][(i + j)%3]++;
            }
        }
    }
    int value = INT_MAX;
    int x, y;
    
    for(int i = 0; i < 3; i++){
        int curr = INT_MAX;
        int first, second;
        for(int j = 0; j < 3; j++){
            if(i != j){
                if(b[0][i] + b[1][j] < curr){
                    curr =  b[0][i] + b[1][j];
                    first = i;
                    second = j;
                }
            }
        }
        if(curr < value){
            value = curr;
            x = first;
            y = second;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j)%3 == x && a[i][j] == 'X'){
                a[i][j] = 'O';
            }else if((i + j)%3 == y && a[i][j] == 'O'){
                a[i][j] = 'X';
        }
    }
}
    
    
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j];
        }cout << endl;
    }
    
    
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
