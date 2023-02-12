#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ; cin >> n ;
    vector<int> v(n) ;

    if((n&1) == 1 )
    {
        if(n==3)
        {
            cout << "NO" << nl;
            return;
        }

        int mid = n/2 ;


        for(int i = 0 ; i < n ; i++)
        {
            if((i&1) == 1 )
            {
                v[i] = -(mid)  ;
            }

            else v[i] = mid - 1; 
        }

        cout << "YES\n" ;
        for(auto x : v) cout << x << " " ;
        cout << nl  ;
    }

    else 
    {
        for(int i = 0 ; i < n ; i++)
        {
            if((i&1) == 1 )
            {
                v[i] =  -1 ;
            }

            else v[i] = 1 ; 
        }

        cout << "YES\n" ;
        for(auto x : v) cout << x << " " ;
        cout << nl  ;

    }


    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
