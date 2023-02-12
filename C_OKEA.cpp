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

        int n , k ; cin >> n >> k ;

        int odd = ceil((n*k*1.0)/2) ;
        int even = ( n*k) - odd ;


        if(odd%k!=0)
        {
            cout << "NO\n" ;
            continue ;
        }

        int o = 1 , e = 2 ; 

        cout << "YES\n" ;

        for(int row = 0 ; row < n ; row++)
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(odd>0)
                {
                    cout << o << " " ;
                    o+=2 ;
                    odd-- ;
                }

                else
                {   
                    cout << e << " " ; 
                    e+=2 ;
                }

               
                
            }

            cout << "\n" ;
        }
        


        
        
                                  
                                        
                                       
    }
}

