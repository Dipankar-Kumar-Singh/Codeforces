#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);  for (int i = 0; i < n; i++)    cin >> v[i];

    int sum = 0 ;  
    for (int i = 1; i < n; i++)   sum += abs(v[i] - v[i - 1]);
    
    int dx = 1e18 , dy = 1e18 ;
    for(int i = 1 ; i < n; i++)
    {
        int oldcost = abs(v[i] - v[i-1]) ;
        int newcost = abs(v[i]-1) + abs(v[i-1]-1) ;
        int change  = newcost - oldcost ;
        if(change < 0 ) change = 0 ;
        int res  = max(change,0LL) ;
        dx = min(dx, res) ;

    }

    for(int i = 1 ; i < n; i++)
    {
        int oldcost = abs(v[i] - v[i-1]) ;
        int newcost = abs(v[i]-k) + abs(v[i-1]-k) ;
        int change  = newcost - oldcost ;
        if(change < 0 ) change = 0 ;
        int res  = max(change,0LL) ;
        dy = min(dy, res) ;
    }

    dx = min({abs(v.front() - 1) , abs(v.back()-1) , dx}) ;
    dy = min({abs(v.front() - k) , abs(v.back()-k) , dy}) ;

    int mn = *min_element(all(v)), mx = *max_element(all(v));

    if(1==mn) dx = 0 ;
    if(k<=mx) dy = 0 ;

    sum += (dx+dy) ;

    cout << sum << nl ;
    return ;
}

signed main(){   FAST      TestCases      solve() ;  }

