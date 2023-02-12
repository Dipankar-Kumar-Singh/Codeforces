#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


bool isPossible_New(int h , vector<int> v )
{
    auto org = v ;
    int n = v.size() ;
    vector<int> t = {1 , 2 , 10 , 100 } ;

    for(int i = n -1 ; i - 2 >= 0 ; i--)
    {
        int give = 0 ;

        if(v[i] < h) return 0 ;

        give = min((v[i]-h)/3 , org[i]/3) ;

        v[i-1] += give ;
        v[i-2] += 2*give ;
        v[i] -= give*3 ;
    }

    return ( *min_element(all(v)) >= h ) ;
}

signed main()
{
    FAST 
    t_case
    {
        
        int n ;
        cin >> n ;
        
        vector<int> v(n) ; 
        for(int &x : v) cin >> x ;

        int l = -1 , r = *max_element(all(v))  + 100 ;
        int ans = 0 ;                     

        while(r-l>1)
        {
            int m = l + (r-l)/2 ;
            if(isPossible_New(m,v))
            {
                ans = max(ans,m) ;
                l = m ;
            }
            else r = m ;
        } 
    
        cout << ans << endl;      

    }
}

