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
    int n ,  m , t ; 
    cin >> n >> m >> t ;
    vector<int> v(n-1) ;
    for(auto &x : v) cin >> x ;

    map<int,int> bonus ;

    for(int i = 0 ; i < m ; i++)
    {
        int room , b ; 
        cin >> room >> b ;
        bonus[room] = b ;
    }

    for(int r = 1 ; r < n ; r++)
    {
        int b = bonus[r] ;
        t += b ;

        int req = v[r-1] ;

        if(t <= req)
        {
            cout << "No" << nl ;
            return ;
        }
        t -= req ;
    }

    cout << "Yes\n" ;


}

signed main(){  FAST     solve() ; }