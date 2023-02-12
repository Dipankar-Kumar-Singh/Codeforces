#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;
map<int,vector<int>> m; 

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    vector<int> last(1100,-1) ;

    for(int i = 0 ; i < n; i++)
    {
        last[v[i]] = i ;
    }

    int ans = -1 ;

    int found = 0 ;

    for(int i = 0 ; i < n; i++)
    {
        for(auto coPr : m[v[i]])
        {   
            int j = last[coPr] ;
            if(j != -1)
            {
                ans = max(ans, i + 1 + j + 1);
                found = 1 ;
            }
        }
    }

    cout << ans << nl ;

}

signed main(){  
    FAST   

    for(int i = 1 ; i <= 1000 ; i++)
    {
        for(int j = 1 ; j <= 1000 ; j++)
        {
            if(gcd(i,j)==1) m[i].push_back(j) ;
        }
    } 
    
    TestCases    solve() ; 

}