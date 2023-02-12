#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int const N  = 1e9 ;
int test = 0 ;


void solve()
{
    int n ; cin >> n ;
    char c ; cin >> c ;
    string s; cin >> s ;

    vector<int> v(n+1,INF) ;
    vector<int> loc ;
    for(int i = n-1 ; i >=0 ; i--)
    {
        if (s[i] == 'g')
            v[i] = i;
        else
            v[i] = v[i + 1];

        if(s[i]==c) loc.push_back(i) ;
    }

    vector<int> ans(n+1) ;

    for(int i = 0 ; i < n ; i++)
    {
        ans[i] = v[i] - i ;
    } 

    for(int i = n - 1 , move =  0; i >=0 ; i--)
    {
        move++ ;
        if(ans[i]  > N)
        {
            ans[i] = ans[0] + move ; 
        }
        else break ;
    }

    int mx = 0 ; 
    for(auto i : loc) mx = max(mx,ans[i]);

    cout << mx << nl ;

    

}

signed main(){  FAST    TestCases    solve() ; }