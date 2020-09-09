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
    vector<pair<int, int>>v;
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    v.push_back({0, 0});
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'L'){
            for(auto vii : v){
                if(vii.first == x - 1 && vii.second == y){
                    debug() << imie(x) << imie(y);
                    cout << "BUG" << endl;
                    return;
                }
            }
            int cnt = 0;
            for(auto vii : v){
                if(abs(vii.first - x + 1) + abs(vii.second - y) == 1){
                    cnt++;
                }
            }
            if(cnt > 1){
                cout << "BUG" << endl;
                return;
            }
            x -= 1;
            v.push_back({x ,y});
        }else if(s[i] == 'R'){
            for(auto vii : v){
                if(vii.first == x + 1 && vii.second == y){
                    debug() << imie(x) << imie(y);
                    cout << "BUG" << endl;
                    return;
                }
            }
            int cnt = 0;
            for(auto vii : v){
                if(abs(vii.first - x - 1) + abs(vii.second - y) == 1){
                    cnt++;
                }
            }
            if(cnt > 1){
                cout << "BUG" << endl;
                return;
            }
            x += 1;
            v.push_back({x ,y});
        }else if(s[i] == 'U'){
            for(auto vii : v){
                if(vii.first == x && vii.second == y + 1){
                    debug() << imie(x) << imie(y);
                    cout << "BUG" << endl;
                    return;
                }
            }
            int cnt = 0;
            for(auto vii : v){
                if(abs(vii.first - x) + abs(vii.second - y - 1) == 1){
                    cnt++;
                }
            }
            if(cnt > 1){
                cout << "BUG" << endl;
                return;
            }
            y += 1;
            v.push_back({x ,y});
        }else{
            for(auto vii : v){
                if(vii.first == x && vii.second == y - 1){
                    debug() << imie(x) << imie(y);
                    cout << "BUG" << endl;
                    return;
                }
            }
            int cnt = 0;
            for(auto vii : v){
                if(abs(vii.first - x) + abs(vii.second - y + 1) == 1){
                    cnt++;
                }
            }
            if(cnt > 1){
                cout << "BUG" << endl;
                return;
            }
            y -= 1;
            v.push_back({x ,y});
        }
        
    }
    int cnt = 0;
    for(auto vii : v){
        if(abs(vii.first - x) + abs(vii.second - y) == 1){
            cnt++;
        }
    }
    if(cnt > 1)cout << "BUG" << endl;
    else cout << "OK" << endl;
    
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
