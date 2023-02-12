#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int ca = 0 , cb = 0  ;


bool isPossible(int n , int x , int y )
{
    if(n < ca + cb) return 0 ;
    
    int factorX  = n/x ;
    int factorY = n/y ;

    int common_fact = n/gcd(x,y) ;

    common_fact  = n / x / y ;

    int op1 = n - factorX ;
    int op2 = n - factorY ;

    int free = n - factorX - factorY + common_fact ;

    bool possible = op1 >= ca and op2>=cb and (n - common_fact) >= ca + cb ;

    return possible ;
}

signed main()
{
    FAST 
    int a , b , x ,y ; 
    cin >> a >> b >> x >> y ;

    ca = a , cb  = b ;


    int l = 0 , r = INF-10 ;

    int ans = 0 ; 

    while (r-l>1)
    {
        int m = midpoint(l,r) ;
        if(isPossible(m,x,y))
        {
            r = m ; 
            ans  =  m;
        }
        else l = m ;
    }

    cout << ans ;
}

