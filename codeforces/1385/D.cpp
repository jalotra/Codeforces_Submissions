#include <bits/stdc++.h>
using namespace std;

//int solve(const string& s, int start, int end, char c){
    //if(start > end)return 0;
    //if(start == end - 1){
        //return s[start] != c; 
    //}
    //int mid = (start + end)/2;    
    //int first_half = solve(s, mid, end, c+1);
    //first_half += (mid - start) - count(s.begin(), s.begin() + mid, c);
    
    //int second_half = solve(s, start, mid, c+1);
    //second_half += (end - mid) - count(s.begin() + mid, s.end(), c);
    
    //cout << start << " " << end << " " << first_half << " " << second_half << endl;
    
    //return min(first_half, second_half);
//}
int calc(const string &s, char c) {
	if (s.size() == 1) {
		return s[0] != c;
	}
	int mid = s.size() / 2;
	int cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
	int cntr = calc(string(s.begin() + mid, s.end()), c + 1);
	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
	return min(cntl, cntr);
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        
        int n; string s;
        cin >> n >> s;
        
        int ans = calc(s, 'a');
        
        cout << ans << endl;
    }
} 
