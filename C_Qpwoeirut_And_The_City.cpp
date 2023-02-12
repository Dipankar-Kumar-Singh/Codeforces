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
    int n;  cin >> n;
    vector<int> v(n);  for (auto &x : v) cin >> x;

    vector<int> cost(n+1);
    for (int i = 1 ; i < n - 1 ; i++)
    {
        cost[i] = max(0LL, max(v[i - 1], v[i + 1]) - v[i] + 1 );
    }

    int sum = 0  ;
    for(int i = 1 ; i < n - 1 ; i+=2) sum += cost[i] ;

    if(n&1){cout << sum << nl ; return; }

    int best = sum ;

    for (int i = n - 2 ; i > 0; i -= 2)
    {
        sum -= cost[i-1] ;
        sum += cost[i] ;
        best = min(best,sum);
    }

    cout << best << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



