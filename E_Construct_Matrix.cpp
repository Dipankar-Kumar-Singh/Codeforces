// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

void solve(int& __case__)
{
    vector<string> names = { 
        "dipankar" , 
        "kumar" ,
        "singh",
    } ;

    dbg(names) ;

    
    vector<pair<int,string>> vv = {{2,"dsf"}} ;

    dbg(vv) ;


    for(auto &n : names) {
        cout << n << " " ; 
    } cout << nl ;


}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}