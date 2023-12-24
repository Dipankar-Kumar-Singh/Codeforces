// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    string s; cin >> s ; 
    char c = s[0] ; 
    int num = s[1] - '0' ; 

    for(int i = 1 ; i <= 8 ; i++){
        if(i == num ) continue; 
        cout << c << i << nl ; 
    } 

    for(char cc = 'a' ; cc <= 'h' ; cc++){
        if(cc == c) continue ; 
        cout << cc << num << nl ;
    }
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}