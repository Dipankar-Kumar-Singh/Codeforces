#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e6 + 10 ;
vector<bool> p(N,1) ;

void seive(){
    auto &prime = p ;
    prime[0] = prime[1] = 0 ;
    for(int i = 2 ; i < N ; i++ )
    {
        if(prime[i] == 0) 
            continue ;
        for(int j = i*2 ; j < N ; j+=i)     
            prime[j] = 0 ; 
    }
}

signed main()
{
    FAST 
    seive() ;
    t_case
    {   
        int n , e ; cin >> n >> e ;
        vector<int> v(n,0)  ; for(int &x : v) cin >> x ;

        int ans = 0 ;

        for(int ii = 0 ; ii < n ; ii++){
            if(   p[ v[ii] ]   )
            {
               int a = 0 , b = 0 ;

               int i = ii - e , j = ii + e ;

               while (i>=0 and v[i]==1)
               {
                   a++ ; i-=e ;
               }
               
               while (j<n and v[j]==1)
               {
                   b++ ; j+=e ;
               }

               ans += (a+1)*(b+1)*1LL - 1LL ;
                      
            }
        }

        cout << ans << "\n" ;                                            
    }
}

