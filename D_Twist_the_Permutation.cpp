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
    for(auto  &x : v) cin >> x ;

    vector<int> req(n) ;
    iota(all(req),1) ;

    vector<int> ans(n+1) ; 

    int x = n ;
    int opration = n ;


    while (opration--)
    {
        int loc = 0 ;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == x)
            {
                loc = i ; 
                break; 
            }
        }

        if(loc+1 == x) ans[x] = 0 ; 
        else ans[x] = loc + 1 ;

        x-- ;
        rotate(v.begin(),v.begin()+loc+1,v.begin()+x+1) ;

        // CAN BE DONE USING C++ STL RORATE .... New learning .. 

        // vector<int> temp ;
        // vector<int> v1 , v2 , v3 ;

        // for(int i = loc+1 ; i < x ; i++ ) v1.push_back(v[i]) ;
        // for(int i = 0 ; i <= loc ; i++) v2.push_back(v[i]) ;
        // for(int i = x ; i < n ; i++) v3.push_back(v[i]) ;

        // for(auto &e : v1) temp.push_back(e) ;
        // for(auto &e : v2) temp.push_back(e) ;
        // for(auto &e : v3) temp.push_back(e) ;

        // v=temp ;
    }

    if(v!=req) {  cout << -1 << nl ; return ;  }

    for(int i = 1 ; i <= n ; i++)  cout << ans[i] << " " ;    cout << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  
}

