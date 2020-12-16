#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll fact[200005];
ll mod = 1e9 + 7;
void setup(){
    fact[0] = 1;
    for(int i = 1; i <= 200000; i++){
        fact[i] = (fact[i-1]*1ll*i);
        if(fact[i] >= mod){
            fact[i] = fact[i]%mod;
        }
    }
}
ll bin_exp_with_mod(ll a, ll b, ll mod){
    // Calculates a^b in O(log(b)) time complexity
    if(b == 0){
        return 1ll;
    }

    ll ans = bin_exp_with_mod(a, b/2, mod);
    if(b%2 == 0){
        ll curr = ans*ans;
        if(curr >= mod){
            return curr%mod;
        }
        return curr;
    }else{
        ll curr = ans*ans;
        if(curr >= mod){
            curr = curr%mod;
        }
        curr *= a;
        if(curr >= mod){
            return curr%mod;
        }
        return curr;
    }
}
ll mod_inverse(ll a, ll m){
    return bin_exp_with_mod(a, m - 2, m);
}

ll nck(ll n, ll k){
    if(n < k){
        return 0ll;
    }
    else{
        ll num = fact[n];
        ll deno1 = fact[n - k];
        ll deno2 = fact[k];

        deno1 = mod_inverse(deno1, mod);
        deno2 = mod_inverse(deno2, mod);

        num *= deno1;
        if(num >= mod)num = num%mod;
        num *= deno2;
        if(num >= mod)num = num%mod;
        return num%mod;

    }
}

void test_case(){
    int n, k, m;
    cin >> n >> m >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++)cin >> a[i];


    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int value = a[i];
        int idx = lower_bound(a.begin(), a.end(),value - k) - a.begin();
        int numbers = i - idx;
        ans += nck(numbers, m - 1);
    }
    cout << ans%mod << endl;

}


int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    setup();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();

    return 0;
}