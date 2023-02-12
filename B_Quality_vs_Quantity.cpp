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
    vector<int> v(n) ; for(auto &x : v ) cin >> x ;

    sort(all(v)) ;

    int s1 = v[0] + v[1] ; 
    int s2 = v.back() ;

    int p1 = 2 ;
    int p2 = n-1-1 ;


    if(s1<s2)
    {
        cout << "YES\n" ;
        return ;
    }

    while (p1<p2)
    {
        s1 += v[p1] ;
        s2 += v[p2] ;

        if(s1<s2)
        {
            cout << "YES\n" ;
            return ;
        }
        p1++ ; p2-- ;
    }
    

    if(s1<s2)
    {
        cout << "YES\n" ;
        return ;
    }

    else cout << "NO\n"  ;

    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

