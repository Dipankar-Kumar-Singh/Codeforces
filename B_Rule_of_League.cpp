#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;
int const INF  = 1e18 ;
int test = 0 ;

void solve()
{
    int n , x , y ; cin >> n >> x >> y ;
    if(x > y) swap(x , y ) ; 
    vector<int> num(n+100) ; 

    for(int i = n , j = 1 ; i > 0 ; i--) num[i] = j++ ;
    num[1] = num[2] ;

    if(x == 0 and y == 0) 
    {
        cout << -1 << nl ;
        return ;
    }

    if(x == 1)
    {
        cout << -1 << nl ;
        return ;
        int match = n - 1 ;
        if((n - 1)%y==0)
        {
            int i = 2 ; 
            while(i < n){
                for(int j = 0 ; j < y ; j++ ) cout << i << " " ; 
                i += y;  
            }
            cout << n << nl ;
            return ;
        }
        else cout << - 1  << nl ;
        return ;
    }

    else if(x == 0)
    {
        int winner = 0  ;
        for (int i = 2 ; i <= n; i++){
            if (y == num[i]){
                winner = i;
                break;
            }
        }

        if((winner - 2) % y == 0 )
        {
            int i = 2 ; 
            while(i < winner){
                for(int j = 0 ; j < y ; j++ ) cout << i << " " ; 
                i += y;  
            }

            for(int i = winner ; i <= n ; i++ ) cout << winner << " " ; cout << nl ;
        }

        else 
        {
            cout << - 1 << nl ;
            return ;
        }
    }
    else 
    {
        cout << - 1 << nl ;
    }
}

signed main(){  FAST    TestCases    solve() ; }