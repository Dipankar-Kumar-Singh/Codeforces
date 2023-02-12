#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   
    int n ; cin >> n;

    int odda = 0  , evena = 0 ;
    int oddb = 0 , evenb = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ;
        if(i&1)
        {
            if(x&1)odda++ ;
            else evena++ ;
        }

        else
        {
            if(x&1) oddb++ ;
            else evenb++ ;
        }
    } 

    if((odda and evena) or (oddb and evenb))
    {
        cout << "NO\n"; 
    }
    else cout << "YES\n" ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

