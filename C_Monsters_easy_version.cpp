#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

#include"/home/dk/Code/debug/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;
    sort(all(v)) ;

    dbg(v) ;

    int curr = 1 ;

    int spellOne = 0 ;

    for(int i = 0 ; i < n; i++)
    {
        if(v[i] <= curr)
        {
            continue;
        }

        else if(v[i] > curr)
        {
              curr++ ;
              if(v[i] != curr)
              {
                  spellOne += abs(curr - v[i]);
              }
        }
    }

    cout << spellOne << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
