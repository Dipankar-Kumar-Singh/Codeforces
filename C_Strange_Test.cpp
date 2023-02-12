#include <bits/stdc++.h>
using namespace std;
#include "C:\Users\dipan\OneDrive\ProCode\CP\debugging.h"


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
        int a , b ; cin >> a >> b ; int ans = b - a  ;

        for(int i = a ; i <= b ; i++)
        {
           ans =  min(ans , min(((i|b) - b)+1, abs(b-i)) + (i-a));
        }

        for(int i = b ; i <= 2*b ; i++)
        {
           ans =  min(ans,min(((a|i) - i)+1, abs(i-a)) + (i-b))  ;
        }
        
        cout << ans << nl ;                                                   
    }
}

