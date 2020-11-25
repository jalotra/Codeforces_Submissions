#include <bits/stdc++.h>
#define int long long
using namespace std;

int range_max(int t[], int l, int r, int n) {  // max on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) res = max(res, t[l++]);
        if(r & 1) res = max(res, t[--r]);
    }
    return res;
}
int range_min(int t[], int l, int r, int n) {  // min on interval [l, r)
    int res = INT32_MAX;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) res = min(res, t[l++]);
        if(r & 1) res = min(res, t[--r]);
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;    cin >> t;
    while(t--)
    {
        int n;    cin >> n;
        int mintree[2 * n], maxtree[2 * n];
        for(int i = 0; i < n; i++)
        {
            cin >> mintree[n + i];
            maxtree[n + i] = mintree[n + i];
        }
        for(int i = n - 1; i > 0; i--)
        maxtree[i] = max(maxtree[i << 1], maxtree[i << 1 | 1]),
        mintree[i] = min(mintree[i << 1], mintree[i << 1 | 1]);

        int i;
        for(i = 0; i < n; i++)
        {
            int a, b, c;
            a = range_max(maxtree, 0, i + 1, n);
            int beg = i + 1, end = n - 2, mid;
            while(beg <= end)
            {
                mid = beg + end >> 1;
                b = range_min(mintree, i + 1, mid + 1, n);
                if(b == a)
                {
                    c = range_max(maxtree, mid + 1, n, n);
                    if(c == a)
                    {
                        cout << "YES\n";
                        cout << i + 1 << ' ' << mid - i << ' ' << n - mid - 1 << '\n';
                        goto end;
                    }
                    else if(c < a)
                        end = mid - 1;
                    else
                        beg = mid + 1;
                }
                else if( b < a)
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
        }
        end:
        if(i == n)    cout << "NO\n";
    }
}