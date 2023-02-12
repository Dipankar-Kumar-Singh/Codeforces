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
    
    int n ; cin >> n ;
    int q ; cin >> q ;
    int odd_ct = 0 , even_ct = 0 ;

    int sum  = 0 ;
    vector<int> v(n);
    int even_sum = 0 , odd_sum = 0;
    for (auto &x : v)
    {
        cin >> x;
        sum += x ;
        if(x&1) odd_ct++ , odd_sum += x ;
        else even_ct++ , even_sum += x;
    }


    int odd = 0 , even = 0 ; 

    while(q--)
    {
        int t , x ; cin >> t >> x ; 
        if(t==0)
        {
            if(x%2==0)
            {
                // even + even == even ;
                even_ct = even_ct ;
                even_sum += even_ct*x ;
            }
            else 
            {
                // e + o ==> o
                //e ven += x ;  

                odd_sum += even_sum + even_ct*x ;
                odd_ct = odd_ct  +  even_ct ;
                
                even_ct = 0 ;
                even_sum = 0 ;

                // odd = odd + even ;
                
            }
            
        }
        else if(t==1)
        {
            if(x%2==0)
            {
                // Odd + even ===> odd ..
                odd_sum += odd_ct*x ;
            }
            else 
            {
                // odd + odd ==> even ...
                even_sum += odd_sum + odd_ct*x  ;
                even_ct = even_ct + odd_ct ;

                odd_ct = 0 ;
                odd_sum = 0 ;
            }
        }
        cout << odd_sum + even_sum << nl  ;
    }




}

signed main(){  FAST    TestCases    solve() ; }