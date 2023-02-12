#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        int n , k ; cin >> n >> k ;

        vector<int> v (n) ; for(auto &x:v) cin >> x ;

        sort(all(v)) ; reverse(all(v)) ;

        vector<int> v1 (v.begin(),v.begin()+k) ; 
        vector<int> v2 (v.begin()+k , v.end()) ;


        // for(auto i : v1) cout << i << " " ;
        // cout << "\n" ;
        // for(auto i : v2) cout << i << " " ;

        // cerr << boolalpha << (v.size() == (v1.size() + v2.size())) << "\n";
        
        int ans = 0 ;

        for(int i = 0 ; i < v1.size();i++)
        {
            int big = v1[i] , small = v2[i] ;
            ans += small/big ;
        }

        ans += accumulate(v2.begin()+k,v2.end(),0) ;

        cout << ans << "\n" ;

        // cout << "\n" ;



        
                                  
                                        
                                       
    }
}

