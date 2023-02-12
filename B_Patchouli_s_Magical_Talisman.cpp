#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{

    int n; cin >> n;
    vector<int> v(n) ;
    int odd = 0 , even = 0 ;
    for(auto &x : v) 
    {
        cin >> x ;
        (x&1 ? odd : even )++ ; 
    }

    if(odd)
    {
        cout << even << nl; 
    }

    else
    {
        even-- ;

        int moves = LONG_LONG_MAX ;
        sort(all(v)) ;

        for(int i = 0 ;  i < n ; i++)
        {
            int x =  0 ;
            while ((v[i]&1)!=1)
            {
                v[i]/=2 ;
                x++ ;
            }
            moves = min(moves,x) ;
        }

        cout << even + moves << nl;
    }


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

