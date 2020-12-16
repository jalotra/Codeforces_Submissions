#include <bits/stdc++.h>
using namespace std;

#define ll long long

void test_case(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int value = a[i];
        int idx = lower_bound(a.begin(), a.end(),value - 2) - a.begin();
        int numbers = i - idx;
        ans += ((numbers)*1ll*(numbers - 1))/2;
    }cout << ans << endl;

}


int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();

    return 0;
}