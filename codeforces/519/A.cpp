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

bool f(char c){
    if(toupper(c) == c)return true;
    return false;
}

int values(char c){
    
    switch(c){
        case 'q':
            return 9;
        case 'r':
            return 5;
        case 'b':
            return 3;
        case 'n':
            return 3;
        case 'p':
            return 1;
        default : 
            return 0;
    } 
        
    
}



void test_case(){
    
    int n = 8, m = 8;
    int white = 0, black = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(f(c)){
                white += values(tolower(c));
            }else{
                black += values(c);
            }
        }   
    }
    
    if(white > black){
        cout << "White" << endl; 
    }else if(white == black){
        cout << "Draw" << endl;
    }else{
        cout << "Black" << endl;
    }
    
} 


int main(){
    
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
