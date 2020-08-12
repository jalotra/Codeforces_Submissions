#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        
        int odds_first = r%2 + g%2 + b%2;
        int odds_second = w%2;
        if(odds_first + odds_second <= 1){
            cout << "Yes" << endl;
            continue;
        }
        
        if(r > 0 && g > 0 && b > 0){
            r -= 1;
            g -= 1;
            b -= 1;
            odds_first = 3 - odds_first;
            odds_second = 1 - odds_second;
             if(odds_first + odds_second <= 1){
                cout << "Yes" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
}
