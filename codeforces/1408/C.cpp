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

double find_1_time(vector<int>&a, double loc){
    int n = a.size();
    double t = 0;
    int start_speed = 1;
    int start_loc = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > loc)break;
        t += double(a[i] - start_loc)/double(start_speed);
        start_speed++;
        start_loc = a[i];
    }
    t += (loc - start_loc)/double(start_speed); 
    return t;
}
double find_2_time(vector<int>&a, double loc, int l){
    int n = a.size();
    double t = 0;
    int start_speed = 1;
    int start_loc = l;
    for(int i = n-1; i >= 0; i--){
        if(a[i] < loc)break;
        t += (start_loc - a[i])/double(start_speed);
        start_speed++;
        start_loc = a[i];
    }
    t += (abs(loc - start_loc))/double(start_speed); 
    return t;
}


void test_case(){
    int n, l;
    cin >> n >> l;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    double low = 0;
    double high = l;
    while(low < high){
        double location = low + (high - low)/2;
        double time1 = find_1_time(a, location);
        double time2 = find_2_time(a, location, l);
        debug() << imie(time1) imie(time2) imie(location);
        if(abs(time1 - time2) < 1e-7){
            printf("%0.16lf\n", time1);
            break;
        }else if(time1 < time2){
            low = location;
        }else{
            high = location;
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


 
