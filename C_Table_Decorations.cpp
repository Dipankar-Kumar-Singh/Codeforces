#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

int a {}, b{}, c{}  ;
int com = 0 ;

bool isPossible(int len)
{
    int sum = 0 ;
    int x = 2*len ;
    sum += min(x , a) ;
    sum += min(x , b) ;
    sum += min(x , c ) ;

    int req_len = 3 * len ;
    return  ( sum >=req_len ) ; 
}


signed main()
{
    FAST 
    cin >>  a >> b >> c ;

    vector<int> v = {a,b,c } ;

    cout <<   min((a + b + c )/3 , v[0] + v[1] ) ; 
    return 0 ;

    int l = -1 , r = 1e10 ; 

    int ans = 0 ;

    while (r-l >1)
    {
        int m = midpoint(l,r) ;

        if(isPossible(m))
            ans = max(ans,m) ,     l = m ;
    
        else         
            r = m ;
        
    }

    cout << ans << nl ;


}

