#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n , m ; cin >> n >> m ;

    vector<string> v(n) ; 
    for(auto &s : v) cin >> s;

    int d = LONG_LONG_MAX ;

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ;  j < i ; j++)
        {
            string s = v[i] ;
            string t = v[j] ;

            int dif = 0 ;

            for(int k = 0 ; k < m ; k++)
            {
                char c1 = s[k] ;
                char c2 = t[k] ;

                if(c1<c2) swap(c1,c2) ;

                dif += (c1-c2) ;
            } 

            d = min(d,dif) ;
        }
    }

    cout << d << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

