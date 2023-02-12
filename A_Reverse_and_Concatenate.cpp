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
        int k ; cin >> k ;
        string s ; cin >> s ;
        string srev = s ;
        reverse(all(srev)) ;
        
        if(k==0)
        {
            cout << 1  << nl;
            continue ; 
        }

        else 
        {
            if(srev == s)
            {
                cout << 1 << "\n" ;
                
            }

            else cout << 2 << "\n" ;

        }
                                  
                                        
                                       
    }
}

