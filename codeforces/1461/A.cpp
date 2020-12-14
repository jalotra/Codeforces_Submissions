/**
  Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
*/

#include <bits/stdc++.h>
using namespace std;


void test_case(){

    int n, k;
    cin >> n >> k;
    string s = "";
    int q, r;
    q = n/3;
    r = n%3;
    while(q--){
        s += "abc";
    }
    if(r == 2){
        s += "ab";
    }else if(r == 1){
        s += "a";
    }
    cout << s << endl;



}

int main()
{
    // Write your solution here

    int t;
    cin >> t;
    while(t--)test_case();


    return 0;
}