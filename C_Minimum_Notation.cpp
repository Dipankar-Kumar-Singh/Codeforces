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
    string s ; cin >> s ;
    int n = s.size() ;

    vector<pair<int,int>> v(n) ;
    vector<int> vec(n) ;
    for(int i = 0 ; i < n; i++)
    {
        v[i] = {s[i] -'0',i} ;
        vec[i] = s[i] - '0' ;
    }

    
    sort(all(v)) ;
    int currmax = -1 ;


    vector<int> mn (n+1,INF) ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        mn[i] = min(mn[i + 1], vec[i]);
    }


    for(int i = 0; i < n ; i++)
    {
        if(vec[i] == mn[i])
        {
            continue ;
        }
        else 
        {
            vec[i]++ ;
            vec[i] = min(vec[i],9ll) ;
        }
    }

    sort(all(vec)) ;
    for(auto x : vec) cout << x ; cout << nl ;


}

signed main(){  FAST    TestCases    solve() ; }