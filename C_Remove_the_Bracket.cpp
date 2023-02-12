#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

#include"/home/dk/Code/debug/debugging.h"

void solve(int& __case__)
{
    int n , s ; 
    cin >> n >> s ;

    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    vector<pair<int,int>> v2 (n + 2);

    for(int i = 1 ; i + 1 < n ; i++)
    {
        int pechey = 1 , agey = 1 ;

        pechey = (i == 1 ? v[i - 1] : v[i - 1] / 2);
        agey = (i + 1 == n - 1 ? v[i + 1] : v[i + 1] / 2);

        int a = 1;
        int b = 2 ;
        
        if(s <= 0 or s >= v[i] + 1)
        {
            // no problem .. 
            a = 0 ; 
            b = v[i] ;
        }

        else 
        {
            a = s ; 
            b = v[i] - a ;
        }

        // dbg(a,b) ;
        int A = 1 , B = 1 ;

        // if(agey > pechey) 
        //     A = max(a,b) , B = min(a,b) ;
        // else 
            A = min(a,b) , B = max(a,b) ;

        v2[i] = {A, B};

        // cerr << " A " << A << "  B " << B << nl ;
    }

    int ans = 0 ;

    for(int i = 1 ; i + 1 < n ; i++)
    {
        if(i == 1) 
        {
            ans += v.front() * v2.front().first ;
        }

        else if( i == n - 2)
        {
            ans += v.back() * v2.back().second ;
        }

        else 
        {
            ans += v2[i].second * v2[i + 1].first ;
        }   
    }


    cout << ans << nl ;

    // cerr << nl ;


}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
