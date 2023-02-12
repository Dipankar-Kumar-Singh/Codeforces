#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


void solve(int& __case__)
{
    int n ; cin>>n ;
    int twob = 0 ;
    vector<int> v(n) ;

    for(auto &x : v )
    {
        cin >> x;
        twob += (x == 2) ;
    }

    if(twob == 0)
    {
        cout << 1 << nl ;
        return ;
    }

    if((twob & 1 )== 1)
    {
        cout << -1 << nl ;
        return ;
    }

    int twoa = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        twoa += (v[i] == 2) ;
        twob -= (v[i] == 2) ;

        if(twoa == twob)
        {
            cout << i + 1 << nl ;
            return ;
        }
    }

    cerr << nl ;

    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
