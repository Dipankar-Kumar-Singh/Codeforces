// Problem: Weekly Tasks
// Contest: CodeChef - CODUO 2022 
// URL: https://www.codechef.com/CDDU2022/problems/WTASK
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
    
    vector<int> v(7) ; for(auto &x : v) cin >> x ;

    vector<int> prefix(8,0) ;

    for(int i = 1 ; i <= 8 ; i++) prefix[i] = prefix[i-1] + v[i-1] ;

    int ans =  n/prefix[7] ;
    int rem = n%prefix[7] ;

    if(rem==0)
    {
        cout << 7 << nl ;
        return ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        rem -= v[i] ;
        if(rem<=0)
        {
            cout << (i+1) << nl;
            return ;
        }
    }

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

