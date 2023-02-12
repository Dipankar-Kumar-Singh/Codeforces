#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    int n , h ; 
    cin >> n >> h ;

    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    sort(begin(v),end(v)) ;

    vector<vector<int>> orders = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};

    int ans = 0 ;

    for(auto order : orders )
    {
        int health = h ;
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if(v[i] < health)
            {
                health += v[i++]/2 ;
            }
            else if( j < 3 )
            {
                health *= order[j++] ;
            }
            else break;
        }

        ans = max(ans , i) ;
    }

    cout << ans << "\n" ;
    
}

signed main() { FAST TestCases solve(); }
