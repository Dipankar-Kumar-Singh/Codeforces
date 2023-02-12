#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


void put(bool x)
{
    cout << (   x   ?    "YES"  :   " NO"   ) ;
    cout << "\n" ;
}


void solve()
{
    int n ; cin >> n ; 
    vector<int> b(n) ;
    vector<int> a(n) ;

    int sumB {} ;

    for(int &x : b ) 
    {
        cin >> x  ;
        sumB  +=  x  ;
    }

    int d = ( n*(n+1) ) / 2 ;

    if(sumB%d != 0) 
    {   
        put(0) ; 
        return ;
    }

    int sum = sumB / d ;

    for(int i = 0  ; i < n ; i++)
    {
        int rr = sum -(b[(i+1) % n] -  b[i]  ) ;
        if( rr % n !=  0  or rr <= 0  )
        { 
            put(0) ; 
            return ;
        } 

        a[(i+1)%n] = rr/n ; 
    }


    put(1) ;

    for(auto &x : a) cout << x << " " ;

    cout << "\n" ;


}

signed main()
{
    FAST 
    t_case
    {
       solve() ;                     
    }
}

