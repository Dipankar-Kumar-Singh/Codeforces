#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 


signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        int f = __bit_floor(n-1) ;
        
        int num = 1 ;
        for(num = 1; num < f ; num++ ) cout << num << " " ;
        cout << 0 << " " ;
        for( ; num < n ; num++ ) cout << num << " " ;
        cout << nl ;                              
                                       
    }
}

