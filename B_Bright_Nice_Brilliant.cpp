#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int const INF  = 1e18 ;
int test = 0 ;



void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<vector<int>> v(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        v[i] = vector<int>(i+1) ;
        v[i].front() = v[i].back() = 1 ;
        for(auto x : v[i]) cout << x <<  " " ; cout << nl ;
    }
    
    

}

signed main(){  FAST    TestCases    solve() ; }