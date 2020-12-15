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
    string s;
    cin >> s;
    
    
    //vector<vector<int>>a(3);
    //for(int i = 0; i < n; i++){
        //if(s[i] == '0'){
            //a[0].push_back(i);
        //}else if(i + 1 < n && s.substr(i, 2) == "20"){
            //a[1].push_back(i);
        //}else if(i + 2 < n && s.substr(i, 3) == "020"){
            //a[2].push_back(i);
        //}
    //}
    //bool found = false;
    //for(int i = 0; i < n; i++){
        //if(s[i] == '2'){
            //auto idx = lower_bound(a[2].begin(), a[2].end(), i + 1);
            //if(idx != a[2].end()){
                //found = true;
                //break;
            //}
        //}if(i + 1 < n && s.substr(i, 2) == "20"){
            //auto idx = lower_bound(a[1].begin(), a[1].end(), i + 1);
            //if(idx != a[1].end()){
                //found = true;
                //break;
            //}
        //}if(i + 2 < n && s.substr(i, 3) == "202"){
            //auto idx = lower_bound(a[0].begin(), a[0].end(), i + 1);
            //if(idx != a[0].end()){
                //found = true;
                //break;
            //}
        //}
    //}
    
    //found == true ? cout << "Yes\n" : cout << "No\n";
    
    bool found = false;
    if(s[0] == '2' && s.substr(n - 3, 3) == "020")found = true;
    if(s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20")found = true;
    if(s.substr(0, 3) == "202" && s.substr(n - 1, 1) == "0")found = true;
    if(s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020")found = true;
    
    found == true ? cout << "Yes\n" : cout << "No\n";
    
} 


int main(){
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
