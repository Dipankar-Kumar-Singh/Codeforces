#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int n {};



void solve()
{
    n = 0 ; cin >> n ;

    vector<int> v(n) ;

    int ans = -1 ;
    map<int,int> mp ;

    for(int i = 0 ; i  < n ; i++)
    {
        int x ; cin >> x ;

        if(mp[x])
        {
            ans = max(ans , mp[x] + (n - i - 1)) ;
        }

        mp[x] = i + 1 ;
    }

   

    cout << ans << "\n" ;
    return ;
}

signed main()
{
    FAST 
    t_case
    {   
        n = 0 ;   
        solve( ) ;                                                                                         
    }
}

