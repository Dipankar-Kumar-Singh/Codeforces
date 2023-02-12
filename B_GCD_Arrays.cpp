#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


int noOfodd(int start , int end )
{
    int odd ;
    if(start%2 ==   0 )
    {
        int x  = floor((end - start  +  1 )/(2.0))  ;
        odd = x ;
    }

    else {
        int x  = ceil((end - start  +  1 )/(2.0))  ;
        odd = x ;
    }

    return odd ;
}

signed main()
{
    FAST 
    t_case
    {
        
        int a , b , k ; 
        cin >> a >> b >> k ;

        int dif = b - a ;
        if(dif == 0)
        {
            if(a == 1 ){ cout << "NO\n" ; continue ;}
            else cout << "YES\n" ; continue ;
        }
        int odd = noOfodd(a,b) ;

        cout << ( k >=  odd ?  "YES\n" : "NO\n") ;
                                                              
    }
}

