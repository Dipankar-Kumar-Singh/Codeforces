#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

bool solve(int a , int b , int k)
{   

    while (a>0 and b>0)
    {   
        if(k==a or k==b) return 1 ;
        if(a>b) swap(a,b) ;

        int toned_down  = b%a ;

        if(b%a==0)
            if(k<=b and k>=a)
                if( (k -a)%a == 0) return 1 ;

        if(abs(a - toned_down) % k == 0) return 1 ;

        b = toned_down ;
    }
    
    return 0 ;
}

signed main()
{
    FAST 
    t_case
    {
        int x {} , y {} ; cin >> x >> y  ;

        int k ; cin >> k ;

        if(solve(x,y, k))
        {
            cout << "YES\n" ;
           
        }
        else 
        {
            cout << "NO\n" ; 
        }
                                                  
    }
}

