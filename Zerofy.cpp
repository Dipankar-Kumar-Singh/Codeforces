#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    int ans = 0 ; 
    vector<int> v(3) ; for(auto &x : v) cin >> x ;

    while (accumulate(all(v), 0LL) > 0)
    {
        sort(all(v)) ;

        if(v[0]==0 and v[1]==0 and v[2]==0 ) 
        {
            cout << "Yes\n" ;
            return ;
        }

        if(v.front()<0)
        {
            cout << "No\n" ;
            return ;
        }

        --v[1] , --v[2] ;

        if(v[0]==0 and v[1]==0 and v[2]==0 ) 
        {
            cout << "Yes\n" ;
            return ;
        }
    }


    cout << "No\n" ;

}

signed main(){  FAST    TestCases    solve() ; }