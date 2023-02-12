#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

bool isPossible(vector<int> &v  , int &h , int &k){
    int sum  = 0 ;
    for(int i = 0 ; i < v.size() - 1 ; i++){
        int dam  = min( (v[i+1] - v[i]) , k ) ;
        sum += dam ;
        if(sum >= h) break ;
    }
    return sum >= h ;
}

signed main()
{
    FAST 
    t_case
    {
        
        int n , h ; cin >> n >> h ;

        vector<int> v(n,0) ; for(auto &x : v) cin >> x ;
        v.push_back(INF) ;
 
        int l = 0 , r  = INF ;
        int ans = 0 ;

        while (r-l>1)
        {
            int m =  l + (r-l)/2 ;
           
            if(isPossible(v,h,m)) 
            {
                ans = m ;
                r = m  ; 
            }

            else {
                l = m ;
            }
        }

        cout << ans << "\n" ;
        
                                                    
                                       
    }
}

