#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n ; cin >> n ;
   vector<int> v(n) ;
   for(auto &x : v) cin >> x ;

   vector<int> prifix(n+1,0) ;
   set<pair<int,int>> s;

    for(int i = 1 ; i <n ; i++)
    {
        prifix[i] = prifix[i-1] + v[i-1] ;
        s.insert({prifix[i],-i}) ;
    }

   int sm = 0 ;
   int best = 0 ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        int lenb = n - i ;
        sm += v[i] ;
        s.erase({prifix[i+1],-(i+1)}) ;
        auto f = s.lower_bound({sm,-LLONG_MAX}) ;
      
        if(f!=s.end())
        {
            auto [wt,lena] = *f ;
            lena = -lena ;
            if(wt==sm)
            {
                best = max(best,(lena+lenb)) ;
            }
        }
    }

    cout << best << nl;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

