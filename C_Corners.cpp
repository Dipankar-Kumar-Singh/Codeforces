#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


int dedice(int a , int b , int c , int d)
{
    // case 1 
    int s1 = a + b + d ;
    int s2 = c ;

    if(s1)   s1 = 1;
    if (s2)   s2 = 1;

    int r1 = s2 + s1 ;

    if(s1 and s2) return 2 ;

    // case 2

    s1 = a + b + c ;
    s2 = d ; 

    if(s1)   s1 = 1;
    if(s2)   s2 = 1;

    int r2 = s1 + s2 ;

    if(s1 and s2) return 2 ;

    return max(r1,r2) ;
}

void solve()
{
    int n;    cin >> n;
    int m;    cin >> m;

    vector<string> v(n) ;
    for(auto &s : v) cin >> s ;
    int ans = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if (!((i + 1 < n) and (j + 1 < m)))  continue;

            int a = (v[i][j]     - '0');
            int b = (v[i][j + 1] - '0');
            int c = (v[i + 1][j] - '0');
            int d = (v[i+1][j+1] - '0');

            // cerr << " i = " << i << " j =  " << j << " " ;

            int sum = (a + b + c + d) ;

            if(sum > 1) ans += 2 ;
            else if(sum == 1) ans += 1 ;

            // cerr << sum << nl ;

            // ans += dedice(a,b,c,d) ;

            // for(auto x : v) 
            // {
            //     cout << x << nl ; 
            // }
            // cout << nl ;

            v[i][j] = '0';
            v[i][j + 1] = '0';
            v[i + 1][j] = '0';
            v[i + 1][j + 1] = '0';
            
        } 
    }

    cout << ans << nl ;
    
}
signed main(){   FAST      TestCases      solve() ;  }



