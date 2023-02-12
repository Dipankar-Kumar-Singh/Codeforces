#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n , k ; cin  >> n >> k ;

    vector< bitset<31> > v(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ;
        v[i] =  bitset<31>(x) ;
    }

    vector<int> req(31,0) ;
    auto ans = bitset<31>(0) ;

    for(int BIT = 30 ; BIT >= 0 ; BIT--)
    {
        for(int i = 0 ; i < n ; i++)
        {
            req[BIT]  += (v[i][BIT]==0) ;
        }

        if(req[BIT]<=k)
        {
            ans[BIT] = 1 ;
            k-= req[BIT] ;
        }
    }

    

    cout << ans.to_ullong() << nl ;




}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

