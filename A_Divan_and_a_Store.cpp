#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        int  n, l, r, k ; 
        cin >> n >> l >> r >> k ;

        vector<int> v(n,0) ;

        for(auto &x:v) cin >> x ; 

        int ans = 0 ;

        sort(all(v)) ;

        vector<int> vv ; 
        
        for(auto x:v){ if(!(x>r and x<l)) vv.push_back(x);}

        for(auto x : vv)
        { 
            if(x > r) continue ; 
            else if(x < l) continue ; 

            if( k-x >= 0){ k-=x ; ans++ ; }  
            // else if(k-x < 0) break ;
        }
        cout << ans << "\n" ; 
                                                              
    }
}

