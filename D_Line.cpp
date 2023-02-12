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
    int n;  cin >> n;  string line;  cin >> line;    
    vector<int> curr(n), best(n);

    int ans = 0 ;
    vector<int> deltas ;

    for (int i = 0; i < n; i++)
    {
        best[i] = max(i, n - i - 1);
        curr[i] = ((line[i] == 'L') ? i : n - i - 1);

        ans += curr[i] ;
        int delta = best[i] - curr[i] ;
        deltas.push_back(delta) ;
    }

    sort(all(deltas),greater<>()) ;

    for(int i = 0 ; i < n; i++)
    {
        ans += deltas[i] ;
        cout << ans <<  " " ;
    }

    cout << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



