#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e18 
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


signed main()
{
    FAST 
    t_case
    {
        
        int n ; cin >> n ;
        vector < int> v (n) ;
        for(int & i : v) cin>> i ;

        vector<int> v2 = v ;
        sort(all(v2)) ;

        if(v2==v)
        {
            cout << "NO\n" ;
        }

        else cout << "YES\n" ; 
                                                             
                                       
    }
}

