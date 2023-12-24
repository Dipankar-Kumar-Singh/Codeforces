#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int b, c , h ; 
    cin >> b >> c >> h ; 

    if(c + h >= b - 1){
        int layer = b - 1 + b ;   
        cout << layer << nl ;     
    } else {
        int layer = (h + c) + (h + c + 1) ;
    
        cout << layer << nl ;
    }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
