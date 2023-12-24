#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    string s ; cin >> s ;
    string a , b ;

    for(int i = 0 ; i + 1 < s.size() ; i++){
        a += s[i] ;
        b = s.substr(i+1) ;

        if(stoi(a) < stoi(b) and (b[0] != '0')){
            cout << stoi(a) << " " << stoi(b) << nl ;
            return ;
        }
    }

    cout << -1 << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
