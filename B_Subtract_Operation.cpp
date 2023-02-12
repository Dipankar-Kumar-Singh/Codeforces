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
    int k ; cin >> k ;
    vector<int> v(n) ;

    int sm  = 0  ;
    for(int i = 0 ; i < n ; i++ ) cin >> v[i] ;

    map<int,int> fr ;

    for(auto &x : v) fr[x]++ ;

    for(auto &x : v)
    {
        if(fr[x+k])
        {
            cout << "YES\n" ;
            return ;
        }
    }

    cout << "NO\n" ;
 
    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

